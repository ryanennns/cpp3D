#pragma once
#include "./Vector3D.h"

namespace components
{
	class Ray
	{
	private:
		Vector3D origin;
		Vector3D direction;
	public:
		Ray();
		Ray(Vector3D, Vector3D);
		Ray(Vector3D*, Vector3D*);

		Vector3D getOrigin();
		Vector3D getDirection();

		Vector3D evaluate(double);
		Ray transform(Vector3D);
	};
}