#include <iostream>
#include <stdio.h>
#include <vector>

#include "Sphere.h"
#include "Vector3D.h"
#include "ViewPort.h"
#include <Ray.h>

int main(void)
{
	Sphere sphere = Sphere(Vector3D(10, 6, 7), 2);
	Sphere sphere2 = Sphere(Vector3D(0, 0, 5), 0.8);

	ViewPort viewPort = ViewPort();

	vector<vector<Ray>> rays = viewPort.generateRays(80,100);

	for (int i = 0; i < rays.size(); i++)
	{
		for (int j = 0; j < rays.at(i).size(); j++)
		{
			vector<double> intersects = sphere.rayIntersect(rays.at(i).at(j));
			vector<double> intersects2 = sphere2.rayIntersect(rays.at(i).at(j));
			if (intersects.size() == 0 && intersects2.size() == 0) {
				printf(" ");
			}
			else {
				printf(":");
			}
		}
		printf("\n");
	}
}