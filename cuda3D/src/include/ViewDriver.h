#pragma once

#include <vector>

#include "Scene.h"
#include "ViewPort.h"
#include "Rgb.h"
#include "HitDetection.h"

class ViewDriver
{
public:
	ViewDriver(Scene*, ViewPort);
	vector<vector<Rgb>> processFrame();
	Rgb processLighting(HitDetection);
	bool isInShadow(HitDetection, Light*);
private:
	Scene* scene;
	ViewPort viewPort;

	Vector3D reflect(Vector3D, Vector3D);
};