#pragma once

#include <vector>
#include <memory>

#include "./Surface.h"
#include "./Ray.h"

class Object
{
public:
	Object();
	~Object();
	std::vector<double> intersections(Ray ray);
	void addSurface(Surface* surface);
private:
	std::vector<Surface*> surfaces;
};