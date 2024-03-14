#pragma once

#include "Object.h"
#include <vector>

class Scene
{
public:
	Scene();
	void addObject(Object object);
	std::vector<Object> getObjects();
private:
	std::vector<Object> objects;
};