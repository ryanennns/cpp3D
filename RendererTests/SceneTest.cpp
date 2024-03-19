#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <include/Object.h>
#include <include/Triangle.h>
#include <include/Scene.h>
#include <include/HitDetection.h>
#include <include/Sphere.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace EnvironmentTests
{
	TEST_CLASS(SceneTest)
	{
	public:
		TEST_METHOD(test_it_detects_all_ray_intersections_across_multiple_objects_in_a_scene)
		{
			Object object1 = Object();

			object1.addSurface(new Sphere(Vector3D(0, 0, 5), 1));

			object1.addSurface(new Triangle(
				Vector3D(5, 0, 3),
				Vector3D(-5, 5, 3),
				Vector3D(-5, -5, 3)
			));

			Object object2 = Object();

			object2.addSurface(new Triangle(
				Vector3D(5, 0, 5),
				Vector3D(-5, 5, 5),
				Vector3D(-5, -5, 5)
			));

			object2.addSurface(new Triangle(
				Vector3D(5, 0, 7),
				Vector3D(-5, 5, 7),
				Vector3D(-5, -5, 7)
			));

			Ray ray = Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 1));

			Scene scene = Scene();
			scene.addObject(&object1);
			scene.addObject(&object2);

			vector<HitDetection> intersections = scene.intersections(ray);

			Assert::AreEqual(5, (int)intersections.size());
		}

		TEST_METHOD(test_it_can_get_intersections_from_all_objects)
		{
			Object object = Object();

			object.addSurface(new Triangle(
				Vector3D(5, 0, 3),
				Vector3D(-5, 5, 3),
				Vector3D(-5, -5, 3)
			));

			object.addSurface(new Triangle(
				Vector3D(5, 0, 2),
				Vector3D(-5, 5, 2),
				Vector3D(-5, -5, 2)
			));

			Ray ray = Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 1));

			Scene scene = Scene();
			scene.addObject(&object);

			vector<HitDetection> intersections = scene.intersections(ray);

			Assert::AreEqual(2, (int)intersections.size());
		}
	};
}
