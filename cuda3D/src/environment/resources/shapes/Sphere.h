#pragma once

#include "../../../components/headers/Vector3D.h"
#include "../../../components/headers/Ray.h"

using namespace components;

namespace environment
{
	class Sphere
	{
	private:
		Vector3D center;
		double radius;

		double intersectDiscriminant(Ray, double);
	public:
		Sphere();
		Sphere(const Vector3D&, double);

		Vector3D getCenter();
		double getRadius();

		bool rayIntersect(Ray, double);
	};
}