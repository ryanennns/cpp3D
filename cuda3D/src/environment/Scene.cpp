#include <vector>
#include "../include/Scene.h"

using namespace std;

Scene::Scene()
{

}

Scene::~Scene()
{
	for (int i = 0; i < this->objects.size(); i++)
	{
		//delete this->objects.at(i);
	}

	for (int i = 0; i < this->lights.size(); i++)
	{
		//delete this->lights.at(i);
	}
}

void Scene::addLight(Light* light)
{
	this->lights.push_back(light);
}

void Scene::addObject(Object* object)
{
	this->objects.push_back(object);
}

vector<Object*> Scene::getObjects()
{
	return this->objects;
}

vector<Light*> Scene::getLights()
{
	return this->lights;
}

vector<HitDetection> Scene::intersections(Ray ray)
{
	vector<HitDetection> intersections;
	for (int i = 0; i < this->objects.size(); i++)
	{
		vector<Vector3D> objectIntersections = objects.at(i)->intersections(ray);
		if (objectIntersections.size() > 0)
		{
			for (int j = 0; j < objectIntersections.size(); j++)
			{
				intersections.push_back(
					HitDetection(
						objectIntersections.at(j),
						//objects.at(i),
						objects.at(i)->getColour()
					)
				);
			}
		}
	}
	return intersections;
}
