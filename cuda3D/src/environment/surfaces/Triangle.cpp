#include "../../include/Triangle.h"
#include "../../include/Vector3D.h"
#include "../../include/Ray.h"

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

	Vector3D normal = this->getNormal();
	double NdotRayDirection = normal.dotProduct(ray.getDirection());

	if (NdotRayDirection == 0.0) {
		return returnVector;
	}

	double d = -normal.dotProduct(this->getA());
	double t = -((normal.dotProduct(ray.getOrigin())) + d)
				/ NdotRayDirection;

	if (
		this->isPointInTriangle(ray.evaluate(t))
		&& t > 0
	) {
		returnVector.push_back(t);
	}

	return returnVector;
}

bool Triangle::isPointInTriangle(Vector3D point)
{
	Vector3D edge0 = B.subtract(A);
	Vector3D edge1 = C.subtract(B);
	Vector3D edge2 = A.subtract(C);

	Vector3D C0 = point.subtract(A);
	Vector3D C1 = point.subtract(B);
	Vector3D C2 = point.subtract(C);

	if (this->getNormal().dotProduct(edge0.crossProduct(C0)) > 0 &&
		this->getNormal().dotProduct(edge1.crossProduct(C1)) > 0 &&
		this->getNormal().dotProduct(edge2.crossProduct(C2)) > 0) {

		return true;
	}

	return false;
}

