#pragma once

#include "Vector3D.h"
#include "Object.h"

class HitDetection
{
public:
	HitDetection(Vector3D, Vector3D, Rgb);

	Vector3D getHitPoint();
	Vector3D getNormal();
	Rgb getColour();
private:
	Vector3D hitPoint;
	Vector3D surfaceNormal;
	Rgb colour;
};