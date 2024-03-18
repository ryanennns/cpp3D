#pragma once

#include <vector>
#include "Rgb.h"
#include "Ray.h"
#include "Vector3D.h"

class Surface
{
protected:
	Rgb colour;
public:
	virtual ~Surface() {};
	virtual std::vector<Vector3D> intersections(Ray) = 0;
	virtual void transform(Vector3D translation, Vector3D rotation = Vector3D(0, 0, 0)) = 0;
	virtual Surface* clone() const = 0; // Pure virtual clone method
	virtual Rgb getColour() = 0;
	virtual void setColour(Rgb) = 0;
};