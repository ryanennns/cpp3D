#include "../../include/Sphere.h"
#include "stdio.h"
#include <cmath>
#include <vector>

using namespace std;

Sphere::Sphere()
{
	this->center = Vector3D(0,0,0);
	this->radius = 1;
}

Sphere::Sphere(const Vector3D& center, double radius)
{
	this->center = Vector3D(center);
	this->radius = radius;
}

Vector3D Sphere::getCenter()
{
	return this->center;
}

double Sphere::getRadius()
{
	return this->radius;
}

std::vector<double> Sphere::intersections(Ray ray)
{
	const double discriminant = this->intersectDiscriminant(ray);
	vector<double> returnVector;

	if (discriminant < 0.0) {
		return returnVector;
	}

	Vector3D d = ray.getDirection();
	Vector3D e = ray.getOrigin();
	Vector3D center = this->center;

	double a = d.dotProduct(d);
	double b = 2 * d.dotProduct(e.subtract(center));

	returnVector.push_back(
		(-b - sqrt(discriminant)) / (2 * a)
	);

	if (discriminant > 0.0) {
		returnVector.push_back(
			(-b + sqrt(discriminant)) / (2 * a)
		);
	}

	return returnVector;
}

double Sphere::intersectDiscriminant(Ray ray)
{
	Vector3D d = ray.getDirection();
	Vector3D e = ray.getOrigin();
	Vector3D center = this->center;
	double radius = this->radius;

	double a = d.dotProduct(d);
	double b = 2 * (d.dotProduct(e.subtract(center)));
	double c = e.subtract(center).dotProduct(e.subtract(center)) - pow(radius, 2);

	return pow(b, 2) - (4.0 * (a * c));
}

void Sphere::transform(Vector3D translation, Vector3D rotation)
{
	this->center = this->center.add(translation);
}