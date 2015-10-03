#include "PhotonGenerator.h"
#include <iostream>
extern LightList lights;

PhotonGenerator::PhotonGenerator(int maxNum) : photonNum(maxNum), PTotal(0.0)
{
	map = createPhotonMap(1000000);
	lightsRange.push_back(0.0);
	for (int i = 0; i < lights.size(); i++)
	{
		if (lights[i]->IsPhotonSource())
		{
			Color inten = lights[i]->GetPhotonIntensity();
			float lightsRan = inten.r >(inten.g > inten.b ? inten.g : inten.b) ? inten.r : (inten.g > inten.b ? inten.g : inten.b);
			PTotal += lightsRan;
			lightsRange.push_back(lightsRan + lightsRange.back());
		}
	}
}
void PhotonGenerator::Init(int maxNum)
{
	photonNum = maxNum;
	PTotal = 0.0;
	map = createPhotonMap(1000000);
	caus_map = createPhotonMap(100000);
	lightsRange.push_back(0.0);
	for (int i = 0; i < lights.size(); i++)
	{
		if (lights[i]->IsPhotonSource())
		{
			Color inten = lights[i]->GetPhotonIntensity();
			float lightsRan = inten.r >(inten.g > inten.b ? inten.g : inten.b) ? inten.r : (inten.g > inten.b ? inten.g : inten.b);
			PTotal += lightsRan;
			lightsRange.push_back(lightsRan + lightsRange.back());
		}
	}
}
void PhotonGenerator::createMap()
{
	//for (int i = 0; i < threadNum; i++)
	//	tPhoton[i] = std::thread(&PhotonGenerator::buildPhoton, this, maxBounce);

	//for (int i = 0; i < threadNum; i++)
	//	tPhoton[i].join();
	buildPhoton(maxBounce);
	bmap = balancePhotonMap(map);
	b_caus_map = balancePhotonMap(caus_map);
	savePhotonMap(bmap, "photonMap.dat");
	savePhotonMap(b_caus_map, "causticMap.dat");
}

void PhotonGenerator::buildPhoton(const int maxBounce)
{
	int emittedNum = 0;
	while (emittedNum < photonNum)
	{
		emittedNum++;
		//std::cout << photonNum <<" "<< map->stored_photons<< std::endl;
		
		//emit photon
		Ray r;
		Color photonIntensity;
		float lightIndex = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) + 1)*PTotal;
		for (int i = 0; i < lightsRange.size()-1; i++)
		{
			if (lightIndex >= lightsRange[i] && lightIndex < lightsRange[i + 1])
			{
				r = lights[i]->RandomPhoton();
				photonIntensity = PTotal*lights[i]->GetPhotonIntensity()/photonNum / (lightsRange[i + 1] - lightsRange[i]);
				break;
			}
		}

		//trace photon
		int bounceCount = 0;
		bool isCaustic = false;
		while (bounceCount < maxBounce)
		{
			HitInfo hit;
			if (Tracer::traceRay(r, hit))
			{
				const Material* mat = hit.node->GetMaterial();
				if (mat->IsPhotonSurface())
				{
					if (bounceCount >= 2 && !isCaustic)
					{
						float power[3] = { photonIntensity.r, photonIntensity.g, photonIntensity.b };
						//float power[3] = { 1, 1, 1 };
						float pos[3] = { hit.p.x, hit.p.y, hit.p.z };
						float dir[3] = { r.dir.x, r.dir.y, r.dir.z };
						storePhoton(map, power, pos, dir);
					}
					else if (isCaustic)
					{
						float power[3] = { photonIntensity.r, photonIntensity.g, photonIntensity.b };
						//float power[3] = { 1, 1, 1 };
						float pos[3] = { hit.p.x, hit.p.y, hit.p.z };
						float dir[3] = { r.dir.x, r.dir.y, r.dir.z };
						storePhoton(caus_map, power, pos, dir);
						break;
					}

				}
				else
				{
					isCaustic = true;
				}

				if (!mat->RandomPhotonBounce(r, photonIntensity, hit))
					break;
				bounceCount++;
			}
			else
				break;
		}
	}
}

void PhotonGenerator::getIrradiance(Color &irrad, Point3 &direction, const Ray &ray, const HitInfo &hInfo) const
{
	float ir[3];
	float dir[3];
	float pos[3] = { hInfo.p.x, hInfo.p.y, hInfo.p.z };
	float normal[3] = { hInfo.N.x, hInfo.N.y, hInfo.N.z };
	irradianceEstimate(bmap, ir, dir, pos, normal, 0.5, 1000);
	irrad = Color(ir);
	direction = Point3(dir);
}

void PhotonGenerator::getCausticIrradiance(Color &irrad, Point3 &direction, const Ray &ray, const HitInfo &hInfo) const
{
	float ir[3];
	float dir[3];
	float pos[3] = { hInfo.p.x, hInfo.p.y, hInfo.p.z };
	float normal[3] = { hInfo.N.x, hInfo.N.y, hInfo.N.z };
	irradianceEstimate(b_caus_map, ir, dir, pos, normal, 0.25, 4000);
	irrad = Color(ir);
	direction = Point3(dir);
}
PhotonGenerator::~PhotonGenerator()
{
	destroyPhotonMap(bmap);
}
