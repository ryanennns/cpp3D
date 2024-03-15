#pragma once

#include <vector>

#include "Scene.h"
#include "ViewPort.h"
#include "Rgb.h"

class ViewDriver
{
public:
	ViewDriver(Scene, ViewPort);
private:
	Scene scene;
	ViewPort viewPort;

	vector<vector<Rgb>> processFrame();
};