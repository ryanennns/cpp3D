#include "pch.h"
#include "CppUnitTest.h"

#include "include/Object.h"
#include "include/Triangle.h"
#include "include/Sphere.h"
#include "include/RaySurfaceIntersection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RendererTests
{
	TEST_CLASS(ObjectTest)
	{
	public:
		TEST_METHOD(test_it_detects_all_ray_intersections_in_object)
		{
			Object object = Object();
			object.addSurface(new Sphere(Vector3D(0, 0, 5), 1));
			object.addSurface(new Triangle(
				Vector3D(5, 0, 3),
				Vector3D(-5, 5, 3),
				Vector3D(-5, -5, 3)
			));

			Ray ray = Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 1));

			std::vector<RaySurfaceIntersection> intersections = object.intersections(ray);

			Assert::AreEqual((size_t)3, intersections.size());
		}

		//todo object translate test
		//TEST_METHOD(test_it_translates_all_surfaces_in_object)
		//{
		//	Object object = Object();
		//	object.addSurface(new Sphere(Vector3D(0, 0, 5), 1));
		//	object.addSurface(new Triangle(
		//		Vector3D(5, 0, 3),
		//		Vector3D(-5, 5, 3),
		//		Vector3D(-5, -5, 3)
		//	));
		//
		//	object.translate(Vector3D(1, 1, 1));
		//}
	};
}
