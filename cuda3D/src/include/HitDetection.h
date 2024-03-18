#pragma once

#include "Vector3D.h"
#include "Object.h"

class HitDetection
{
public:
	HitDetection(Vector3D, Object*, Rgb);

	Vector3D getHitPoint();
	Object getHitObject();
private:
	Vector3D hitPoint;
	Object hitObject;
	Rgb colour;
};