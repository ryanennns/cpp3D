#pragma once

#include "Vector3D.h"

class Light
{
public:
	Light();
	Light(Vector3D, double);

	Vector3D getOrigin();
	void setOrigin(Vector3D);

	double getIntensity();
	void setIntensity(double);
private:
	Vector3D origin;
	double intensity;
};