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

	//Object object = Object();
	//object.addSurface(
	//	new Sphere(
	//		Vector3D(0, 0, 10),
	//		);

	for (int i = 0; i < rays.size(); i++)
	{
		vector<Ray> row = rays.at(i);
		for (int j = 0; j < row.size(); j++)
		{
			Ray ray = row.at(j);
			vector<Vector3D> intersections = scene.intersections(ray);
			if (intersections.size() > 0)
			{
				
			}
		}
	}

	return vector<vector<Rgb>>();
}