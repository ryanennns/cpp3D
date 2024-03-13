#include "Sphere.h"
#include "stdio.h"
#include <cmath>

using namespace components;
using namespace std;

namespace environment
{
	double Sphere::intersectDiscriminant(Ray ray, double renderDistance)
	{
		Vector3D d = ray.evaluate(renderDistance);
		d.consoleDisplay();
		Vector3D e = ray.getOrigin();
		e.consoleDisplay();
		Vector3D c = this->center;
		double radius = this->radius;

		printf("pow(d.dotProduct(e.subtract(c)), 2):\t\t%lf\n", pow(d.dotProduct(e.subtract(c)), 2));
		printf("d.dotProduct(d), 2):\t\t\t\t%lf\n", d.dotProduct(d));
		printf("(e.subtract(c).dotProduct(e.subtract(c))):\t%lf\n", (e.subtract(c).dotProduct(e.subtract(c))));

		return pow(d.dotProduct(e.subtract(c)), 2) - (d.dotProduct(d) * (e.subtract(c).dotProduct(e.subtract(c))));
	}

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

	bool Sphere::rayIntersect(Ray ray, double renderDistance)
	{
		return this->intersectDiscriminant(ray, renderDistance) >= 0;
	}
}