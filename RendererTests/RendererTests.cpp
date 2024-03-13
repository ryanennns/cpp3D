#include "pch.h"
#include "CppUnitTest.h"
#include "components/headers/Ray.h"
#include "environment/resources/shapes/Sphere.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace environment;
using namespace components;

namespace RendererTests
{
	TEST_CLASS(SphereIntersectTest)
	{
	public:
		TEST_METHOD(test_hit_detection_if_line_touches_sphere)
		{
			Sphere sphere = Sphere(Vector3D(3, 0, 0), 1);
			Ray ray = Ray(Vector3D(0, 0, 0), Vector3D(1, 0, 0));

			Assert::IsTrue(sphere.rayIntersect(ray, 10));
		}

		TEST_METHOD(test_no_hit_detection_if_line_does_not_touch_sphere)
		{
			Sphere sphere = Sphere(Vector3D(3, 0, 0), 1);
			Ray ray = Ray(Vector3D(0, 0, 0), Vector3D(1, 0, 0));

			Assert::IsFalse(sphere.rayIntersect(ray, 1));
		}
	};
}
