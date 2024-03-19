#include <vector>
#include <algorithm>
#include <cmath>
#include "../include/ViewDriver.h"
#include "../include/Sphere.h"
#include "../include/Light.h"

ViewDriver::ViewDriver(Scene* scene, ViewPort viewPort)
{
	this->scene = scene;
	this->viewPort = viewPort;
}

vector<vector<Rgb>> ViewDriver::processFrame()
{
	vector<vector<Rgb>> rgbValues;
	vector<vector<Ray>> rays = viewPort.getRays();

	for (int y = 0; y < rays.size(); y++)
	{
		vector<Ray> row = rays.at(y);
		vector<Rgb> rgbColumn;
		for (int x = 0; x < row.size(); x++)
		{
			Ray ray = row.at(x);
			vector<HitDetection> intersections = scene->intersections(ray);
			if (intersections.size() > 0)
			{
				rgbColumn.push_back(processLighting(intersections.at(0)));
			}
			else
			{
				rgbColumn.push_back(Rgb(12, 12, 12));
			}
		}
		rgbValues.push_back(rgbColumn);
	}

	return rgbValues;
}

Rgb ViewDriver::processLighting(HitDetection intersection)
{
	Light* light = this->scene->getLights().at(0);
	Vector3D normal = intersection.getNormal().normalize();
	Vector3D hitPoint = intersection.getHitPoint();
	Rgb objectColor = intersection.getColour(); 

	// todo implement ambient light shade for individual objects
	Rgb ambient = Rgb(0,0,0);

	Vector3D lightDirection = light->getOrigin().subtract(hitPoint).normalize();

	double diff = std::fabs(normal.dotProduct(lightDirection)); // returns 0 for all triangles
	Rgb diffuse = objectColor * diff;

	Rgb combinedLight = (ambient + diffuse);

	if (this->isInShadow(intersection, light))
	{
		combinedLight = combinedLight * 0.15;
	}

	return combinedLight;
}

bool ViewDriver::isInShadow(HitDetection intersection, Light* light)
{
	Ray intersectionToLight = Ray(intersection.getHitPoint(), light->getOrigin());
	vector<HitDetection> sceneIntersections = this->scene->intersections(intersectionToLight);
	return sceneIntersections.size() > 0;
}
