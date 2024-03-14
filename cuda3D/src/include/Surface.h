#pragma once

#include <vector>
#include "Ray.h"

class Surface
{
	virtual std::vector<double> intersections(Ray) = 0;
};