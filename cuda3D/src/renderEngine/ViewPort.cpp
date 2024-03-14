#include "ViewPort.h"

ViewPort::ViewPort()
{
	this->eye = Vector3D(0, 0, 0);
}

vector<vector<Ray>> ViewPort::generateRays(double width, double height)
{
	vector<vector<Ray>> rays;
	double aspectRatio = width / height;
	double zOffset = 1;

	for (int y = 0; y < height; y++)
	{
		vector<Ray> newRaySet;
		rays.push_back(newRaySet);

		for (int x = 0; x < width; x++)
		{
			double normalizedX = (x + 0.5) / width;
			double normalizedY = (y + 0.5) / height;

			normalizedX = (2 * normalizedX) - 1;
			normalizedY = (2 * normalizedY) - 1;

			normalizedX *= aspectRatio;

			rays.at(y).push_back(
				Ray(this->eye, Vector3D(normalizedX, normalizedY, zOffset))
			);
		}
	}

	return rays;
}