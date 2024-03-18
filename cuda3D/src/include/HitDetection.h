#pragma once

#include "Vector3D.h"
#include "Object.h"

class HitDetection
{
public:
	//HitDetection(Vector3D, Object*, Rgb);
	HitDetection(Vector3D, Rgb);

	Vector3D getHitPoint();
	Rgb getColour();
	//Object getHitObject();
private:
	Vector3D hitPoint;
	//Object hitObject;
	Rgb colour;
};