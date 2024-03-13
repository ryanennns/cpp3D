#pragma once

#include "../../../components/headers/Vector3D.h"
#include "../../../components/headers/Ray.h"
#include <vector>

using namespace components;

namespace environment
{
	class Sphere
	{
	private:
		Vector3D center;
		double radius;

		double intersectDiscriminant(Ray);
	public:
		Sphere();
		Sphere(const Vector3D&, double);

		Vector3D getCenter();
		double getRadius();

		std::vector<double> rayIntersect(Ray);
	};
}