#include "pch.h"
#include "Wall.h"

Wall* Wall::getWall()
{
    Wall* wall = new Wall();
    return wall;
}

Wall* Wall::getWall(const Point3D& center, double sideLength)
{
    Wall* wall = new Wall(center, sideLength);
    return wall;
}

Wall::Wall() : mTriangles()
{
    // Default wall with side length 1.0 centered at the origin
    calculateVertices(Point3D(0, 0, 0), 1.0, 1.0, 1.0);
}

Wall::Wall(const Point3D& center, double sideLength) : mTriangles()
{
    calculateVertices(center, sideLength, sideLength, sideLength);
}

Wall::~Wall()
{
}

const std::vector<Triangle>& Wall::getTriangles() const
{
    return mTriangles;
}

void Wall::calculateVertices(const Point3D& center, double length, double width, double height)
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

void Wall::setLength(double length)
{
    // Recalculate vertices with the new length
    calculateVertices(Point3D(0, 0, 0), length, width(), height());
}

void Wall::setWidth(double width)
{
    // Recalculate vertices with the new width
    calculateVertices(Point3D(0, 0, 0), length(), width, height());
}

void Wall::setHeight(double height)
{
    // Recalculate vertices with the new height
    calculateVertices(Point3D(0, 0, 0), length(), width(), height);
}

double Wall::length() const
{
    return mLength;
}

double Wall::width() const
{
    return mWidth;
}

double Wall::height() const
{
    return mHeight;
}

void Wall::translate(double deltaX, double deltaY, double deltaZ)
{
    // Translate all vertices by the specified deltas
    for (Triangle& triangle : mTriangles) {

        // Point 1
        double newX = triangle.point1().x() + deltaX/20.0f;
        double newY = triangle.point1().y() + deltaY / 20.0f;
        double newZ = triangle.point1().z() + deltaZ / 20.0f;
        Point3D point1;
        point1.setX(newX);
        point1.setY(newY);
        point1.setZ(newZ);
        triangle.setPoint1(point1);

        // Point 2
        newX = triangle.point2().x() + deltaX / 20.0f;
        newY = triangle.point2().y() + deltaY / 20.0f;
        newZ = triangle.point2().z() + deltaZ / 20.0f;
        Point3D point2;
        point2.setX(newX);
        point2.setY(newY);
        point2.setZ(newZ);
        triangle.setPoint2(point2);

        // Point 3
        newX = triangle.point3().x() + deltaX / 20.0f;
        newY = triangle.point3().y() + deltaY / 20.0f;
        newZ = triangle.point3().z() + deltaZ / 20.0f;
        Point3D point3;
        point3.setX(newX);
        point3.setY(newY);
        point3.setZ(newZ);
        triangle.setPoint3(point3);
    }
}
