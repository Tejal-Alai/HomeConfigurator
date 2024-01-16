#pragma once
#include "pch.h"

class GEOMETRY_API Point3D
{
public:

    //constructors and destructors
    Point3D();
    Point3D(double inX, double inY, double inZ);
    ~Point3D();

    //Accessor Functions

    double x() const;
    double y() const;
    double z() const;

    //Mutator Functions 

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    bool operator == (const Point3D& other) const;

private:

    //Member functions

    double mX;
    double mY;
    double mZ;
};

