#pragma once
#include "Triangle.h"
#include <vector>

class GEOMETRY_API Wall
{
public:
	static Wall* getWall();
	static Wall* getWall(const Point3D& center, double sideLength);
	~Wall();
private:	
	// Constructors and destructor
	Wall();
	Wall(const Point3D& center, double sideLength);
    

public:
	// Accessor function
	const std::vector<Triangle>& getTriangles() const;
	double length() const;
	double width() const;
	double height() const;

	// Setters for dimensions
	void setLength(double length);
	void setWidth(double width);
	void setHeight(double height);

	// Function to translate the Wall
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