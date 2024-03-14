#pragma once

#include <vector>
#include "../components/headers/Vector3D.h"
#include "../components/headers/Ray.h"

using namespace std;
using namespace components;

class ViewPort
{
private:
	Vector3D eye;

	vector<vector<Ray>> generateRays(double width, double height);
public:
	ViewPort();
};