#include <iostream>
#include <stdio.h>
#include <vector>

#include "Sphere.h"
#include "Vector3D.h"
#include "ViewPort.h"
#include "Ray.h"
#include "Rgb.h"
#include "Triangle.h"

int main(void)
{
	// the same sort of console demo test harness, except with a triangle about 5units in front of the camera.

	Triangle triangle = Triangle(
		Vector3D(5, 0, 10),
		Vector3D(-5, 5, 10),
		Vector3D(-5, -5, 10)
	);

	ViewPort viewPort = ViewPort(200, 50);

	vector<vector<Ray>> rays = viewPort.getRays();

	for (int i = 0; i < rays.size(); i++)
	{
		for (int j = 0; j < rays.at(i).size(); j++)
		{
			vector<double> intersects = triangle.intersections(rays.at(i).at(j));
			if (intersects.size() == 0) {
				printf(" ");
			}
			else {
				printf(":");
			}
		}
		printf("\n");
	}
}