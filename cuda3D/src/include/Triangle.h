#pragma once

#include "Surface.h"
#include "Vector3D.h"
#include "Ray.h"

#include <vector>

class Triangle : Surface
{
private:
	Vector3D A, B, C;

	bool isPointInTriangle(Vector3D);
public:
	Triangle(Vector3D, Vector3D, Vector3D);

	Vector3D getA();
	Vector3D getB();
	Vector3D getC();

	void setA(Vector3D);
	void setB(Vector3D);
	void setC(Vector3D);

	Vector3D getNormal();

	std::vector<double> intersections(Ray) override;
};