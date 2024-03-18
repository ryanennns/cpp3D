#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <include/Object.h>
#include <include/Triangle.h>
#include <include/Scene.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace RendererTests
{
	TEST_CLASS(SceneTest)
	{
	public:
		TEST_METHOD(test_it_returns_all_ray_intersections)
		{
			Assert::AreEqual("", "TODO");
		}

		TEST_METHOD(test_it_does_not_check_intersects_on_objects_that_are_entirely_covered)
		{
			Assert::AreEqual("", "TODO");
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

			vector<Vector3D> intersections = scene.intersections(ray);

			Assert::AreEqual(2, (int)intersections.size());
		}
	};
}
