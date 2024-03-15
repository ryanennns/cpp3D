#pragma once

#include "Object.h"
#include <vector>

class Scene
{
public:
	Scene();

	void addObject(Object object);
	std::vector<Object> getObjects();
	std::vector<double> intersections(Ray);
private:
	std::vector<Object> objects;
};