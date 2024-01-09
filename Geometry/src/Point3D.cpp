#include "pch.h"
#include "Point3D.h"

// Default constructor with member initialization list
Point3D::Point3D() : mX(0), mY(0), mZ(0)
{

}

// Parameterized constructor with member initialization list
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

// Return the x-coordinate
double Point3D::x() const
{
    return mX;
}

// Return the y-coordinate
double Point3D::y() const
{
    return mY;
}

// Return the z-coordinate
double Point3D::z() const
{
    return mZ;
}

// Mutator functions

// Set the x-coordinate
void Point3D::setX(double x) {
    mX = x;
}

// Set the y-coordinate
void Point3D::setY(double y) {
    mY = y;
}

// Set the z-coordinate
void Point3D::setZ(double z) {
    mZ = z;
}

// Comparison operator for equality
bool Point3D::operator==(const Point3D& other)const
{
    return mX == other.mX && mY == other.mY && mZ == other.mZ;
}
