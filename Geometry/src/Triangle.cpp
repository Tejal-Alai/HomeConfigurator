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
Point3D Triangle::point1() const
{
    return mPoint1;
}

Point3D Triangle::point2() const
{
    return mPoint2;
}

Point3D Triangle::point3() const
{
    return mPoint3;
}

Point3D Triangle::normal() const
{
    return mNormal;
}

// Setter methods
void Triangle::setPoint1(const Point3D& inPoint)
{
    mPoint1 = inPoint;
}

void Triangle::setPoint2(const Point3D& inPoint)
{
    mPoint2 = inPoint;
}

void Triangle::setPoint3(const Point3D& inPoint)
{
    mPoint3 = inPoint;
}

void Triangle::setNormal(const Point3D& inNormal)
{
    mNormal = inNormal;
}
   