#include "pch.h"
#include "CppUnitTest.h"

#include <cmath>
#include <iomanip>

#include "include/Ray.h"
#include "include/Sphere.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EnvironmentTests
{
	TEST_CLASS(SphereTest)
	{
	public:
		TEST_METHOD(test_no_hit_detection_if_line_does_not_touch_sphere)
		{
			Sphere sphere = Sphere(Vector3D(0, 10, 0), 1);
			Ray ray = Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 1));

			std::vector<Vector3D> rayIntersections = sphere.intersections(ray);

			Assert::AreEqual((size_t)0, rayIntersections.size());
		}

		TEST_METHOD(test_multiple_hit_detection_if_line_touches_sphere_1)
		{
			Vector3D rayOrigin = Vector3D(-0.19, 1.82, 1);
			Vector3D rayDirection = Vector3D(-2.19, 3.13, 1.48);

			Sphere sphere = Sphere(Vector3D(-7.04, 5.16, 2), 1.5);

			Ray ray = Ray(rayOrigin, rayDirection);

			std::vector<Vector3D> rayIntersections = sphere.intersections(ray);

			Vector3D evaluateOne = rayIntersections.at(0);
			Vector3D evaluateTwo = rayIntersections.at(1);

			// this rounding tomfoolering is to round to two decimal places.
			Assert::AreEqual(-5.58, std::round(evaluateOne.x * 100) / 100.0);
			Assert::AreEqual(5.35, std::round(evaluateOne.y * 100) / 100.0);
			Assert::AreEqual(2.29, std::round(evaluateOne.z * 100) / 100.0);

			Assert::AreEqual(-7.28, std::round(evaluateTwo.x * 100) / 100.0);
			Assert::AreEqual(6.46, std::round(evaluateTwo.y * 100) / 100.0);
			Assert::AreEqual(2.70, std::round(evaluateTwo.z * 100) / 100.0);
		}

		TEST_METHOD(test_multiple_hit_detection_if_line_touches_sphere_2)
		{
			Vector3D rayOrigin = Vector3D(8, 3.5, 3.95);
			Vector3D rayDirection = Vector3D(3.18, -3.12, -7.48);

			Sphere sphere = Sphere(Vector3D(4.14, -3.16, -7), 0.9);

			Ray ray = Ray(rayOrigin, rayDirection);

			std::vector<Vector3D> rayIntersections = sphere.intersections(ray);

			Vector3D evaluateOne = rayIntersections.at(0);
			Vector3D evaluateTwo = rayIntersections.at(1);

			Assert::AreEqual(3.55, std::round(evaluateOne.x * 100) / 100.0);
			Assert::AreEqual(-2.61, std::round(evaluateOne.y * 100) / 100.0);
			Assert::AreEqual(-6.6, std::round(evaluateOne.z * 100) / 100.0);

			Assert::AreEqual(3.29, std::round(evaluateTwo.x * 100) / 100.0);
			Assert::AreEqual(-2.97, std::round(evaluateTwo.y * 100) / 100.0);
			Assert::AreEqual(-7.22, std::round(evaluateTwo.z * 100) / 100.0);
		}
		
		TEST_METHOD(test_it_clones_a_sphere)
		{
			Sphere sphere = Sphere(Vector3D(0, 0, 0), 1);
			Surface* clonedSphere = sphere.clone();

			Assert::IsFalse((Surface*)&sphere == clonedSphere);
			Assert::AreEqual(sphere.getCenter().x, ((Sphere*)clonedSphere)->getCenter().x);
			Assert::AreEqual(sphere.getCenter().y, ((Sphere*)clonedSphere)->getCenter().y);
			Assert::AreEqual(sphere.getCenter().z, ((Sphere*)clonedSphere)->getCenter().z);
		}

		TEST_METHOD(test_it_does_not_detect_hit_if_sphere_is_behind_ray)
		{
			Sphere sphere = Sphere(Vector3D(0, 0, 5), 1);
			Ray ray = Ray(Vector3D(0, 0, 0), Vector3D(0, 0, -1));

			std::vector<Vector3D> rayIntersections = sphere.intersections(ray);

			Assert::AreEqual((size_t)0, rayIntersections.size());
		}
		
		TEST_METHOD(test_it_translates_sphere)
		{
			Sphere sphere = Sphere(Vector3D(0, 0, 0), 1);
			Vector3D transformVector = Vector3D(1, 1, 1);

			Vector3D expectedCenter = sphere.getCenter().add(transformVector);

			sphere.transform(transformVector);

			Vector3D actualCenter = sphere.getCenter();

			Assert::AreEqual(expectedCenter.x, actualCenter.x);
			Assert::AreEqual(expectedCenter.y, actualCenter.y);
			Assert::AreEqual(expectedCenter.z, actualCenter.z);
		}
	};
}
