#pragma once

#include "Vector3D.h"
#include "Surface.h"
#include "Ray.h"
#include "Rgb.h"

class RaySurfaceIntersection
{
private:
	Vector3D hitPoint;
	Vector3D normal;
	Rgb colour;
	Surface* surface;
public:
	RaySurfaceIntersection(Vector3D, Vector3D, Rgb, Surface*);
	~RaySurfaceIntersection();
	Vector3D getHitPoint();
	Vector3D getNormal();
	Rgb getColour();
};