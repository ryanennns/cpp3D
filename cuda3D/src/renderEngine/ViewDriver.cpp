#include <vector>
#include "../include/ViewDriver.h"
#include "../include/Sphere.h"
#include "../include/Light.h"

ViewDriver::ViewDriver(Scene scene, ViewPort viewPort)
{
	this->scene = scene;
	this->viewPort = viewPort;
}

vector<vector<Rgb>> ViewDriver::processFrame()
{
	vector<vector<Rgb>> rgbValues;

	vector<vector<Ray>> rays = viewPort.getRays();

	// replace from here
	Object object = Object();

	object.addSurface(new Sphere(Vector3D(0, 0, 10), 1));
	Light light = Light(Vector3D(-4,0,8));
	// to here with scene

	for (int y = 0; y < rays.size(); y++)
	{
		vector<Ray> row = rays.at(y);
		vector<Rgb> rgbColumn;
		for (int x = 0; x < row.size(); x++)
		{
			Ray ray = row.at(x);
			vector<Vector3D> intersections = scene.intersections(ray);
			if (intersections.size() > 0)
			{
				rgbColumn.push_back(processLighting(intersections.at(0)));
			}
		}
		rgbValues.push_back(rgbColumn);
	}

	return rgbValues;
}

Rgb ViewDriver::processLighting(Vector3D intersection)
{
	return Rgb(255, 255, 255);
}
