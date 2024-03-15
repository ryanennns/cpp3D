#include <vector>
#include "../include/Scene.h"

using namespace std;

Scene::Scene()
{

}

void Scene::addObject(Object object)
{
	this->objects.push_back(object);
}

vector<Object> Scene::getObjects()
{
	return this->objects;
}

vector<double> Scene::intersections(Ray ray)
{
	vector<double> intersections;
	for (int i = 0; i < this->objects.size(); i++)
	{
		vector<double> objectIntersections = objects[i].intersections(ray);
		if (objectIntersections.size() > 0)
		{
			intersections.push_back(objectIntersections.at(0));
		}
	}
	return intersections;
}
