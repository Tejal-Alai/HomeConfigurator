// Cube.cpp
#include "pch.h"
#include "Wall.h"

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

    // empty triangle
    Triangle triangle = Triangle(Point3D(), Point3D(), Point3D());


    // Front face
    triangle = Triangle(p1, p2, p3);
    triangle.setNormal(Point3D(0, -1, 0));
    mTriangles.push_back(triangle);

    triangle = Triangle(p1, p3, p4);
    triangle.setNormal(Point3D(0, -1, 0));
    mTriangles.push_back(triangle);



    // Back face
    triangle = Triangle(p5, p6, p7);
    triangle.setNormal(Point3D(0, 1, 0));
    mTriangles.push_back(triangle);

    triangle = Triangle(p5, p7, p8);
    triangle.setNormal(Point3D(0, 1, 0));
    mTriangles.push_back(triangle);



    // Left face
    triangle = Triangle(p1, p4, p8);
    triangle.setNormal(Point3D(-1, 0, 0));
    mTriangles.push_back(triangle);

    triangle = Triangle(p1, p8, p5);
    triangle.setNormal(Point3D(-1, 0, 0));
    mTriangles.push_back(triangle);



    // Right face
    triangle = Triangle(p2, p3, p7);
    triangle.setNormal(Point3D(1, 0, 0));
    mTriangles.push_back(triangle);

    triangle = Triangle(p2, p7, p6);
    triangle.setNormal(Point3D(1, 0, 0));
    mTriangles.push_back(triangle);



    // Top face
    triangle = Triangle(p4, p3, p7);
    triangle.setNormal(Point3D(0, 0, 1));
    mTriangles.push_back(triangle);

    triangle = Triangle(p4, p7, p8);
    triangle.setNormal(Point3D(0, 0, 1));
    mTriangles.push_back(triangle);



    // Bottom face
    triangle = Triangle(p1, p2, p6);
    triangle.setNormal(Point3D(0, 0, 1));
    mTriangles.push_back(triangle);

    triangle = Triangle(p1, p6, p5);
    triangle.setNormal(Point3D(0, 0, 1));
    mTriangles.push_back(triangle);



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
        double newX = triangle.point1().x() + deltaX/20.0f;
        double newY = triangle.point1().y() + deltaY / 20.0f;
        double newZ = triangle.point1().z() + deltaZ / 20.0f;
        Point3D p;
        p.setX(newX);
        p.setY(newY);
        p.setZ(newZ);
        triangle.setPoint1(p);


        // Point 2
        newX = triangle.point2().x() + deltaX / 20.0f;
        newY = triangle.point2().y() + deltaY / 20.0f;
        newZ = triangle.point2().z() + deltaZ / 20.0f;
        Point3D p1;
        p1.setX(newX);
        p1.setY(newY);
        p1.setZ(newZ);
        triangle.setPoint2(p1);

        // Point 3
        newX = triangle.point3().x() + deltaX / 20.0f;
        newY = triangle.point3().y() + deltaY / 20.0f;
        newZ = triangle.point3().z() + deltaZ / 20.0f;
        Point3D p2;
        p2.setX(newX);
        p2.setY(newY);
        p2.setZ(newZ);
        triangle.setPoint3(p2);
    }
}
