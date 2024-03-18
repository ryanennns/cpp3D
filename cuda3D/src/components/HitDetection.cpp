#include "../include/HitDetection.h"
#include "../include/Vector3D.h"
#include "../include/Object.h"

HitDetection::HitDetection(Vector3D vector, Object* object, Rgb colour)
{
	this->hitPoint = vector;
	this->hitObject = Object(*object);
	this->colour = colour;
}

Vector3D HitDetection::getHitPoint()
{
	return this->hitPoint;
}

Object HitDetection::getHitObject()
{
	return this->hitObject;
}