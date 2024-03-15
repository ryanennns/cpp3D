#pragma once

#include <vector>
#include <memory>

#include "./Surface.h"
#include "./Ray.h"

class Object
{
public:
	Object();
	std::vector<double> intersections(Ray ray);
private:
	std::vector<Surface*> surfaces;
};