#pragma once

#include <vector>

#include "Scene.h"
#include "ViewPort.h"
#include "Rgb.h"

class ViewDriver
{
public:
	ViewDriver(Scene*, ViewPort);
	vector<vector<Rgb>> processFrame();
private:
	Scene* scene;
	ViewPort viewPort;

	Rgb processLighting(Vector3D);
};