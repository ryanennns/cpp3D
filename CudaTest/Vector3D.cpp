#include <cmath>
#include <stdio.h>

class Vector3D
{
public:
    double x;
    double y;
    double z;

    Vector3D()
    {
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
    }

    Vector3D(Vector3D* v)
    {
        this->x = v->x;
        this->y = v->y;
        this->z = v->z;
    }

    Vector3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double magnitude()
    {
        return std::sqrt(x*x + y*y + z*z);
    }

    Vector3D* normalized()
    {
        double magnitude = this->magnitude();

        return new Vector3D(
            this->x / magnitude,
            this->y / magnitude,
            this->z / magnitude
        );
    }

    Vector3D* add(Vector3D* v)
    {
        this->x = this->x + v->x;
        this->y = this->y + v->y;
        this->z = this->z + v->z;

        return this;
    }

    Vector3D* subtract(Vector3D* v)
    {
        this->x = this->x - v->x;
        this->y = this->y - v->y;
        this->z = this->z - v->z;

        return this;
    }

    Vector3D* multiply(double scalar)
    {
        this->x = this->x * scalar; 
        this->y = this->y * scalar; 
        this->z = this->z * scalar; 
    
        return this;
    }

    double dotProduct(Vector3D* v)
    {
        return (
            (this->x * v->x) +
            (this->y * v->y) +
            (this->z * v->z)
        );
    }

    Vector3D* crossProduct(Vector3D* v)
    {
        return new Vector3D(
            (this->y * v->z) - (this->z * v->y),
            (this->x * v->z) - (this->z * v->x),
            (this->x * v->y) - (this->y * v->x)
        );
    }

    double distanceBetween(Vector3D* v)
    {
        double x = v->x - this->x;
        double y = v->y - this->y;
        double z = v->z - this->z;
        
        return std::sqrt(x*x + y*y + z*z);
    }

    void consoleDisplay()
    {
        printf("(%lf, %lf, %lf)\n", this->x, this->y, this->z);
    }

    // right now this thing pisses memory EVERYWHERE lol
    static void debug(Vector3D v1, Vector3D v2)
    {
        printf("Testing Vectors\n");
        v1.consoleDisplay();
        v2.consoleDisplay();

        printf("\n");

        printf("Magnitude:\n");
        printf("V1:\t%lf\n", v1.magnitude());
        printf("V2:\t%lf\n", v2.magnitude());

        printf("Adding V1 + V2\n");
        v1.add(&v2);
        printf("(%lf, %lf, %lf)\n", v1.x, v1.y, v1.z);

        printf("Multiplying V1 * 5\n");
        v1.consoleDisplay();
        printf("\n");
        v1.multiply(5)->consoleDisplay();
        printf("\n");

        printf("Normalized Magnitude (Expects 1.0):\n");
        printf("V1:\t%lf\n", v1.normalized()->magnitude());
        printf("V2:\t%lf\n\n", v2.normalized()->magnitude());

        printf("Dot Product:\n");
        printf("V1 . V2 = %lf\n\n", v1.dotProduct(&v2));

        printf("Cross Product:\n");
        Vector3D* cross = v1.crossProduct(&v2);
        cross->consoleDisplay();
        printf("\n");
    }
};