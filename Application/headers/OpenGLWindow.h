#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QMainWindow>
#include <QQuaternion>
#include <QWheelEvent>
#include "Point3D.h"

// Forward declarations
class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;


class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT

		// Signal emitted when shapes are updated
signals:
	void shapesUpdated();

public:
	// Constructor
	OpenGLWindow(const QColor& background, QMainWindow* parent);

	// Destructor
	~OpenGLWindow();

	void setVectorOfLines(QVector<GLfloat>& vectorOfLines);
	void setColorOfLines(QVector<GLfloat>& colorOfLines);
	void updateShapeData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors);
	void updateShapesData(const QVector<QVector<GLfloat>> vertices, const QVector<QVector<GLfloat>> colors);
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
	void clearScreen();

protected:
	// OpenGL initialization
	void paintGL() override;

	// OpenGL rendering
	void initializeGL() override;

private:
	// Draw a shape using specified vertices and colors
	void drawShape(QVector<GLfloat> vertices, QVector<GLfloat> colors);

	// Reset OpenGL resources
	void reset();

private:

	// List of 3D points representing the shapes
	QList<Point3D> mPoints;

	// Shader and shader program
	QOpenGLShader* mVshader = nullptr;
	QOpenGLShader* mFshader = nullptr;
	QOpenGLShaderProgram* mProgram = nullptr;

	// Vertex buffer object (VBO) for storing vertex data
	QOpenGLBuffer mVbo;

	// Attribute and uniform locations
	GLint mPosAttr = 0;
	GLint mColAttr = 0;
	GLint mMatrixUniform = 0;

	// Background color
	QColor mBackground;

	// Connection for watching OpenGL context changes
	QMetaObject::Connection mContextWatchConnection;

	// Quaternion for rotation
	QQuaternion mRotationAngle;

	// Last mouse position
	QPoint mLastPos;

	QVector3D mPanTranslationFactor;

	// Original line vertices and colors
	QVector<GLfloat> mVerticesOfOriginalLine;
	QVector<GLfloat> mColorsOfOrignalLine;

	// Current vertices and colors for rendering
	QVector<GLfloat> mVertices;
	QVector<GLfloat> mColors;

	// Lists to store vertices and colors of multiple shapes
	QVector <QVector<GLfloat>> mShapeVertices;
	QVector <QVector<GLfloat>> mShapeColors;

	// Zoom factor for handling mouse wheel events
	float mZoomFactor = 1.0f;
};