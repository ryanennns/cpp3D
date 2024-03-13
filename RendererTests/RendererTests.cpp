#include "pch.h"
#include "CppUnitTest.h"
#include "../CudaTest/environment/resources/shapes/Sphere.h"
#include "../CudaTest/components/headers/Ray.h"
#include "../CudaTest/components/headers/Vector3D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace components;
using namespace environment;

namespace RendererTests
{
	TEST_CLASS(RendererTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Sphere sphere = Sphere(Vector3D(5, 5, 0), 1);
			Ray ray = Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 1));

			Assert::IsFalse(sphere.rayIntersect(ray, 10));
		}
	};
}
