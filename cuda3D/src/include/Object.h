#pragma once

#include <vector>
#include <memory>

#include "./Surface.h"
#include "./Ray.h"

class Object
{
public:
	Object();
	Object(Object&);
	~Object();
	std::vector<Vector3D> intersections(Ray ray);
	void addSurface(Surface* surface);
	void transform(Vector3D translation, Vector3D rotation = Vector3D(0,0,0));
private:
	std::vector<Surface*> surfaces;
};