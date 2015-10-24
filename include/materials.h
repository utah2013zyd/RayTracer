
//-------------------------------------------------------------------------------
///
/// \file       materials.h 
/// \author     Cem Yuksel (www.cemyuksel.com)
/// \version    12.3
/// \date       December 4, 2014
///
/// \brief Example source for CS 6620 - University of Utah.
///
//-------------------------------------------------------------------------------

#ifndef _MATERIALS_H_INCLUDED_
#define _MATERIALS_H_INCLUDED_

#include "scene.h"

//-------------------------------------------------------------------------------

class MtlBlinn : public Material
{
public:
	MtlBlinn() : diffuse(0.5f, 0.5f, 0.5f), specular(0.7f, 0.7f, 0.7f), glossiness(20.0f), emission(0, 0, 0),
		reflection(0, 0, 0), refraction(0, 0, 0), absorption(0, 0, 0), ior(1), viewportTextureID(0),
		reflectionGlossiness(0), refractionGlossiness(0) {}
	virtual Color Shade(const Ray &ray, const HitInfo &hInfo, const LightList &lights, int bounceCount) const;
	virtual Color directShade(const Ray &ray, const HitInfo &hInfo, const LightList &lights) const;
	virtual Color photonShade(const Ray &ray, const HitInfo &hInfo) const;
	virtual Color reflectShade(const Ray &ray, const HitInfo &hInfo, const LightList &lights, int bounceCount) const;
	virtual Color refractShade(const Ray &ray, const HitInfo &hInfo, const LightList &lights, int bounceCount) const;

	void SetDiffuse(Color dif)     { diffuse.SetColor(dif); }
	void SetSpecular(Color spec)    { specular.SetColor(spec); }
	void SetGlossiness(float gloss)   { glossiness = gloss; }
	void SetEmission(Color e)       { emission.SetColor(e); }
	void SetReflection(Color reflect) { reflection.SetColor(reflect); }
	void SetRefraction(Color refract) { refraction.SetColor(refract); }
	void SetAbsorption(Color absorp) { absorption = absorp; }
	void SetRefractionIndex(float _ior) { ior = _ior; }

	void SetDiffuseTexture(TextureMap *map)  { diffuse.SetTexture(map); }
	void SetSpecularTexture(TextureMap *map)  { specular.SetTexture(map); }
	void SetBumpTexture(TextureMap *map) {bump.SetTexture(map);}
	void SetEmissionTexture(TextureMap *map)  { emission.SetTexture(map); }
	void SetReflectionTexture(TextureMap *map)  { reflection.SetTexture(map); }
	void SetRefractionTexture(TextureMap *map)  { refraction.SetTexture(map); }
	void SetReflectionGlossiness(float gloss)   { reflectionGlossiness = gloss; }
	void SetRefractionGlossiness(float gloss)   { refractionGlossiness = gloss; }

	Point3 GetBumpNormal(const HitInfo &hInfo) const {
		if(bump.GetTexture() == NULL) {
			return Point3(0.0f, 0.0f, 1.0f);
		}
		else {
			Color tmp = bump.Sample(hInfo.uvw);
			tmp = tmp*2-1;
			return Point3(tmp.r, tmp.g, tmp.b);
		}
	}
	virtual void SetViewportMaterial(int subMtlID = 0) const{}   // used for OpenGL display

	// Photon Extensions
	virtual bool IsPhotonSurface() const { return diffuse.GetColor().Gray() > 0 && reflection.GetColor().Gray() <= 0 && refraction.GetColor().Gray() <= 0; }   // if this method returns true, the photon will be stored
	virtual bool RandomPhotonBounce(Ray &r, Color &c, const HitInfo &hInfo) const;  // if this method returns true, a new photon with the given direction and color will be traced

private:
	TexturedColor diffuse, specular, bump, reflection, refraction, emission;
	float glossiness;
	Color absorption;
	float ior;  // index of refraction
	float reflectionGlossiness, refractionGlossiness;
	unsigned int viewportTextureID;
};

//-------------------------------------------------------------------------------

class MultiMtl : public Material
{
public:
	virtual ~MultiMtl() { for (unsigned int i = 0; i<mtls.size(); i++) delete mtls[i]; }
	//Cone?
	virtual Color Shade(const Ray &ray, const HitInfo &hInfo, const LightList &lights, int bounceCount) const { return hInfo.mtlID<(int)mtls.size() ? mtls[hInfo.mtlID]->Shade(ray, hInfo, lights, bounceCount) : Color(1, 1, 1); }

	virtual void SetViewportMaterial(int subMtlID = 0) const { if (subMtlID<(int)mtls.size()) mtls[subMtlID]->SetViewportMaterial(); }

	// Photon Extensions
	virtual bool IsPhotonSurface() const { for (unsigned int i = 0; i<mtls.size(); i++) if (mtls[i]->IsPhotonSurface()) return true; return false; }
	virtual bool RandomPhotonBounce(Ray &r, Color &c, const HitInfo &hInfo) const { return hInfo.mtlID<(int)mtls.size() ? mtls[hInfo.mtlID]->RandomPhotonBounce(r, c, hInfo) : false; }
	Point3 GetBumpNormal(const HitInfo &hInfo) const {return hInfo.mtlID < (int)mtls.size() ? mtls[hInfo.mtlID]->GetBumpNormal(hInfo) : Point3(0.0f, 0.0f, 1.0f);}
	void AppendMaterial(Material *m) { mtls.push_back(m); }

private:
	std::vector<Material*> mtls;
};

//-------------------------------------------------------------------------------

#endif
