// Cube.h
#pragma once
#include "Triangle.h"
#include <vector>

class GEOMETRY_API Cube
{
public:
	// Constructors and destructor
	Cube();
	Cube(const Point3D& center, double sideLength);
	~Cube();

	// Accessor function
	const std::vector<Triangle>& getTriangles() const;
	double getLength() const;
	double getWidth() const;
	double getHeight() const;

	// Setters for dimensions
	void setLength(double length);
	void setWidth(double width);
	void setHeight(double height);

	// Function to translate the Cube
	void translate(double deltaX, double deltaY, double deltaZ);

private:
	// Member variables
	std::vector<Triangle> mTriangles;

	// Helper function to calculate adjusted coordinates based on center and dimensions
	void calculateVertices(const Point3D& center, double length, double width, double height);
	double mLength;
	double mWidth;
	double mHeight;
};