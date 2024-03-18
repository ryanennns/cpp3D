#include "../include/Vector3D.h"
#include "../include/Light.h"

Light::Light()
{
	this->origin = Vector3D(0, 0, 0);
	this->intensity = 10.0;
}

Light::Light(Vector3D origin, double intensity = 10.0)
{
	this->origin = origin;
	this->intensity = intensity;
}

Vector3D Light::getOrigin()
{
	return this->origin;
}

void Light::setOrigin(Vector3D origin)
{
	this->origin = origin;
}

double Light::getIntensity()
{
	return this->intensity;
}

void Light::setIntensity(double intensity)
{
	this->intensity = intensity;
}