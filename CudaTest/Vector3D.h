#pragma once

class Vector3D {
public:
    double x, y, z;

    Vector3D();
    Vector3D(Vector3D* v);
    Vector3D(double x, double y, double z);

    double magnitude();
    Vector3D* normalized();
    Vector3D* add(Vector3D* v);
    Vector3D* subtract(Vector3D* v);
    Vector3D* multiply(double scalar);
    double dotProduct(Vector3D* v);
    Vector3D* crossProduct(Vector3D* v);
    double distanceBetween(Vector3D* v);
    void consoleDisplay();

    static void debug(Vector3D v1, Vector3D v2);
};
