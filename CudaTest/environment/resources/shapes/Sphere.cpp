#include "Sphere.h"
#include <cmath>

using namespace components;
using namespace std;

namespace environment
{
	double Sphere::intersectDiscriminant(Ray ray, double renderDistance)
	{
		Vector3D d = ray.evaluate(renderDistance);
		Vector3D e = ray.getOrigin();
		Vector3D c = this->center;
		double radius = this->radius;
		
		// (Math.pow(d.dot(e.sub(c)), 2)
		// (
		//		d.dot(d) * (e.sub(c).dot(e.sub(c)))
		//	  - Math.pow(this->radius, 2)
		// )

		return pow(d.dotProduct(e.subtract(c)), 2) - (d.dotProduct(d) * (e.subtract(c).dotProduct(e.subtract(c))));

		//return Math.pow(d.dot(e.sub(c)), 2) - (d.dot(d) * (e.sub(c).dot(e.sub(c))) - Math.pow(this->radius, 2));
	}

	Sphere::Sphere()
	{
		this->center = Vector3D(0,0,0);
		this->radius = 1;
	}

	Sphere::Sphere(Vector3D* center, double radius)
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