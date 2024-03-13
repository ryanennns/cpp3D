#include "pch.h"
#include "CppUnitTest.h"
#include "components/headers/Ray.h"
#include "environment/resources/shapes/Sphere.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace environment;
using namespace components;

namespace RendererTests
{
	TEST_CLASS(RayTest)
	{
	public:
		TEST_METHOD(test_it_evaluates_the_ray_in_positive_direction)
		{
			double distance = 10;

			double rayDirectionX = -7.0;
			double rayDirectionY = -5.0;
			double rayDirectionZ = 4.0;

			double rayOriginX = -10.0;
			double rayOriginY = 14.0;
			double rayOriginZ = -4.0;

			Ray ray = Ray(
				Vector3D(rayOriginX, rayOriginY, rayOriginZ),
				Vector3D(rayDirectionX, rayDirectionY, rayDirectionZ)
			);

			Vector3D resultant = ray.evaluate(distance);

			Vector3D direction = ray.getB().subtract(ray.getA());

			Assert::AreEqual(rayOriginX + (direction.x * distance), resultant.x);
			Assert::AreEqual(rayOriginY + (direction.y * distance), resultant.y);
			Assert::AreEqual(rayOriginZ + (direction.z * distance), resultant.z);
		}

		TEST_METHOD(test_it_evaluates_the_ray_in_negative_direction)
		{
			double distance = -10;

			double rayDirectionX = -7.0;
			double rayDirectionY = 5.0;
			double rayDirectionZ = -4.0;

			double rayOriginX = -10.0;
			double rayOriginY = -14.0;
			double rayOriginZ = 4.0;

			Ray ray = Ray(
				Vector3D(rayOriginX, rayOriginY, rayOriginZ),
				Vector3D(rayDirectionX, rayDirectionY, rayDirectionZ)
			);

			Vector3D resultant = ray.evaluate(distance);

			Vector3D direction = ray.getB().subtract(ray.getA());

			Assert::AreEqual(rayOriginX + (direction.x * distance), resultant.x);
			Assert::AreEqual(rayOriginY + (direction.y * distance), resultant.y);
			Assert::AreEqual(rayOriginZ + (direction.z * distance), resultant.z);
		}
	};
}
