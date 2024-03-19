#pragma once

#include "Vector3D.h"

class Light
{
public:
	Light();
	Light(Vector3D);

	Vector3D getOrigin();
	void setOrigin(Vector3D);

	double getIntensity();
	void setIntensity(double);
private:
	Vector3D origin;
};