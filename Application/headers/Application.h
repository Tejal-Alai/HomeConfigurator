#pragma once

#include <QtWidgets/QMainWindow>
#include "Application.h"
#include "OpenGLWindow.h"
#include <Qvector>
#include "Wall.h"
class OpenGLWindow;

class Application : public QMainWindow {
    Q_OBJECT

public:
    // Constructor  
    Application(QWindow* parent = nullptr);

    //Destructor
    ~Application();
   
public slots:
    // Slots for various actions
    void addWall();
    void changeLength();
    void changeWidth();
    void changeHeight();
    void translateWall();
    void clear();
    void displayCubes();
    void onTranslateXValueChanged(double newValue);
    void onTranslateYValueChanged(double newValue);
    void onTranslateZValueChanged(double newValue);
private:
    // Private function for UI
    void setupUi();

private:
    // Member variables

    // Main central widget
    QWidget* mCentralWidget;

    // OpenGL rendering window
    OpenGLWindow* mRenderer;

    // UI components
    QPushButton* mAddWallButton;
    QListWidget* mWallList;

    // Widgets for manipulating cube dimensions
    QPushButton* mLength;
    QDoubleSpinBox* mDoubleSpinBoxLength;

    QPushButton* mHeight;
    QDoubleSpinBox* mDoubleSpinBoxHeight;

    QPushButton* mWidth;
    QDoubleSpinBox* mDoubleSpinBoxWidth;
  
    // Widgets for translating walls
    QPushButton* mTranslateButton;
    QDoubleSpinBox* mDoubleSpinBoxTranslateX;
    QDoubleSpinBox* mDoubleSpinBoxTranslateY;
    QDoubleSpinBox* mDoubleSpinBoxTranslateZ;

    // Reset button
    QPushButton* mResetButton;

    // Data structures for storing cube vertices, colors, and cube objects
    QVector<QVector<GLfloat>>mVertices;
    QVector<QVector<GLfloat>>mColors;

    QVector<Cube> mCubes;

};
