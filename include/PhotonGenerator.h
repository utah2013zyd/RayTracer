#pragma once
#include "photonmap.h"
#include "scene.h"
#include "Tracer.h"
#include <vector>
#include <string>
class PhotonGenerator
{
public:
	PhotonGenerator(){};
	PhotonGenerator(int maxNum);
	~PhotonGenerator();

	void Init(int maxNum);
	void createMap();
	void buildPhoton(const int bounceCount);
	void tracePhoton(const Ray ray, const Color intensity, int bounceCount);
	void saveMap(char* fileName);

	void getIrradiance(Color &irrad, Point3 &direction, const Ray &ray, const HitInfo &hInfo) const;
	void getCausticIrradiance(Color &irrad, Point3 &direction, const Ray &ray, const HitInfo &hInfo) const;
private:
	PhotonMap* map;
	BalancedPhotonMap* bmap;
	PhotonMap* caus_map;
	BalancedPhotonMap* b_caus_map;
	float PTotal;
	std::vector<float> lightsRange;
	static const int maxBounce = 100;
	int photonNum;
};

