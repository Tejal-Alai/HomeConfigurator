# HomeConfigurator

## Geometry Library
This is a simple C++ geometry library that provides classes for representing 3D points, triangles, and walls. The library includes classes Point3D, Triangle, and Wall. It allows you to work with geometric entities and perform basic operations.

### Point3D Class
The Point3D class represents a point in 3D space with x, y, and z coordinates. It includes constructors, destructor, accessor functions, mutator functions, and an equality operator.

#### Constructors
+ Point3D(): Default constructor.
+ Point3D(double inX, double inY, double inZ): Constructor with specified coordinates.
#### Destructor
+ ~Point3D(): Destructor.
#### Accessor Functions
+ double x() const: Returns the x-coordinate.
+ double y() const: Returns the y-coordinate.
+ double z() const: Returns the z-coordinate.
#### Mutator Functions
+ void setX(double x): Sets the x-coordinate.
+ void setY(double y): Sets the y-coordinate.
+ void setZ(double z): Sets the z-coordinate.
#### Equality Operator
bool operator==(const Point3D& other) const: Checks if two points are equal.

### Triangle Class
The Triangle class represents a triangle in 3D space using three points. It includes constructors, destructor, accessor functions, mutator functions, and member variables for the three points and normal vector.

#### Constructors
+ Triangle(): Default constructor.
+ Triangle(const Point3D& point1, const Point3D& point2, const Point3D& point3): Constructor with three points.
#### Destructor
+ ~Triangle(): Destructor.
#### Accessor Functions
+ Point3D point1() const: Returns the first point.
+ Point3D point2() const: Returns the second point.
+ Point3D point3() const: Returns the third point.
+ Point3D normal() const: Returns the normal vector.
#### Setter Functions
+ void setPoint1(const Point3D& inPoint): Sets the first point.
+ void setPoint2(const Point3D& inPoint): Sets the second point.
+ void setPoint3(const Point3D& inPoint): Sets the third point.
+ void setNormal(const Point3D& inNormal): Sets the normal vector.

### Wall Class
The Wall class represents a wall composed of triangles in 3D space. It includes constructors, destructor, accessor functions, mutator functions, and member variables for triangles and dimensions.

#### Constructors
+ Wall(): Default constructor.
+ Wall(const Point3D& center, double sideLength): Constructor with center and side length.
#### Destructor
+ ~Wall(): Destructor.
#### Accessor Functions
+ const std::vector<Triangle>& getTriangles() const: Returns the vector of triangles.
+ double length() const: Returns the length of the wall.
+ double width() const: Returns the width of the wall.
+ double height() const: Returns the height of the wall.
#### Setters for Dimensions
+ void setLength(double length): Sets the length of the wall.
+ void setHeight(double height): Sets the height of the wall.
+ Function to Translate the Wall
void translate(double deltaX, double deltaY, double deltaZ): Translates the wall by specified deltas.

### Static Factory Methods
+ static Wall* getWall(): Creates a default wall.
+ static Wall* getWall(const Point3D& center, double sideLength): Creates a wall with specified center and side length.

### Helper Function
+ void calculateVertices(const Point3D& center, double length, double width, double height): Calculates adjusted coordinates based on center and dimensions.