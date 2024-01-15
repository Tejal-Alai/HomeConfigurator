# HomeConfigurator

# Application 

This application allows users to add walls, change their dimensions, translate them, and visualize the walls in a 3D rendering window.

## Overview
The project is structured into three main components:

### Point3D Class
 Represents a 3D point with x, y, and z coordinates. It is utilized in defining the geometry of shapes.

### OpenGLWindow Class
 Inherits from QOpenGLWidget and provides the rendering window for displaying 3D shapes. It includes functionalities for updating and rendering shapes using OpenGL. Users can manipulate the view through mouse movements and zoom.

### Application Class
 Inherits from QMainWindow and serves as the main application window. It includes UI components for adding walls, changing dimensions, translating walls, and resetting the view.

## Classe
### Point3D Class
The Point3D class represents a point in 3D space. It includes constructors, destructor, accessor functions, and mutator functions for x, y, and z coordinates.

### OpenGLWindow Class
The OpenGLWindow class provides the rendering window for 3D shapes. It includes functions for handling OpenGL initialization, rendering, and mouse events. Users can interact with the 3D view by adding walls, changing dimensions, and translating walls.

### Application Class
The Application class is the main application window. It includes UI components for adding walls, changing dimensions, translating walls, and resetting the view. Users can interact with the application through buttons, spin boxes, and a list widget.

## Usage
+ Adding Walls: Click the "Add Wall" button to add a wall to the scene.

+ Changing Dimensions: Use the spin boxes to change the length, width, and height of the selected wall.

+ Translating Walls: Adjust the translation values using the spin boxes to move the selected wall in the x, y, or z direction.

+ Clearing the Scene: Click the "Clear" button to remove all walls from the scene.

+ Displaying Walls: Click the "Display Walls" button to visualize the walls in the OpenGL rendering window.

+ Resetting the View: Click the "Reset" button to reset the view to its default state.

## Dependencies
Qt Framework
OpenGL