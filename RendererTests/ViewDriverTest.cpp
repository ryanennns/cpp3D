#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <include/Object.h>
#include <include/Triangle.h>
#include <include/Scene.h>
#include <include/HitDetection.h>
#include <include/Sphere.h>
#include <include/ViewDriver.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace RenderEngineTests
{
	TEST_CLASS(ViewDriverTest)
	{
	public:
		TEST_METHOD(test_it_detects_if_sphere_is_in_shadow)
		{
			Scene scene = Scene();
			Object hitScannedObject = Object();
			hitScannedObject.setColour(Rgb(255, 0, 0));
			hitScannedObject.addSurface(
				new Sphere(
					Vector3D(0, 0, 3.5),
					1
				)
			);

			scene.addObject(&hitScannedObject);

			Object intrudingObject = Object();
			intrudingObject.setColour(Rgb(0, 0, 255));
			intrudingObject.addSurface(
				new Triangle(
					Vector3D(-0.1, -0.1, 2),
					Vector3D(1, 0, 2),
					Vector3D(0, 1, 2)
				)
			);

			scene.addObject(&intrudingObject);

			ViewDriver viewDriver = ViewDriver(&scene, ViewPort(200,200));
			Light light = Light(Vector3D(0, 0, 1));

			vector<HitDetection> intersections = scene.intersections(Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 1)));

			Assert::AreEqual((size_t)3, intersections.size());

			bool isShadowed = viewDriver.isInShadow(intersections.at(0), &light);
			Assert::AreEqual(2.5, intersections.at(0).getHitPoint().z);
			Assert::IsTrue(isShadowed);
		}

		TEST_METHOD(test_it_detects_if_triangle_is_not_in_shadow)
		{
			Scene scene = Scene();
			Object hitScannedObject = Object();
			hitScannedObject.addSurface(
				new Triangle(
					Vector3D(0, 0, 3),
					Vector3D(1, 0, 3),
					Vector3D(0, 1, 3)
				)
			);

			scene.addObject(&hitScannedObject);

			Light light = Light(Vector3D(0.4, 0.4, 2));

			ViewDriver viewDriver = ViewDriver(&scene, ViewPort(200,200));

			vector<HitDetection> intersections = scene.intersections(Ray(Vector3D(0, 0, 0), Vector3D(0.1, 0.1, 1)));

			Assert::AreEqual((size_t)1, intersections.size());

			for (int i = 0; i < intersections.size(); i++)
			{
				bool isShadowed = viewDriver.isInShadow(intersections.at(i), &light);
				Assert::IsFalse(isShadowed);
			}
		}

		TEST_METHOD(test_it_detects_if_triangle_is_in_shadow)
		{
			Scene scene = Scene();
			Object hitScannedObject = Object();
			hitScannedObject.setColour(Rgb(255, 0, 0));
			hitScannedObject.addSurface(
				new Triangle(
					Vector3D(0, 0, 3),
					Vector3D(1, 0, 3),
					Vector3D(0, 1, 3)
				)
			);

			Object intrudingObject = Object();
			intrudingObject.setColour(Rgb(0, 0, 255));
			intrudingObject.addSurface(
				new Triangle(
					Vector3D(0, 0, 2.5),
					Vector3D(1, 0, 2.5),
					Vector3D(0, 1, 2.5)
				)
			);

			scene.addObject(&intrudingObject);
			scene.addObject(&hitScannedObject);

			Light light = Light(Vector3D(0.4, 0.4, 2));

			ViewDriver viewDriver = ViewDriver(&scene, ViewPort(200,200));

			vector<HitDetection> intersections = scene.intersections(Ray(Vector3D(0, 0, 0), Vector3D(0.1, 0.1, 1)));

			Assert::AreEqual((size_t)2, intersections.size());

			for (int i = 0; i < intersections.size(); i++)
			{
				bool isShadowed = viewDriver.isInShadow(intersections.at(i), &light);
				if (intersections.at(i).getColour().getRed() == 255)
				{
					Assert::IsTrue(isShadowed);
				}
				else if (intersections.at(i).getColour().getBlue() == 255)
				{
					HitDetection hd = intersections.at(i);
					Assert::IsFalse(isShadowed);
				}
			}
		}

		TEST_METHOD(test_it_detects_spheres_that_are_in_their_own_shadow)
		{
			Scene scene = Scene();

			Object object = Object();
			object.addSurface(new Sphere(Vector3D(0, 0, 3), 1));
			scene.addObject(&object);

			Light light = Light(Vector3D(0, 0, 1));
			scene.addLight(&light);

			ViewDriver viewDriver = ViewDriver(&scene, ViewPort(200,200));

			vector<HitDetection> intersections = scene.intersections(Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 1)));

			Assert::AreEqual((size_t)2, intersections.size());

			bool isShadowed = viewDriver.isInShadow(intersections.at(0), &light);
			Assert::IsFalse(isShadowed);

			isShadowed = viewDriver.isInShadow(intersections.at(1), &light);
			Assert::IsTrue(isShadowed);
		}
	};
}
