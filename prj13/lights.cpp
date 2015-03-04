#include "lights.h"
#include "Tracer.h"
#include <iostream>
#include "PhotonGenerator.h"

#define SHADOW_SAMPLE 16
#define INDIRECT_SAMPLE 16
extern LightList lights;
extern TexturedColor environment;
extern PhotonGenerator photonGenerator;

float GenLight::Shadow(Ray ray, float t_max)
{
	HitInfo hit;
	if (Tracer::traceRay(ray, hit, HIT_FRONT_AND_BACK))
	{
		if (hit.z > t_max)
			return 1.0;
		else
			return 0.0;
	}
	else
		return 1.0;
}

Color PointLight::Illuminate(const Point3 &p, const Point3 &N) const
{
	Point3 x_circle = (p - position).GetNormalized().Cross(Point3(1, 0, 0));
	x_circle.Normalize();
	Point3 y_circle = x_circle.Cross((p - position).GetNormalized());
	y_circle.Normalize();
	float opacity = 0;
	for (int i = 0; i < (size == 0 ? 1 : SHADOW_SAMPLE); i++)
	{
		float theta = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*M_PI * 2;
		float length = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*size;

		Point3 pos = position + x_circle*cos(theta)*length + y_circle*sin(theta)*length;

		opacity += Shadow(Ray(p, pos - p), 1);

	}

	opacity /= (size == 0 ? 1 : SHADOW_SAMPLE);
	
	return opacity*intensity/std::fmax(1.0, (position-p).LengthSquared()*falloff);
}

Ray PointLight::RandomPhoton() const
{
	float x1, x2;
	do{
		x1 = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1) - 0.5) * 2;
		x2 = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1) - 0.5) * 2;
	} while (x1*x1 + x2*x2 > 1);

	Ray ray;
	ray.p = position;
	ray.dir.x = 2 * x1*std::sqrt(1 - x1*x1 - x2*x2);
	ray.dir.y = 2 * x2*std::sqrt(1 - x1*x1 - x2*x2);
	ray.dir.z = 1 - 2 * (x1*x1 + x2*x2);
	return ray;
}
Color IndirectLight::Illuminate(const Point3 &p, const Point3 &N) const
{
	Color intensity = Color(0, 0, 0);
	Point3 normal = N.GetNormalized();
	Point3 tangent = Point3(1, 1, 1);
	if (normal.x != 0)
		tangent.x = -(normal.y+normal.z)/normal.x;
	else if (normal.y != 0)
		tangent.y = -normal.z/normal.y;
	else
		tangent.z = 0;
	tangent.Normalize();
	Point3 bitan = normal.Cross(tangent);
	bitan.Normalize();

	for (int i = 0; i < INDIRECT_SAMPLE; i++)
	{
		float theta = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*M_PI * 2;
		float length = std::sqrt(static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1));

		Point3 randomPoint = Point3(length*cos(theta), length*sin(theta), sqrt(1 - length*length));
		Ray sample;
		sample.p = p;
		sample.dir = (randomPoint.x*tangent + randomPoint.y*bitan + randomPoint.z*normal).GetNormalized();
		HitInfo hit;
		//std::cout << sample.p.x << " " << sample.p.y << " " << sample.p.z << " " << sample.dir.x << " " << sample.dir.y << " " << sample.dir.z << std::endl;
		if (Tracer::traceRay(sample, hit))
		{
			const Material* mat = hit.node->GetMaterial();

			if (mat != NULL)
				intensity += mat->directShade(sample, hit, lights);
		}
		else
		{
			intensity += environment.SampleEnvironment(sample.dir);
		}
		
	}
	return intensity / INDIRECT_SAMPLE;
	//return Color(0, 0, 0);
}