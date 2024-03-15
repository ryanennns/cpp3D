#pragma once

#include <vector>
#include "Ray.h"

class Surface
{
public:
	virtual std::vector<double> intersections(Ray) = 0;
	virtual void transform(Vector3D translation, Vector3D rotation = Vector3D(0, 0, 0)) = 0;
};