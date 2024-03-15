#include <iostream>
#include <stdio.h>
#include <vector>

#include "Sphere.h"
#include "Vector3D.h"
#include "ViewPort.h"
#include "Ray.h"
#include "Rgb.h"
#include "Triangle.h"
#include "Object.h"

//int main(void)
//{
//	Object object = Object();
//
//	object.addSurface(
//		new Triangle(
//			Vector3D(-5, -5, 10),
//			Vector3D(5, 0, 5),
//			Vector3D(-5, 3, 5)
//		)
//	);
//
//	//Triangle* t = new Triangle(
//	//	Vector3D(0, 1, 10),
//	//	Vector3D(0, 0, 10),
//	//	Vector3D(0, 2 , 10)
//	//);
//	//t->transform(Vector3D(-10, 0, 0));
//	//object.addSurface(t);
//
//	ViewPort viewPort = ViewPort(100, 50);
//
//	vector<vector<Ray>> rays = viewPort.getRays();
//
//	for (int i = 0; i < rays.size(); i++)
//	{
//		for (int j = 0; j < rays.at(i).size(); j++)
//		{
//			vector<double> intersects = object.intersections(rays.at(i).at(j));
//			if (intersects.size() == 0) {
//				printf(" ");
//			}
//			else {
//				printf("+");
//			}
//		}
//		printf("\n");
//	}
//}