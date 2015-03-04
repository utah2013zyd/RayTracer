#include "materials.h"
#include <iostream>
#include "Math.h"
#include "PhotonGenerator.h"
#include "Tracer.h"
extern Camera camera;
extern TexturedColor environment;
extern PhotonGenerator photonGenerator;

#define REFLECT_SAMPLE 4
#define REFRACT_SAMPLE 4

Color MtlBlinn::Shade(const Ray &ray, const HitInfo &hInfo, const LightList &lights, int bounceCount) const
{
	Color result(0, 0, 0);

	//direct illumination
	result += directShade(ray, hInfo, lights);

	//indirect illumination
	if (diffuse.GetColor().Gray() > 0)
	{
		for (int i = 0; i < lights.size(); i++)
		{
			if (lights[i]->IsAmbient())
			{
				result += lights[i]->Illuminate(hInfo.p, hInfo.N)*this->diffuse.Sample(hInfo.uvw);
				
				//std::cout << temp.r << " " << temp.g << " " << temp.b << std::endl;
			}
		}
	}
	if (reflection.GetColor().Gray() > 0)
	{
		result += reflectShade(ray, hInfo, lights, bounceCount);
	}
	if (refraction.GetColor().Gray() > 0)
	{
		result += refractShade(ray, hInfo, lights, bounceCount);
	}

	Color irradiance;
	Point3 direction;

	photonGenerator.getCausticIrradiance(irradiance, direction, ray, hInfo);
	if (irradiance.Gray() <= 0)
		return result;
	float LDotN = (-direction.GetNormalized()).Dot(hInfo.N);
	// clamp l dot n
	LDotN = Math::clamp(LDotN, 0.0, 1.0);
	Color diffuseFactor = this->diffuse.Sample(hInfo.uvw) * LDotN;
	// calculate specular factor
	Point3 H = (-direction.GetNormalized() - ray.dir.GetNormalized()).GetNormalized();
	float HDotN = H.Dot(hInfo.N);
	// clamp h dot n
	HDotN = Math::clamp(HDotN, 0.0, 1.0);
	Color specularFactor = this->specular.Sample(hInfo.uvw) * pow(HDotN, this->glossiness)*LDotN;
	Color re = irradiance * (diffuseFactor + specularFactor);
	if (re.r < 0 || re.g < 0 || re.b < 0){
		std::cout << irradiance.r << " " << irradiance.g << " " << irradiance.b << " ";
		std::cout << diffuseFactor.r << " " << diffuseFactor.g << " " << diffuseFactor.b << " ";
		std::cout << specularFactor.r << " " << specularFactor.g << " " << specularFactor.b << std::endl;
	}
	result += irradiance * (diffuseFactor + specularFactor);

	return result;

 }

Color MtlBlinn::directShade(const Ray &ray, const HitInfo &hInfo, const LightList &lights) const
{
	 Color result = Color(0.0, 0.0, 0.0);

	 for (int i = 0; i < lights.size(); i++)
	 {
		 if (!lights[i]->IsAmbient())
		 {
			 // calculate diffuse factor
			 float LDotN = (-lights[i]->Direction(hInfo.p)).Dot(hInfo.N);
			 // clamp l dot n
			 LDotN = Math::clamp(LDotN, 0.0, 1.0);
			 Color diffuseFactor = this->diffuse.Sample(hInfo.uvw) * LDotN;
			 // calculate specular factor
			 Point3 H = (-lights[i]->Direction(hInfo.p).GetNormalized() - ray.dir.GetNormalized()).GetNormalized();
			 float HDotN = H.Dot(hInfo.N);
			 // clamp h dot n
			 HDotN = Math::clamp(HDotN, 0.0, 1.0);
			 Color specularFactor = this->specular.Sample(hInfo.uvw) * pow(HDotN, this->glossiness)*LDotN;
			 result += lights[i]->Illuminate(hInfo.p, hInfo.N) * (diffuseFactor + specularFactor);
		 }
	 }
	 return result;
}

Color MtlBlinn::photonShade(const Ray &ray, const HitInfo &hInfo) const
{
	Color irradiance;
	Point3 direction; 

	photonGenerator.getIrradiance(irradiance, direction, ray, hInfo);
	if (irradiance.Gray() <= 0)
		return Color(0, 0, 0);
	float LDotN = (-direction.GetNormalized()).Dot(hInfo.N);
	// clamp l dot n
	LDotN = Math::clamp(LDotN, 0.0, 1.0);
	Color diffuseFactor = this->diffuse.Sample(hInfo.uvw) * LDotN;
	// calculate specular factor
	Point3 H = (-direction.GetNormalized() - ray.dir.GetNormalized()).GetNormalized();
	float HDotN = H.Dot(hInfo.N);
	// clamp h dot n
	HDotN = Math::clamp(HDotN, 0.0, 1.0);
	Color specularFactor = this->specular.Sample(hInfo.uvw) * pow(HDotN, this->glossiness)*LDotN;
	//Color result = irradiance * (diffuseFactor + specularFactor);
	//if (result.r < 0 || result.g < 0 || result.b < 0){
	//	std::cout << irradiance.r << " " << irradiance.g << " " << irradiance.b << " ";
	//	std::cout << diffuseFactor.r << " " << diffuseFactor.g << " " << diffuseFactor.b << " ";
	//	std::cout << specularFactor.r << " " << specularFactor.g << " " << specularFactor.b << std::endl;
	//}
	return irradiance * (diffuseFactor + specularFactor);
}

Color MtlBlinn::reflectShade(const Ray &ray, const HitInfo &hInfo, const LightList &lights, int bounceCount) const
{
	 //reflection
	 Color result;
	 if (bounceCount > 0)
	 {
	 	Color reflectPart = Color(0, 0, 0);

	 	Point3 reflectDir = Math::reflect(-ray.dir, hInfo.N).GetNormalized();

	 	Point3 x_circle = reflectDir.Cross(Point3(1, 0, 0));
	 	x_circle.Normalize();
	 	Point3 y_circle = x_circle.Cross(reflectDir);
	 	y_circle.Normalize();
	 	for (int i = 0; i < (reflectionGlossiness <= 0 ? 1 : REFLECT_SAMPLE); i++)
	 	{
	 		float theta = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*M_PI * 2;
	 		float length = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*reflectionGlossiness;
	 		
	 		Ray reflect;
	 		HitInfo reflectHit;
	 		reflect.p = hInfo.p;
	 		reflect.dir = reflectDir + x_circle*cos(theta)*length + y_circle*sin(theta)*length;
	 		reflect.dir.Normalize();
	 		if (Tracer::traceRay(reflect, reflectHit))
	 		{
	 			//Use the material of the hit point to shade the reflection color
	 			Color reflectColor = reflectHit.node->GetMaterial()->Shade(reflect, reflectHit, lights, bounceCount - 1);
	 			reflectPart += this->reflection.Sample(reflectHit.uvw)*reflectColor;
	 		}
	 		else
	 		{
	 			reflectPart += environment.SampleEnvironment(reflect.dir);
	 		}
	 	}
	 	reflectPart = reflectPart / (reflectionGlossiness <= 0 ? 1 : REFLECT_SAMPLE);
	 	result = reflectPart;
	 }
	 return result;
}

Color MtlBlinn::refractShade(const Ray &ray, const HitInfo &hInfo, const LightList &lights, int bounceCount) const
{
	//refraction
	Color result = Color(0, 0, 0);
 	float cosTheta = hInfo.N.Dot(-ray.dir);
 	float snell;
 	float r0;
 	float r ;

 	Color refractionFactor = Color(0, 0, 0);
 	Color reflectionFactor = Color(0, 0, 0);
 	if (cosTheta > 0)
 	{
 		snell = 1 / this->ior;
 		r0 = std::powf((1 - this->ior) / (1 + this->ior), 2.0f);
 		r = r0 + (1 - r0)*powf(1 - cosTheta, 5.0f);
 	}
 	else
 	{
 		snell = this->ior / 1;
 		r0 = std::powf((this->ior-1) / (1 + this->ior), 2.0f);
 		r = r0 + (1 - r0)*powf(1 - cosTheta, 5.0f);
 	}
 	float cosThetaT2 = 1 - snell*snell*(1 - cosTheta*cosTheta);

	if (cosThetaT2 >= 0)  // refraction as usual
	{
		float cosThetaT = std::sqrtf(cosThetaT2);
		Point3 refractDir;

		if (cosTheta > 0)
			refractDir = -hInfo.N * cosThetaT + (hInfo.N * cosTheta + ray.dir)*snell;
		else
			refractDir = hInfo.N * cosThetaT + (hInfo.N * cosTheta + ray.dir)*snell;

		Point3 x_circle = refractDir.Cross(Point3(1, 0, 0));
		x_circle.Normalize();
		Point3 y_circle = x_circle.Cross(refractDir);
		y_circle.Normalize();
		for (int i = 0; i < (refractionGlossiness <= 0 ? 1 : REFRACT_SAMPLE); i++)
		{
			float theta = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*M_PI * 2;
			float length = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*refractionGlossiness;
			Ray refract;
			HitInfo refractHit;
			refract.p = hInfo.p;
			refract.dir = refractDir + x_circle*cos(theta)*length + y_circle*sin(theta)*length;
			refract.dir.Normalize();
			if (Tracer::traceRay(refract, refractHit, HIT_FRONT_AND_BACK))
			{
				Color refractColor = refractHit.node->GetMaterial()->Shade(refract, refractHit, lights, bounceCount - 1);
				float distance = (refractHit.p - refract.p).Length();
				Color absorptionFactor = Color(std::exp(-distance * this->absorption.r), std::exp(-distance * this->absorption.g), std::exp(-distance * this->absorption.b));
				refractionFactor += this->refraction.Sample(hInfo.uvw)*refractColor * absorptionFactor;
			}
			else
			{
				refractionFactor += environment.SampleEnvironment(refract.dir);
			}

			refractionFactor = refractionFactor / (refractionGlossiness <= 0 ? 1 : REFRACT_SAMPLE);
		}
	}
 	else //total reflection
 	{
 		Ray TIReflect;
 		HitInfo TIReflectHit;
 		TIReflect.p = hInfo.p;
 		TIReflect.dir = Math::reflect(-ray.dir, -hInfo.N);
		if (Tracer::traceRay(TIReflect, TIReflectHit))
 		{
 			Color refractColor = TIReflectHit.node->GetMaterial()->Shade(TIReflect, TIReflectHit, lights, bounceCount-1);
 			float distance = (TIReflectHit.p - TIReflect.p).Length();
 			Color absorptionFactor = Color(std::exp(-distance * this->absorption.r), std::exp(-distance * this->absorption.g), std::exp(-distance * this->absorption.b));
 			refractionFactor += this->refraction.Sample(hInfo.uvw)*refractColor * absorptionFactor;
 		}
 	}

 	result += refractionFactor;
 	if (cosTheta > 0)
 	{
 		Ray reflect;
 		HitInfo reflectHit;
 		Color reflectColor;
 		reflect.p = hInfo.p;
 		reflect.dir = Math::reflect(-ray.dir, hInfo.N).GetNormalized();
 		if (Tracer::traceRay(reflect, reflectHit))
 		{
 			//Use the material of the hit point to shade the reflection color
 			reflectColor = reflectHit.node->GetMaterial()->Shade(reflect, reflectHit, lights, bounceCount - 1);
		}
 		else
 		{
 			reflectColor = environment.SampleEnvironment(reflect.dir);
 		}
 		result +=  this->refraction.Sample(hInfo.uvw)*reflectColor*r;
 	}
	return result;
}

bool MtlBlinn::RandomPhotonBounce(Ray &r, Color &c, const HitInfo &hInfo) const
{
	float Pd = max(diffuse.GetColor().r, max(diffuse.GetColor().g, diffuse.GetColor().b));
	float Ps = max(reflection.GetColor().r, max(reflection.GetColor().g, reflection.GetColor().b));
	float Pt = max(refraction.GetColor().r, max(refraction.GetColor().g, refraction.GetColor().b));
	float Pa = max(0, 1 - Pd - Ps - Pt);
	float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*(Pd + Ps + Pt + Pa);
	if (x < Pd)
	{
		//new color
		c = c * diffuse.GetColor()*Pd / (Pd + Ps + Pt + Pa);
		//new ray
		Point3 normal = hInfo.N.GetNormalized();
		Point3 tangent = Point3(1, 1, 1);
		if (normal.x != 0)
			tangent.x = -(normal.y + normal.z) / normal.x;
		else if (normal.y != 0)
			tangent.y = -normal.z / normal.y;
		else
			tangent.z = 0;
		tangent.Normalize();
		Point3 bitan = normal.Cross(tangent);
		bitan.Normalize();
		//float theta = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*M_PI * 2;
		//float length = std::sqrt(static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1));
		float u1 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1);
		float u2 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1);
		float length = std::sqrtf(1.0 - u1*u1);
		float phi = 2 * M_PI*u2;

		Point3 randomPoint = Point3(cos(phi)*length, sin(phi)*length, u1);

		r.p = hInfo.p;
		r.dir = (randomPoint.x*tangent + randomPoint.y*bitan + randomPoint.z*normal).GetNormalized();
	}
	else if (x >= Pd && x < Pd + Ps)
	{
		//new color
		c = c * reflection.GetColor()*Ps / (Pd + Ps + Pt + Pa);
		
		//new ray
		Point3 reflectDir = Math::reflect(-r.dir, hInfo.N).GetNormalized();

		Point3 x_circle = reflectDir.Cross(Point3(1, 0, 0));
		x_circle.Normalize();
		Point3 y_circle = x_circle.Cross(reflectDir);
		y_circle.Normalize();

		float theta = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*M_PI * 2;
		float length = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*reflectionGlossiness;

		r.p = hInfo.p;
		r.dir = reflectDir + x_circle*cos(theta)*length + y_circle*sin(theta)*length;
		r.dir.Normalize();
	}
	else if (x > Pd + Ps && x < Pd + Ps + Pt)
	{
		//new color
		c = c*refraction.GetColor()*Pt / (Pd + Ps + Pt + Pa);
		//refraction
		float cosTheta = hInfo.N.Dot(-r.dir);
		float snell;
		float r0;
		float r1;

		if (cosTheta > 0)
		{
			snell = 1 / this->ior;
			r0 = std::powf((1 - this->ior) / (1 + this->ior), 2.0f);
			r1 = r0 + (1 - r0)*powf(1 - cosTheta, 5.0f);
		}
		else
		{
			snell = this->ior / 1;
			r0 = std::powf((this->ior - 1) / (1 + this->ior), 2.0f);
			r1 = r0 + (1 - r0)*powf(1 - cosTheta, 5.0f);
		}
		float cosThetaT2 = 1 - snell*snell*(1 - cosTheta*cosTheta);

		if (cosThetaT2 >= 0)  // refraction as usual
		{
			float cosThetaT = std::sqrtf(cosThetaT2);
			Point3 refractDir;

			if (cosTheta > 0)
				refractDir = -hInfo.N * cosThetaT + (hInfo.N * cosTheta + r.dir)*snell;
			else
				refractDir = hInfo.N * cosThetaT + (hInfo.N * cosTheta + r.dir)*snell;

			Point3 x_circle = refractDir.Cross(Point3(1, 0, 0));
			x_circle.Normalize();
			Point3 y_circle = x_circle.Cross(refractDir);
			y_circle.Normalize();
			float theta = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*M_PI * 2;
			float length = static_cast<float>(rand()) / static_cast<float>(RAND_MAX + 1)*refractionGlossiness;

			r.p = hInfo.p;
			r.dir = refractDir + x_circle*cos(theta)*length + y_circle*sin(theta)*length;
			r.dir.Normalize();

		}
		else //total reflection
		{

			r.p = hInfo.p;
			r.dir = Math::reflect(-r.dir, -hInfo.N);
		}
	}
	else
		return false;

	return true;
}
//Color MtlPhong::Shade(const Ray &ray, const HitInfo &hInfo, const LightList &lights) const
//{
//	Color result(0, 0, 0);
//
//	for (int i = 0; i < lights.size(); i++)
//	{
//		//if (i == 0 || i == 1)
//		//{
//		if (lights[i]->IsAmbient())
//			result += lights[i]->Illuminate(hInfo.p) * this->diffuse;
//		else
//		{
//			// calculate diffuse factor
//			float LDotN = (-lights[i]->Direction(hInfo.p)).Dot(hInfo.N);
//			// clamp l dot n
//			LDotN = Math::clamp(LDotN, 0.0, 1.0);
//			Color diffuseFactor = this->diffuse * LDotN;
//
//			// calculate specular factor
//			Point3 R = Math::reflect(-lights[i]->Direction(hInfo.p), hInfo.N).GetNormalized();
//			float RDotV = R.Dot(ray.dir);
//			// clamp h dot n
//			RDotV = RDotV < 0.0 ? 0.0 : (RDotV > 1.0 ? 1.0 : RDotV);
//			Color specularFactor = this->specular * pow(RDotV, this->glossiness);
//			result += lights[i]->Illuminate(hInfo.p) * (diffuseFactor + specularFactor);
//		}
//		//}
//
//	}
//	return result;
//}