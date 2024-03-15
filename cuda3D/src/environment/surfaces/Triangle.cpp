#include "../../include/Triangle.h"
#include "../../include/Vector3D.h"
#include "../../include/Ray.h"

Triangle::Triangle(Triangle& t)
{
	this->A = t.getA();
	this->B = t.getB();
	this->C = t.getC();
}

Triangle::Triangle(Vector3D A, Vector3D B, Vector3D C) {
	this->A = A;
	this->B = B;
	this->C = C;
}

Vector3D Triangle::getA()
{
	return this->A;
}

Vector3D Triangle::getB()
{
	return this->B;
}

Vector3D Triangle::getC()
{
	return this->C;
}

void Triangle::setA(Vector3D A)
{
	this->A = A;
}

void Triangle::setB(Vector3D B)
{
	this->B = B;
}

void Triangle::setC(Vector3D C)
{
	this->C = C;
}

Vector3D Triangle::getNormal()
{
	Vector3D AB = B.subtract(A);
	Vector3D AC = C.subtract(A);
	Vector3D normal = AB.crossProduct(AC);
	normal.normalize();
	return normal;
}

std::vector<double> Triangle::intersections(Ray ray)
{
	std::vector<double> returnVector;

	// do stuff

	return returnVector;
}