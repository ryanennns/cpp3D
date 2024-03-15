#pragma once

#include <vector>
#include "Ray.h"
#include "Vector3D.h"

class Surface
{
public:
	virtual std::vector<Vector3D> intersections(Ray) = 0;
	virtual void transform(Vector3D translation, Vector3D rotation = Vector3D(0, 0, 0)) = 0;
};