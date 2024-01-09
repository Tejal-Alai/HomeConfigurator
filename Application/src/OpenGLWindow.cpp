#include "stdafx.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include "OpenGLWindow.h"
#include "Cube.h"

// Constructor definition
OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
	mBackground(background)
{
	setParent(parent);
	setMinimumSize(300, 250);
}

// Destructor definition
OpenGLWindow::~OpenGLWindow()
{
	reset();
}

// Set the vector of lines for the original line
void OpenGLWindow::setVectorOfLines(QVector<GLfloat>& vectorOfLines)
{
	mVerticesOfOriginalLine = vectorOfLines;
}

// Set the color of lines for the original line
void OpenGLWindow::setColorOfLines(QVector<GLfloat>& colorOfLines)
{
	mColorsOfOrignalLine = colorOfLines;
}

// Update data for rendering a single shape
void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors)
{
	this->mVertices = vertices;
	this->mColors = colors;
	update();
}

// Update data for rendering multiple shapes
void OpenGLWindow::updateData(const QVector<QVector<GLfloat>> vertices, const QVector<QVector<GLfloat>> colors)
{
	mShapeVertices = vertices;
	mShapeColors = colors;
	update();
}

// Handle mouse move events for rotation
void OpenGLWindow::mouseMoveEvent(QMouseEvent* event) {
	int dx = event->x() - mLastPos.x();
	int dy = event->y() - mLastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		QQuaternion rotX = QQuaternion::fromAxisAndAngle(0.0f, 1.0f, 0.0f, 0.5f * dx);
		QQuaternion rotY = QQuaternion::fromAxisAndAngle(1.0f, 0.0f, 0.0f, 0.5f * dy);

		mRotationAngle = rotX * rotY * mRotationAngle;
		update();
	}
	mLastPos = event->pos();
}

// Handle mouse wheel events for zooming
void OpenGLWindow::wheelEvent(QWheelEvent* event)
{
	int delta = event->angleDelta().y();

	if (delta > 0) {

		mZoomFactor *= 1.1f;
	}
	else {
		mZoomFactor /= 1.1f;
	}
	update();
}

// Clear the screen and update the view
void OpenGLWindow::clearScreen()
{
	mShapeVertices.clear();
	mShapeColors.clear();
	update();
}

// Draw a shape using specified vertices and colors
void OpenGLWindow::drawShape(QVector<GLfloat> vertices, QVector<GLfloat> colors) {
	glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices.data());
	glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors.data());

	glEnableVertexAttribArray(m_posAttr);
	glEnableVertexAttribArray(m_colAttr);

	glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);

	glDisableVertexAttribArray(m_posAttr);
	glDisableVertexAttribArray(m_colAttr);
}

// Render the scene
void OpenGLWindow::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT);

	mProgram->bind();

	QMatrix4x4 matrix;
	matrix.rotate(mRotationAngle);
	matrix.ortho(-3.0f, 3.0f, -3.0f, 3.0f, -3.0f, 3.0f);
	matrix.translate(0, 0, -2);
	matrix.scale(mZoomFactor);

	mProgram->setUniformValue(m_matrixUniform, matrix);

	GLfloat* verticesData = mVerticesOfOriginalLine.data();
	GLfloat* colorsData = mColorsOfOrignalLine.data();

	// Draw multiple shapes
	for (int i = 0; i < mShapeVertices.size(); i++) {
		drawShape(mShapeVertices[i], mShapeColors[i]);
	}
}

// Initialize OpenGL settings and shaders
void OpenGLWindow::initializeGL() {
	static const char* vertexShaderSource =
		"attribute highp vec4 posAttr;\n"
		"attribute lowp vec4 colAttr;\n"
		"varying lowp vec4 col;\n"
		"uniform highp mat4 matrix;\n"
		"void main() {\n"
		"   col = colAttr;\n"
		"   gl_Position = matrix * posAttr;\n"
		"}\n";

	static const char* fragmentShaderSource =
		"varying lowp vec4 col;\n"
		"void main() {\n"
		"   gl_FragColor = col;\n"
		"}\n";

	initializeOpenGLFunctions();
	setMouseTracking(true);

	mProgram = new QOpenGLShaderProgram(this);
	mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	mProgram->link();
	m_posAttr = mProgram->attributeLocation("posAttr");
	Q_ASSERT(m_posAttr != -1);
	m_colAttr = mProgram->attributeLocation("colAttr");
	Q_ASSERT(m_colAttr != -1);
	m_matrixUniform = mProgram->uniformLocation("matrix");
	Q_ASSERT(m_matrixUniform != -1);
}

// Reset OpenGL resources
void OpenGLWindow::reset() {
	makeCurrent();
	delete mProgram;
	mProgram = nullptr;
	delete mVshader;
	mVshader = nullptr;
	delete mFshader;
	mFshader = nullptr;
	mVbo.destroy();
	doneCurrent();

	QObject::disconnect(mContextWatchConnection);
}















