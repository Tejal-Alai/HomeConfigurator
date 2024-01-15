// Triangle.h
#pragma once
#include "Point3D.h"

class GEOMETRY_API Triangle
{

public:
    // Constructors and destructor
    Triangle();
    Triangle(const Point3D& point1, const Point3D& point2, const Point3D& point3);
    ~Triangle();

    // Accessor functions
    Point3D point1() const;
    Point3D point2() const;
    Point3D point3() const;
    Point3D normal() const;

    // Setter functions
    void setPoint1(const Point3D& inPoint);
    void setPoint2(const Point3D& inPoint);
    void setPoint3(const Point3D& inPoint);
    void setNormal(const Point3D& inNormal);

private:
    // Member variables
    Point3D mPoint1;
    Point3D mPoint2;
    Point3D mPoint3;
    Point3D mNormal;
};