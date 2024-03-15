#include <vector>
#include "../include/ViewDriver.h"

ViewDriver::ViewDriver(Scene scene, ViewPort viewPort)
{
	this->scene = scene;
	this->viewPort = viewPort;
}

vector<vector<Rgb>> ViewDriver::processFrame()
{
	vector<vector<Ray>> rays = viewPort.getRays();

	for (int i = 0; i < rays.size(); i++)
	{
		for (int j = 0; j < rays.at(i).size(); j++)
		{
			Ray ray = rays.at(i).at(j);

			vector<double> intersections = scene.intersections(ray);
		}
	}

	return vector<vector<Rgb>>();
}