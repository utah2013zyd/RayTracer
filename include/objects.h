
//-------------------------------------------------------------------------------
///
/// \file       objects.h 
/// \author     Cem Yuksel (www.cemyuksel.com)
/// \version    6.2
/// \date       December 4, 2014
///
/// \brief Example source for CS 6620 - University of Utah.
///
//-------------------------------------------------------------------------------

#ifndef _OBJECTS_H_INCLUDED_
#define _OBJECTS_H_INCLUDED_

#include "scene.h"
#include "cyTriMesh.h"
#include "cyBVH.h"

//-------------------------------------------------------------------------------

class Sphere : public Object
{
public:
	virtual bool IntersectRay(const Ray &ray, HitInfo &hInfo, int hitSide = HIT_FRONT) const;
	virtual void ViewportDisplay(const Material *mtl) const{}
	virtual Box GetBoundBox() const { return Box(-1, -1, -1, 1, 1, 1); }
};

extern Sphere theSphere;

//-------------------------------------------------------------------------------

class Plane : public Object
{
public:
	virtual bool IntersectRay(const Ray &ray, HitInfo &hInfo, int hitSide = HIT_FRONT) const;
	virtual void ViewportDisplay(const Material *mtl) const{}
	virtual Box GetBoundBox() const { return Box(-1, -1, 0, 1, 1, 0); }
};

extern Plane thePlane;

//-------------------------------------------------------------------------------

class TriObj : public Object, public cyTriMesh
{
public:
	virtual bool IntersectRay(const Ray &ray, HitInfo &hInfo, int hitSide = HIT_FRONT) const;
	virtual void ViewportDisplay(const Material *mtl) const{}
	virtual Box GetBoundBox() const { return Box(GetBoundMin(), GetBoundMax()); }

	bool Load(const char *filename, bool loadMtl)
	{
		bvh.Clear();
		if (!LoadFromFileObj(filename, loadMtl)) return false;
		if (!HasNormals()) ComputeNormals();
		ComputeTangents();
		ComputeBoundingBox();
		bvh.SetMesh(this, 4);
		return true;
	}

private:
	cyBVHTriMesh bvh;
	bool IntersectTriangle(const Ray &ray, HitInfo &hInfo, int hitSide, unsigned int faceID) const;
	bool TraceBVHNode(const Ray &ray, HitInfo &hInfo, int hitSide, unsigned int nodeID) const;
};

//-------------------------------------------------------------------------------

#endif
