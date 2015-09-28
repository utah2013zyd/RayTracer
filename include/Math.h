#pragma once
#include "cyPoint.h"

class Math
{
public:
	Math();
	static inline float clamp(float data, float low, float high) { return data < low ? low : (data > high ? high : data); }
	static inline cyPoint3f reflect(cyPoint3f I, cyPoint3f N) { return 2.0 * I.Dot(N) * N - I; }
	~Math();
};

