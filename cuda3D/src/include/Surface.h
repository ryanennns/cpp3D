#pragma once

#include <vector>
#include "Ray.h"

class Surface
{
public:
	virtual std::vector<double> intersections(Ray) = 0;
};