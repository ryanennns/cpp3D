#include "../include/Vector3D.h"
#include <cmath>
#include <stdio.h>

Vector3D::Vector3D()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Vector3D::Vector3D(Vector3D* v)
{
    this->x = v->x;
    this->y = v->y;
    this->z = v->z;
}

Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector3D::magnitude()
{
    return std::sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::normalized()
{
    double magnitude = this->magnitude();

    return Vector3D(
        this->x / magnitude,
        this->y / magnitude,
        this->z / magnitude
    );
}

Vector3D Vector3D::add(const Vector3D& v)
{
    return Vector3D(
        this->x + v.x,
        this->y + v.y,
        this->z + v.z
    );
}

Vector3D Vector3D::subtract(const Vector3D& v)
{
    return Vector3D(
        this->x - v.x,
        this->y - v.y,
        this->z - v.z
    );
}

Vector3D Vector3D::multiply(double scalar)
{
    return Vector3D(
        this->x * scalar,
        this->y * scalar,
        this->z * scalar
    );
}

double Vector3D::dotProduct(const Vector3D& v)
{
    return (
        (this->x * v.x) +
        (this->y * v.y) +
        (this->z * v.z)
    );
}

Vector3D Vector3D::crossProduct(const Vector3D& v)
{
    return Vector3D(
        (this->y * v.z) - (this->z * v.y),
        (this->x * v.z) - (this->z * v.x),
        (this->x * v.y) - (this->y * v.x)
    );
}

double Vector3D::distanceBetween(const Vector3D& v)
{
    double x = v.x - this->x;
    double y = v.y - this->y;
    double z = v.z - this->z;

    return std::sqrt(x * x + y * y + z * z);
}

void Vector3D::consoleDisplay()
{
    printf("(%lf, %lf, %lf)\n", this->x, this->y, this->z);
}

// right now this thing pisses memory EVERYWHERE lol
void Vector3D::debug(Vector3D v1, Vector3D v2)
{
    printf("Testing Vectors\n");
    v1.consoleDisplay();
    v2.consoleDisplay();

    printf("\n");

    printf("Magnitude:\n");
    printf("V1:\t%lf\n", v1.magnitude());
    printf("V2:\t%lf\n", v2.magnitude());

    printf("Adding V1 + V2\n");
    Vector3D sum = v1.add(&v2);
    printf("(%lf, %lf, %lf)\n", sum.x, sum.y, sum.z);

    printf("Multiplying V1 * 5\n");
    v1.consoleDisplay();
    printf("\n");
    v1.multiply(5).consoleDisplay();
    printf("\n");

    printf("Normalized Magnitude (Expects 1.0):\n");
    printf("V1:\t%lf\n", v1.normalized().magnitude());
    printf("V2:\t%lf\n\n", v2.normalized().magnitude());

    printf("Dot Product:\n");
    printf("V1 . V2 = %lf\n\n", v1.dotProduct(&v2));

    printf("Cross Product:\n");
    Vector3D cross = v1.crossProduct(&v2);
    cross.consoleDisplay();
    printf("\n");
}