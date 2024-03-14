#pragma once

#include <vector>
#include "../include/Vector3D.h"
#include "../include/Ray.h"

using namespace std;

class ViewPort
{
private:
	Vector3D eye;

	vector<vector<Ray>> generateRays(double width, double height);
public:
	ViewPort();
};