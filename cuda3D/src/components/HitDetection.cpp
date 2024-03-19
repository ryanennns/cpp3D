#include "../include/HitDetection.h"
#include "../include/Vector3D.h"
#include "../include/Object.h"

//HitDetection::HitDetection(Vector3D hitPoint, Object* object, Rgb colour)
//{
//	this->hitPoint = hitPoint;
//	this->hitObject = Object(*object);
//	this->colour = colour;
//}

HitDetection::HitDetection(Vector3D hitPoint, Vector3D surfaceNormal, Rgb colour)
{
	this->hitPoint = hitPoint;
	this->surfaceNormal = surfaceNormal;
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

Vector3D HitDetection::getNormal()
{
	return this->surfaceNormal;
}

//Object HitDetection::getHitObject()
//{
//	return this->hitObject;
//}