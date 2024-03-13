#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include "./components/headers/Ray.h"

using namespace components;

int main()
{
    Vector3D v1 = Vector3D(0, 0, 0);
    Vector3D v2 = Vector3D(1, 2, 3);
    Ray ray = Ray(v1, v2);

    Vector3D resultant = ray.evaluate(5);

    printf("Resultant:\n\tx: %lf\n\ty: %lf\n\tz: %lf", resultant.x, resultant.y, resultant.z);

    return 0;
}