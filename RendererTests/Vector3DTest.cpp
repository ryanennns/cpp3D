#include "pch.h"
#include "CppUnitTest.h"
#include "components/headers/Vector3D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace components;

namespace RendererTests
{
	TEST_CLASS(Vector3DTest)
	{
	public:
		TEST_METHOD(test_it_adds_vectors)
		{
			Vector3D v1 = Vector3D(1,2,3);
			Vector3D v2 = Vector3D(4,5,6);

			Vector3D resultant = v1.add(v2);

			Assert::AreEqual(5.0, resultant.x);
			Assert::AreEqual(7.0, resultant.y);
			Assert::AreEqual(9.0, resultant.z);
		}

		TEST_METHOD(test_it_subtracts_vectors)
		{
			Vector3D v1 = Vector3D(10, 10, 10);
			Vector3D v2 = Vector3D(1, 2, 3);

			Vector3D resultant = v1.subtract(v2);

			Assert::AreEqual(9.0, resultant.x);
			Assert::AreEqual(8.0, resultant.y);
			Assert::AreEqual(7.0, resultant.z);
		}

		TEST_METHOD(test_it_multiplies_by_scalar)
		{
			Vector3D v1 = Vector3D(3, 6, 9);
			double scalar = 3;

			Vector3D resultant = v1.multiply(scalar);

			Assert::AreEqual(9.0, resultant.x);
			Assert::AreEqual(18.0, resultant.y);
			Assert::AreEqual(27.0, resultant.z);
		}

		TEST_METHOD(test_it_calculates_dot_product)
		{
			Vector3D v1 = Vector3D(10, 10, 10);
			Vector3D v2 = Vector3D(1, 2, 3);

			double resultant = v1.dotProduct(v2);

			Assert::AreEqual(60.0, resultant);
		}

		TEST_METHOD(test_it_calculates_cross_product)
		{
			Assert::AreEqual("", "todo");
		}

		TEST_METHOD(test_it_calculates_distance)
		{
			Assert::AreEqual("", "todo");
		}
	};
}
