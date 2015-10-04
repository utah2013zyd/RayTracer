#include "objects.h"
#include <iostream>
Sphere theSphere;
Plane thePlane;
#define BIAS 0.001
#define EPSILON 0.00000001

bool Box::IntersectRay(const Ray &r, float t_max) const
{
	//x normal plane
	if (std::fabs(r.dir.x) < EPSILON && (r.p.x <= pmin.x || r.p.x >= pmax.x))
		return false;
	// y normal plane
	if (std::fabs(r.dir.y) < EPSILON && (r.p.y <= pmin.y || r.p.y >= pmax.y))
		return false;
	//z normal plane
	if (std::fabs(r.dir.z) < EPSILON && (r.p.z <= pmin.z || r.p.z >= pmax.z))
		return false;
	
	float Tx1 = (pmin.x - r.p.x) / r.dir.x;
	float Tx2 = (pmax.x - r.p.x) / r.dir.x;
	if (Tx1 > Tx2)
	{
		float temp = Tx1;
		Tx1 = Tx2;
		Tx2 = temp;
	}

	float Ty1 = (pmin.y - r.p.y) / r.dir.y;
	float Ty2 = (pmax.y - r.p.y) / r.dir.y;
	if (Ty1 > Ty2)
	{
		float temp = Ty1;
		Ty1 = Ty2;
		Ty2 = temp;
	}

	float Tz1 = (pmin.z - r.p.z) / r.dir.z;
	float Tz2 = (pmax.z - r.p.z) / r.dir.z;
	if (Tz1 > Tz2)
	{
		float temp = Tz1;
		Tz1 = Tz2;
		Tz2 = temp;
	}

	float Tmin = Tx1 > (Ty1 > Tz1 ? Ty1 : Tz1) ? Tx1 : (Ty1 > Tz1 ? Ty1 : Tz1);
	float Tmax = Tx2 < (Ty2 < Tz2 ? Ty2 : Tz2) ? Tx2 : (Ty2 < Tz2 ? Ty2 : Tz2);
	if (Tmin > Tmax)
		return false;
	else
		return true;
}
bool Sphere::IntersectRay( const Ray &ray, HitInfo &hInfo, int hitSide) const
{
	float A = ray.dir.x*ray.dir.x + ray.dir.y*ray.dir.y + ray.dir.z*ray.dir.z;
	float B = 2.0*(ray.dir.x*ray.p.x + ray.dir.y*ray.p.y + ray.dir.z*ray.p.z);
	float C = ray.p.x*ray.p.x + ray.p.y*ray.p.y + ray.p.z*ray.p.z-1;
	float delta = B*B - 4*A*C;
	//printf("delta: %f\n", delta);
	if(delta > 0)
	{
		if (hitSide == HIT_FRONT)
		{
			hInfo.z = (-B - sqrt(delta)) / (2.0*A);
			hInfo.front = true;

		}
		else if (hitSide == HIT_FRONT_AND_BACK)
		{
			if ((-B - sqrt(delta)) / (2.0*A) > BIAS)
			{
				hInfo.z = (-B - sqrt(delta)) / (2.0*A);
				hInfo.front = true;
			}
			else
			{
				hInfo.z = (-B + sqrt(delta)) / (2.0*A);
				hInfo.front = false;
			}
			
		}

		if (hInfo.z > BIAS)
		{
			hInfo.p = ray.p + hInfo.z * ray.dir;
			hInfo.N = ray.p + hInfo.z * ray.dir;
			hInfo.uvw.x = (std::atan2(hInfo.p.y, hInfo.p.x) + M_PI) / (2 * M_PI);
			hInfo.uvw.y = (std::asin(hInfo.p.z) + M_PI_2) / M_PI;
			//std::cout << "u and v: " << hInfo.uvw.x << " " << hInfo.uvw.y << std::endl;
			return true;

		}
		else
		{
			hInfo.z = BIGFLOAT;
			return false;
		}
	}
	else
		return false;
}

bool Plane::IntersectRay(const Ray &ray, HitInfo &hInfo, int hitSide) const
{
	if (std::fabs(ray.dir.Dot(Point3(0, 0, 1))) == 0)
		return false;
	float t = -ray.p.Dot(Point3(0, 0, 1)) / ray.dir.Dot(Point3(0, 0, 1));
	Point3 p = ray.p + t*ray.dir;
	//std::cout << t << " " << p.x << " " << p.y << std::endl;
	if (p.x >= -1 && p.x <= 1 && p.y >= -1 && p.y <= 1 && t > BIAS)
	{
		hInfo.p = p;
		hInfo.N = Point3(0, 0, 1);
		hInfo.z = t;
		hInfo.uvw = Point3((p.x + 1) / 2, (p.y + 1) / 2, 0);
		if (ray.dir.Dot(Point3(0, 0, 1)) < 0)
			hInfo.front = true;
		else
			hInfo.front = false;
		return true;
	}
	else
		return false;
}

bool TriObj::IntersectRay(const Ray &ray, HitInfo &hInfo, int hitSide) const
{
	return TraceBVHNode(ray, hInfo, hitSide, bvh.GetRootNodeID());
}

bool TriObj::IntersectTriangle(const Ray &ray, HitInfo &hInfo, int hitSide, unsigned int faceID) const
{
	cyTriFace cur = F(faceID);
	Point3 E1 = V(cur.v[1]) - V(cur.v[0]);
	Point3 E2 = V(cur.v[2]) - V(cur.v[0]);

	Point3 N = E1.Cross(E2) / E1.Cross(E2).Length();

	if (std::fabs(N.Dot(ray.dir)) == 0)
		return false;

	float t = -(ray.p - V(cur.v[0])).Dot(N) / N.Dot(ray.dir);
	if (t < BIAS)
		return false;

	Point3 p = ray.p + t*ray.dir;
	float A2 = N.Dot(E1.Cross(p - V(cur.v[0])) / 2.0);

	float A = N.Dot(E1.Cross(E2) / 2.0);

	float w2 = A2 / A;
	if (w2 <= -EPSILON || w2 >= 1 + EPSILON )
		return false;

	float A1 = N.Dot((p - V(cur.v[0])).Cross(E2) / 2.0);
	float w1 = A1 / A;
	if (w1 <= -EPSILON || w1 >= 1 + EPSILON)
		return false;

	float w0 = 1 - w1 - w2;
	if (w0 <= -EPSILON || w0 >= 1 + EPSILON)
		return false;

	hInfo.p = p;
	hInfo.z = t;
	hInfo.N = GetNormal(faceID, cyPoint3f(w0, w1, w2));
	hInfo.mtlID = GetMaterialIndex(faceID);
	if (NVT() != 0)
		hInfo.uvw = GetTexCoord(faceID, cyPoint3f(w0, w1, w2));
	if (N.Dot(ray.dir) < 0)
		hInfo.front = true;
	else
		hInfo.front = false;
	return true;
}

bool TriObj::TraceBVHNode(const Ray &ray, HitInfo &hInfo, int hitSide, unsigned int nodeID) const
{
	const float* t_bounds = bvh.GetNodeBounds(nodeID);
	Box t_box(Point3(t_bounds[0], t_bounds[1], t_bounds[2]), Point3(t_bounds[3], t_bounds[4], t_bounds[5]));
	if (!t_box.IntersectRay(ray, 1))
		return false;
	else
	{
		if (!bvh.IsLeafNode(nodeID))
		{
			unsigned int firstIdx, secondIdx;
			bool result1, result2;
			bvh.GetChildNodes(nodeID, firstIdx, secondIdx);
			result1 = TraceBVHNode(ray, hInfo, hitSide, firstIdx);
			result2 = TraceBVHNode(ray, hInfo, hitSide, secondIdx);
			return result1 || result2;
		}
		else
		{
			const unsigned int* list = bvh.GetNodeElements(nodeID);
			HitInfo t_hit;
			bool result = false;
			for (int i = 0; i < bvh.GetNodeElementCount(nodeID); i++)
			{
				if (IntersectTriangle(ray, t_hit, hitSide, list[i]))
				{
					hInfo = hInfo.z < t_hit.z ? hInfo : t_hit;
					result = true;
				}
	
			}
			return result;
		}
	}
}
