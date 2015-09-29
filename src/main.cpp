#include "scene.h"
#include "objects.h"
#include "Renderer.h"
#include "PhotonGenerator.h"
#include <time.h>
#include <iostream>
Node rootNode;
Camera camera;
RenderImage renderImage;
MaterialList materials;
LightList lights;
ObjFileList objList;
TexturedColor background;
TexturedColor environment;
TextureList textureList;
PhotonGenerator photonGenerator;

extern int LoadScene(const char *filename);
//extern void ShowViewport();

int main()
{


	if(LoadScene("./scene.xml"))
	{
		//calculate render time
		clock_t start, finish;
		double totalTime;
		start = clock();

		photonGenerator.Init(100000);
		photonGenerator.createMap();
		theRenderer.render();
		
		finish = clock();
		totalTime = (double)(finish - start)/CLOCKS_PER_SEC;
		std::cout << totalTime<< std::endl;
		std::cin.get();
		renderImage.SaveImage("prj11_test.ppm");
		//renderImage.ComputeZBufferImage();
		//renderImage.SaveZImage("zbuffer_falloff.ppm");

		//renderImage.ComputeSampleCountImage();
		//renderImage.SaveSampleCountImage("samples_falloff.ppm");
		//ShowViewport();

	}
	return 0;
}
