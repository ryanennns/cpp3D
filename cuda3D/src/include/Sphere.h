#pragma once

#include "../include/Vector3D.h"
#include "../include/Ray.h"
#include <vector>

class Sphere
{
private:
	Vector3D center;
	double radius;

	double intersectDiscriminant(Ray);
public:
	Sphere();
	Sphere(const Vector3D&, double);

	Vector3D getCenter();
	double getRadius();

	std::vector<double> rayIntersect(Ray);
};