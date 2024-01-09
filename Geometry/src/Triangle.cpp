// Triangle.cpp
#include "pch.h"
#include "Triangle.h"

Triangle::Triangle() : mPoint1(), mPoint2(), mPoint3()
{
}

Triangle::Triangle(const Point3D& point1, const Point3D& point2, const Point3D& point3)
    : mPoint1(point1), mPoint2(point2), mPoint3(point3)
{
}

Triangle::~Triangle()
{
}

//Accessor functions
const Point3D& Triangle::getPoint1() const
{
    return mPoint1;
}

const Point3D& Triangle::getPoint2() const
{
    return mPoint2;
}

const Point3D& Triangle::getPoint3() const
{
    return mPoint3;
}

// Setter methods
void Triangle::setPoint1(const Point3D& point)
{
    mPoint1 = point;
}

void Triangle::setPoint2(const Point3D& point)
{
    mPoint2 = point;
}

void Triangle::setPoint3(const Point3D& point)
{
    mPoint3 = point;
}