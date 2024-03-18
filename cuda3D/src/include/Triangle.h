#pragma once

#include "Surface.h"
#include "Vector3D.h"
#include "Ray.h"

#include <vector>

class Triangle : public Surface
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

	std::vector<Vector3D> intersections(Ray) override;
	void transform(Vector3D translation, Vector3D rotation = Vector3D(0, 0, 0)) override;
	Surface* clone() const override;

	Rgb getColour() override;
	void setColour(Rgb) override;
};