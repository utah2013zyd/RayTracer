#include "Tracer.h"
#include "cyMatrix3.h"
#include <stdio.h>
extern Node rootNode;

Tracer::Tracer()
{
}


Tracer::~Tracer()
{
}

bool Tracer::traceRay(const Ray &ray, HitInfo &hInfo, int hitSide)
{
	return recursiveTraceRay(ray, hInfo, &rootNode, hitSide);
}
bool Tracer::recursiveTraceRay(const Ray &ray, HitInfo &hInfo, const Node* node, int hitSide)
{
	bool isHit = false;
	//HitInfo hit;
	const Ray r = node->ToNodeCoords(ray);
	const Object* obj = node->GetObject();
	if (obj != NULL)
	{
		if (obj->GetBoundBox().IntersectRay(r, 1))
		{
			if (obj->IntersectRay(r, hInfo, hitSide))
			{
				isHit = true;
				hInfo.node = node;
				
				//calculate the normal after bumpmapping
				if(node->GetMaterial()->hasBumpNormal(hInfo)) {
					Point3 n = node->GetMaterial()->GetBumpNormal(hInfo);
					//printf("before: %f, %f, %f\n", hInfo.N.x, hInfo.N.y, hInfo.N.z);
					cyMatrix3f TBN;
					TBN.Set(hInfo.T, hInfo.B, hInfo.N);
					hInfo.N = TBN*n;	
					hInfo.N = hInfo.N.GetNormalized();
					//printf("after: %f, %f, %f\n", hInfo.N.x, hInfo.N.y, hInfo.N.z);
				}
			}
		}
	}
	for (int i = 0; i < node->GetNumChild(); i++)
	{
		HitInfo h;
		if (recursiveTraceRay(r, h, node->GetChild(i), hitSide
			))
		{
			isHit = true;
			if(h.z < hInfo.z) {
				hInfo.z = h.z;
				hInfo.p = h.p;
				hInfo.N = h.N;
				hInfo.T = h.T;
				hInfo.uvw = h.uvw;
			//hInfo.duvw = h.duvw;
				hInfo.node = h.node;
				hInfo.front = h.front;
				hInfo.mtlID = h.mtlID;
			}
		}
	}
	node->FromNodeCoords(hInfo);
	return isHit;
}
