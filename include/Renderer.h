#ifndef _RENDERER_H_INCLUDED_
#define _RENDERER_H_INCLUDED_
 
#include "scene.h"
#include "Tracer.h"
#include <thread>
#include <mutex>
class Renderer
{
public:
	Renderer();
	~Renderer();
	void render(void);

	void stop(void);

private:
	void renderImpl(void);

	void renderPixel(Point3 S0, Point3 x, Point3 y, float h, float w);


private:
	static const int threadNum = 16;
	static const int bounceCount = 8;
	static const int maxSampleCount = 64;
	static const int minSampleCount = 16;
	static const float threshold;
	std::thread tRender;
	std::thread tPixel[threadNum];
	std::mutex mtx;
	volatile int pixelNum;
	volatile bool isStop;
};
extern Renderer theRenderer;
#endif
