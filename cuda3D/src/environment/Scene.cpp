#include <vector>
#include "../include/Scene.h"

Scene::Scene()
{

}

void Scene::addObject(Object object)
{
	this->objects.push_back(object);
}

std::vector<Object> Scene::getObjects()
{
	return this->objects;
}

