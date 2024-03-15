#include "../include/Object.h"
#include "../include/Ray.h"

using namespace std;

Object::Object()
{
}

Object::~Object()
{
	for (int i = 0; i < surfaces.size(); i++)
	{
		delete surfaces.at(i);
	}
}

vector<double> Object::intersections(Ray ray)
{
	vector<double> returnVector;

	for (int i = 0; i < surfaces.size(); i++)
	{
		vector<double> intersects = surfaces.at(i)->intersections(ray);
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
