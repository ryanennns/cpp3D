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
		TEST_METHOD(test_it_detects_intersect_if_line_intersects)
		{
			Triangle triangle = Triangle(
				Vector3D(5, 0, 3),
				Vector3D(-5, 5, 3),
				Vector3D(-5, -5, 3)
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

		TEST_METHOD(test_it_does_not_return_intersect_if_line_does_not_intersect)
		{
			Triangle triangle = Triangle(
				Vector3D(-5, 2, 3),
				Vector3D(-5, 5, 3),
				Vector3D(5, 2, 3)
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

		TEST_METHOD(test_it_does_not_return_intersect_if_triangle_is_behind_origin)
		{
			Triangle triangle = Triangle(
				Vector3D(5, 0, -3),
				Vector3D(-5, 5, -3),
				Vector3D(-5, -5, -3)
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

		TEST_METHOD(test_it_translates_triangle)
		{
			Triangle triangle = Triangle(
				Vector3D(5, 0, 3),
				Vector3D(-5, 5, 3),
				Vector3D(-5, -5, 3)
			);

			Vector3D transformVector = Vector3D(1, 1, 1);


			Vector3D expectedA = triangle.getA().add(transformVector);
			Vector3D expectedB = triangle.getB().add(transformVector);
			Vector3D expectedC = triangle.getC().add(transformVector);

			triangle.transform(transformVector);
			
			Vector3D actualA = triangle.getA();
			Vector3D actualB = triangle.getB();
			Vector3D actualC = triangle.getC();

			Assert::AreEqual(expectedA.x, actualA.x);
			Assert::AreEqual(expectedA.y, actualA.y);
			Assert::AreEqual(expectedA.z, actualA.z);

			Assert::AreEqual(expectedB.x, actualB.x);
			Assert::AreEqual(expectedB.y, actualB.y);
			Assert::AreEqual(expectedB.z, actualB.z);

			Assert::AreEqual(expectedC.x, actualC.x);
			Assert::AreEqual(expectedC.y, actualC.y);
			Assert::AreEqual(expectedC.z, actualC.z);
		}

		TEST_METHOD(test_it_rotates_triangle)
		{
			Assert::AreEqual("", "TODO");
		}
	};
}
