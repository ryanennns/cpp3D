#pragma once

#include "Vector3D.h"

class Light
{
public:
	Light();
	Light(Vector3D origin);
	Vector3D getOrigin();
	void setOrigin(Vector3D);
private:
	Vector3D origin;
};