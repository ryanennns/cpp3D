#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include "./Vector3D.cpp"

int main()
{
    Vector3D vector1(5.0, 3.0, 10.0);
    Vector3D vector2(2.0, 7.0, 1.0);
    Vector3D::debug(vector1, vector2);

    return 0;
}