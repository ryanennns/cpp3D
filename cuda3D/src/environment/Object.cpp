#include "../include/Object.h"
#include "../include/Ray.h"

using namespace std;

Object::Object()
{

}

Object::Object(Object& object)
{
	for (int i = 0; i < object.surfaces.size(); i++)
	{
		this->addSurface(object.surfaces.at(i)->clone());
	}
}

Object::~Object()
{
	for (int i = 0; i < surfaces.size(); i++)
	{
		delete surfaces.at(i);
	}
}

vector<Vector3D> Object::intersections(Ray ray)
{
	vector<Vector3D> returnVector;

	for (int i = 0; i < surfaces.size(); i++)
	{
		// looks like surfaces.size experiences overflow somehow :(
		// probably not overflow, but rather a bug in the code (sure copilot thanks)
		vector<Vector3D> intersects = surfaces.at(i)->intersections(ray);
		for (int j = 0; j < intersects.size(); j++)
		{
			returnVector.push_back(intersects.at(j));
		}
	}

	return returnVector;
}

void Object::addSurface(Surface* surface)
{
	surfaces.push_back(surface);
}

void Object::transform(Vector3D translation, Vector3D rotation)
{
	for (int i = 0; i < surfaces.size(); i++)
	{
		surfaces.at(i)->transform(translation, rotation);
	}
}
