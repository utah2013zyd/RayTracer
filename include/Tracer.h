#pragma once

#include "scene.h"
class Tracer
{
public:
	Tracer();
	~Tracer();


	static bool traceRay(const Ray &ray, HitInfo &hInfo, int hitSide = HIT_FRONT);

	static bool recursiveTraceRay(const Ray &ray, HitInfo &hInfo, const Node* node, int hitSide = HIT_FRONT);
};

