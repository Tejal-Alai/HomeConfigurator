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
    const Point3D& getPoint1() const;
    const Point3D& getPoint2() const;
    const Point3D& getPoint3() const;

    // Setter functions
    void setPoint1(const Point3D& point);
    void setPoint2(const Point3D& point);
    void setPoint3(const Point3D& point);

private:
    // Member variables
    Point3D mPoint1;
    Point3D mPoint2;
    Point3D mPoint3;
};