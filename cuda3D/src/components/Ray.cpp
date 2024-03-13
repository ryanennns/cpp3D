#include "./headers/Ray.h"

namespace components
{
	Ray::Ray()
	{
		this->origin = Vector3D(0,0,0);
		this->direction = Vector3D(1,0,0);
	}

	Ray::Ray(Vector3D origin, Vector3D direction)
	{
		this->origin = origin;
		this->direction = direction;
	}

	Ray::Ray(Vector3D* origin, Vector3D* direction)
	{
		this->origin = Vector3D(origin);
		this->direction = Vector3D(direction);
	}

	Vector3D Ray::getOrigin()
	{
		return this->origin;
	}

	Vector3D Ray::getDirection()
	{
		return this->direction;
	}

	Vector3D Ray::evaluate(double t)
	{
		return this->origin.add(this->direction.multiply(t));
	}

	Ray Ray::transform(Vector3D v)
	{
		return Ray(this->origin.add(v), this->direction.add(v));
	}
}