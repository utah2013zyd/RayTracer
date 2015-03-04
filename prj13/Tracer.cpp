#include "Tracer.h"
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
			if (h.z < hInfo.z){
				hInfo = h;
			}
		}
	}
	node->FromNodeCoords(hInfo);
	return isHit;
}