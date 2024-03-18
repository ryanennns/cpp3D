#include "../include/RaySurfaceIntersection.h"
#include "../include/Vector3D.h"
#include "../include/Surface.h"
#include "../include/Ray.h"
#include "../include/Rgb.h"

RaySurfaceIntersection::RaySurfaceIntersection(Vector3D hitPoint, Vector3D normal, Rgb colour, Surface* surface)
{
	this->hitPoint = hitPoint;
	this->normal = normal;
	this->colour = colour;
	this->surface = surface;
}

RaySurfaceIntersection::~RaySurfaceIntersection()
{
	delete this->surface;
}

Vector3D RaySurfaceIntersection::getHitPoint()
{
	return this->hitPoint;
}

Vector3D RaySurfaceIntersection::getNormal()
{
	return this->normal;
}

Rgb RaySurfaceIntersection::getColour()
{
	return this->colour;
}