#include "pch.h"
#include "CppUnitTest.h"

#include <vector>

#include "include/Triangle.h"
#include "include/Vector3D.h"
#include "include/Ray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace RendererTests
{
	TEST_CLASS(TriangleTest)
	{
	public:
		TEST_METHOD(test_it_detects_intersects_if_line_intersects)
		{
			Triangle triangle = Triangle(
				Vector3D(-5, -5, 3),
				Vector3D(-5, 5, 3),
				Vector3D(5, 0, 3)
			);

			Ray ray = Ray(
				Vector3D(0, 0, 0),
				Vector3D(0, 0, 1)
			);

			vector<double> intersections = triangle.intersections(ray);

			size_t expected = 1;
			size_t actual = intersections.size();

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_it_does_not_intersect_if_line_does_not_intersect)
		{
			Triangle triangle = Triangle(
				Vector3D(-5, 1, 3),
				Vector3D(-5, 5, 3),
				Vector3D(5, 1, 3)
			);

			Ray ray = Ray(
				Vector3D(0, 0, 0),
				Vector3D(0, 0, 1)
			);

			vector<double> intersections = triangle.intersections(ray);

			size_t expected = 0;
			size_t actual = intersections.size();

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_it_detects_perpendicularity_to_triangle_normal)
		{
			Assert::AreEqual("", "TODO");
		}
	};
}
