//#include "cuda_runtime.h"
//#include "device_launch_parameters.h"

#include <stdio.h>
#include "./src/components/headers/Ray.h"
#include "./src/environment/resources/shapes/sphere.h"

using namespace components;
using namespace environment;

int main()
{
    Sphere sphere = Sphere(Vector3D(5,5,0), 1);
    Ray ray = Ray(Vector3D(0,0,0), Vector3D(0,0,1));

    printf("Intersects: %d", sphere.rayIntersect(ray, 0));

    return 0;
}