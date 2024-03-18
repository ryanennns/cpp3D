#include "../include/HitDetection.h"
#include "../include/Vector3D.h"
#include "../include/Object.h"

//HitDetection::HitDetection(Vector3D hitPoint, Object* object, Rgb colour)
//{
//	this->hitPoint = hitPoint;
//	this->hitObject = Object(*object);
//	this->colour = colour;
//}

HitDetection::HitDetection(Vector3D hitPoint, Rgb colour)
{
	this->hitPoint = hitPoint;
	this->colour = colour;
}

Vector3D HitDetection::getHitPoint()
{
	return this->hitPoint;
}

Rgb HitDetection::getColour()
{
	return this->colour;
}

//Object HitDetection::getHitObject()
//{
//	return this->hitObject;
//}