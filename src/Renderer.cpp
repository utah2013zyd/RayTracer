#include "Renderer.h"

#include <iostream>
#include <time.h>
Renderer theRenderer;


extern Camera camera;
extern RenderImage renderImage;
extern MaterialList materials;
extern LightList lights;
extern TexturedColor background;


const float Renderer::threshold = 0.004;

Renderer::Renderer(void) : isStop(false), pixelNum(0)
{
}

Renderer::~Renderer(void){}

void Renderer::render(void)
{
	isStop = false;
	tRender = std::thread(&Renderer::renderImpl, this);
	tRender.join();
	//renderImpl();
}

void Renderer::stop(void)
{
	isStop = true;
}
void Renderer::renderImpl(void)
{
	Point3 y = camera.up;
	Point3 z = -camera.dir;
	Point3 x = y^z;
	float h = 2*tan(camera.fov/2.0*M_PI/180.0)*camera.focaldist;
	float w = h*camera.imgWidth/(float)camera.imgHeight;
	Point3 S0 = camera.pos - z*camera.focaldist + h/2*y - w/2*x;
	renderImage.ResetNumRenderedPixels();

	for (int i = 0; i < threadNum; i++)
		tPixel[i] = std::thread(&Renderer::renderPixel, this, S0, x, y, h, w);

	for (int i = 0; i < threadNum; i++)
		tPixel[i].join();
}

void Renderer::renderPixel(Point3 S0, Point3 x, Point3 y, float h, float w)
{
	int index;	
	while (pixelNum < renderImage.GetHeight()*renderImage.GetWidth())
	{
		mtx.lock();
		index = pixelNum;
		pixelNum++;
		mtx.unlock();

		int i, j;
		i = index / renderImage.GetWidth();
		j = index % renderImage.GetWidth();
		//i = 250;
		//j = 50;

		if (i %100 == 0 && j == 0)
			std::cout << i << " " << j << std::endl;
		Point3 Sij = S0 + j*w / camera.imgWidth*x - i*h / camera.imgHeight*y;
		
		//for multiple samples
		Color sampleColors[maxSampleCount];
		Color sumColor = Color(0, 0, 0);
		int sampleCount = 0;
		//srand(time(NULL));
		float shift = static_cast<float>(rand())/(static_cast<float>(RAND_MAX)+1);
		Color lastAverageColor = Color(0, 0, 0);
		//std::cout << shift << std::endl;
		while (sampleCount < maxSampleCount)
		{

			float sampleDepths = 0.0;
			for (int k = 0; k < minSampleCount; k++)
			{
				Point3 p = Sij + Halton(sampleCount, 2)*w / camera.imgWidth*x - Halton(sampleCount, 3)*h / camera.imgHeight*y;
				//generate random camera position
				float camRandomX, camRandomY;
				int index = sampleCount;
				float theta = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) + 1)*M_PI * 2;
				float length = std::sqrt(static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) + 1)*camera.dof);
				//do{
				//	camRandomX = Halton(index, 3);
				//	camRandomY = Halton(index, 2);
				//	
				//	camRandomX = shift + camRandomX>1 ? shift + camRandomX - 1 : shift + camRandomX;
				//	camRandomY = shift + camRandomY>1 ? shift + camRandomY - 1 : shift + camRandomY;
				//	index++;
				//} while (camRandomX*camRandomX + camRandomY*camRandomY > camera.dof*camera.dof);

				Point3 cameraPos = camera.pos + x*length*sin(theta) + y*length*cos(theta);
				Ray r(cameraPos, p - cameraPos);
				//Ray r(camera.pos, p - camera.pos);
				HitInfo hit;

				if (Tracer::traceRay(r, hit))
				{
					const Material* mat = hit.node->GetMaterial();
					if (mat != NULL)
						sampleColors[sampleCount] = mat->Shade(r, hit, lights, bounceCount);
						//sampleColors[sampleCount] = photonGenerator.ShadePhoton(r, hit);
					else
						sampleColors[sampleCount] = Color(255, 255, 255);

					renderImage.GetZBuffer()[i*renderImage.GetWidth() + j] = hit.z;
				}
				else
				{
					sampleColors[sampleCount] = background.Sample(Point3(j / (float)renderImage.GetWidth(), i / (float)renderImage.GetHeight(), 0));
					//sampleColors[sampleCount] = Color(0, 0, 0);
					renderImage.GetZBuffer()[i*renderImage.GetWidth() + j] = BIGFLOAT;
				}
				//if (sampleColors[sampleCount].r <= 0 || sampleColors[sampleCount].g <= 0 || sampleColors[sampleCount].b <= 0)
				//	std::cout << "here" << std::endl;
				sumColor += sampleColors[sampleCount];
				sampleCount++;
			}
			
			//calculate the standard deviation
			Color averageColor = sumColor / sampleCount;
			Color test = averageColor - lastAverageColor;
			if (test.r < threshold && test.g < threshold && test.b < threshold)
				break;
			lastAverageColor = averageColor;
			//Color sigma = Color(0, 0, 0);
			//for (int k = 0; k < sampleCount; k++)
			//	sigma += (sampleColors[k] - averageColor)*(sampleColors[k] - averageColor);
			//sigma /= sampleCount;
			//if (sigma.r < threshold && sigma.g < threshold && sigma.b < threshold)
			//	break;
		}
		Color pixelColor = sumColor / sampleCount;
		//printf("final color: %f, %f, %f \n", pixelColor.r, pixelColor.g, pixelColor.b);

		renderImage.GetPixels()[i*renderImage.GetWidth() + j] = Color(pow(pixelColor.r, 1/2.2), pow(pixelColor.g, 1/2.2), pow(pixelColor.b, 1/2.2));
		renderImage.GetSampleCount()[i*renderImage.GetWidth() + j] = sampleCount;
		//renderImage.GetZBuffer()[i*renderImage.GetWidth() + j] = sampleDepths / (float)renderImage.GetSampleCount()[i*renderImage.GetWidth() + j];
	}//renderImage.IncrementNumRenderPixel(1);
}

void BeginRender() // Called to start rendering (renderer must run in a separate thread)
{
	theRenderer.render();
}
void StopRender()  // Called to end rendering (if it is not already finished)
{
	theRenderer.stop();
}
