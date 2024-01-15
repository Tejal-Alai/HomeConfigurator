#include "pch.h"
#include "Point3D.h"

Point3D::Point3D() : mX(0), mY(0), mZ(0)
{

}

Point3D::Point3D(double inX, double inY, double inZ)
{
    mX = inX;
    mY = inY;
    mZ = inZ;
}


Point3D::~Point3D()
{
}

// Accessor functions

double Point3D::x() const
{
    return mX;
}


double Point3D::y() const
{
    return mY;
}


double Point3D::z() const
{
    return mZ;
}

// Mutator functions

void Point3D::setX(double x) {
    mX = x;
}


void Point3D::setY(double y) {
    mY = y;
}

void Point3D::setZ(double z) {
    mZ = z;
}


bool Point3D::operator==(const Point3D& other)const
{
    return mX == other.mX && mY == other.mY && mZ == other.mZ;
}
