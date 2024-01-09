// Cube.cpp
#include "pch.h"
#include "Cube.h"

Cube::Cube() : mTriangles()
{
    // Default cube with side length 1.0 centered at the origin
    calculateVertices(Point3D(0, 0, 0), 1.0, 1.0, 1.0);
}

Cube::Cube(const Point3D& center, double sideLength) : mTriangles()
{
    calculateVertices(center, sideLength, sideLength, sideLength);
}

Cube::~Cube()
{
}

const std::vector<Triangle>& Cube::getTriangles() const
{
    return mTriangles;
}

void Cube::calculateVertices(const Point3D& center, double length, double width, double height)
{
    // Calculate half of the dimensions for convenience
    mTriangles.clear();
    double halfLength = length / 2.0;
    double halfWidth = width / 2.0;
    double halfHeight = height / 2.0;

    // Calculate adjusted coordinates based on center and dimensions
    Point3D p1(center.x() - halfLength, center.y() - halfWidth, center.z() - halfHeight);
    Point3D p2(center.x() + halfLength, center.y() - halfWidth, center.z() - halfHeight);
    Point3D p3(center.x() + halfLength, center.y() - halfWidth, center.z() + halfHeight);
    Point3D p4(center.x() - halfLength, center.y() - halfWidth, center.z() + halfHeight);

    Point3D p5(center.x() - halfLength, center.y() + halfWidth, center.z() - halfHeight);
    Point3D p6(center.x() + halfLength, center.y() + halfWidth, center.z() - halfHeight);
    Point3D p7(center.x() + halfLength, center.y() + halfWidth, center.z() + halfHeight);
    Point3D p8(center.x() - halfLength, center.y() + halfWidth, center.z() + halfHeight);

    // Front face
    mTriangles.push_back(Triangle(p1, p2, p3));
    mTriangles.push_back(Triangle(p1, p3, p4));

    // Back face
    mTriangles.push_back(Triangle(p5, p6, p7));
    mTriangles.push_back(Triangle(p5, p7, p8));

    // Left face
    mTriangles.push_back(Triangle(p1, p4, p8));
    mTriangles.push_back(Triangle(p1, p8, p5));

    // Right face
    mTriangles.push_back(Triangle(p2, p3, p7));
    mTriangles.push_back(Triangle(p2, p7, p6));

    // Top face
    mTriangles.push_back(Triangle(p4, p3, p7));
    mTriangles.push_back(Triangle(p4, p7, p8));

    // Bottom face
    mTriangles.push_back(Triangle(p1, p2, p6));
    mTriangles.push_back(Triangle(p1, p6, p5));

    // Update member variables
    mLength = length;
    mWidth = width;
    mHeight = height;
}

void Cube::setLength(double length)
{
    // Recalculate vertices with the new length
    calculateVertices(Point3D(0, 0, 0), length, getWidth(), getHeight());
}

void Cube::setWidth(double width)
{
    // Recalculate vertices with the new width
    calculateVertices(Point3D(0, 0, 0), getLength(), width, getHeight());
}

void Cube::setHeight(double height)
{
    // Recalculate vertices with the new height
    calculateVertices(Point3D(0, 0, 0), getLength(), getWidth(), height);
}

double Cube::getLength() const
{
    return mLength;
}

double Cube::getWidth() const
{
    return mWidth;
}

double Cube::getHeight() const
{
    return mHeight;
}



void Cube::translate(double deltaX, double deltaY, double deltaZ)
{
    // Translate all vertices by the specified deltas
    for (Triangle& triangle : mTriangles) {
        // Point 1
        double newX = triangle.getPoint1().x() + deltaX;
        double newY = triangle.getPoint1().y() + deltaY;
        double newZ = triangle.getPoint1().z() + deltaZ;
        Point3D p;
        p.setX(newX);
        p.setY(newY);
        p.setZ(newZ);
        triangle.setPoint1(p);


        // Point 2
        newX = triangle.getPoint2().x() + deltaX;
        newY = triangle.getPoint2().y() + deltaY;
        newZ = triangle.getPoint2().z() + deltaZ;
        Point3D p1;
        p1.setX(newX);
        p1.setY(newY);
        p1.setZ(newZ);
        triangle.setPoint2(p1);

        // Point 3
        newX = triangle.getPoint3().x() + deltaX;
        newY = triangle.getPoint3().y() + deltaY;
        newZ = triangle.getPoint3().z() + deltaZ;
        Point3D p2;
        p2.setX(newX);
        p2.setY(newY);
        p2.setZ(newZ);
        triangle.setPoint3(p2);
    }
}
