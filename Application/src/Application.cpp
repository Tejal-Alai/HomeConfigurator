#include "stdafx.h"
#include "Application.h"
#include "Cube.h"

Application::Application(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mAddWallButton, &QPushButton::clicked, this, &Application::addWall);
    connect(mLength, &QPushButton::clicked, this, &Application::changeLength);
    connect(mWidth, &QPushButton::clicked, this, &Application::changeWidth);
    connect(mHeight, &QPushButton::clicked, this, &Application::changeHeight);
    connect(mTranslateButton, &QPushButton::clicked, this, &Application::translateWall);
    connect(mResetButton, &QPushButton::clicked, this, &Application::clear);
}

Application::~Application()
{}

void Application::clear()
{
    mWallList->clear();
    mRenderer->clearScreen();
    mCubes.clear();
}

void Application::setupUi() {
    resize(1629, 836);

    mCentralWidget = new QWidget(this);
    mCentralWidget->setObjectName("centralWidget");

    //Application Title Label

    QLabel* label = new QLabel("Home Configurator", mCentralWidget);
    label->setObjectName("label");
    label->setGeometry(QRect(625, 0, 378, 45));
    QFont font;
    font.setFamilies({ QString::fromUtf8("Nirmala UI") });
    font.setPointSize(24);
    font.setBold(true);
    label->setFont(font);
    label->setLayoutDirection(Qt::LeftToRight);

    //OpenGL Window
    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(10, 60, 1521, 920));
    setWindowTitle(QCoreApplication::translate("Home Configurator", "Home Configurator", nullptr));

    //Add Wall Button
    mAddWallButton = new QPushButton("Add Wall", this);
    mAddWallButton->setGeometry(QRect(1670, 50, 80, 24));

    //Wall List
    mWallList = new QListWidget(this);
    mWallList->setGeometry(QRect(1550, 80, 331, 171));


    //Wall Index
    QLabel* labelWallIndex = new QLabel("Wall Index", mCentralWidget);
    labelWallIndex->setGeometry(QRect(1670, 290, 71, 31));

    QFont font1;
    font1.setBold(true);
    labelWallIndex->setFont(font1);
    labelWallIndex->setFrameShape(QFrame::Box);
    labelWallIndex->setFrameShadow(QFrame::Plain);
    labelWallIndex->setLineWidth(3);


    mSpinBoxWallIndex = new QSpinBox(mCentralWidget);
    mSpinBoxWallIndex->setObjectName("mSpinBoxWallIndex");
    mSpinBoxWallIndex->setGeometry(QRect(1680, 340, 51, 22));

    //Change Length
    mLength = new QPushButton("Length",this);
    mLength->setObjectName("Length");
    mLength->setGeometry(QRect(1570, 390, 80, 24));

    mDoubleSpinBoxLength = new QDoubleSpinBox(this);
    mDoubleSpinBoxLength->setObjectName("doubleSpinBoxLength");
    mDoubleSpinBoxLength->setGeometry(QRect(1580, 430, 60, 22));
    mDoubleSpinBoxLength->setMinimum(-100.0000000000000);
    mDoubleSpinBoxLength->setMaximum(100.00000000000000);

    //Change Width
    mWidth = new QPushButton("Width", this);
    mWidth->setObjectName("Width");
    mWidth->setGeometry(QRect(1685, 390, 80, 24));

    mDoubleSpinBoxWidth = new QDoubleSpinBox(this);
    mDoubleSpinBoxWidth->setObjectName("doubleSpinBoxWidth");
    mDoubleSpinBoxWidth->setGeometry(QRect(1695, 430, 60, 22));
    mDoubleSpinBoxWidth->setMinimum(-100.0000000000000);
    mDoubleSpinBoxWidth->setMaximum(100.00000000000000);
    
    //Change Height
    mHeight = new QPushButton("Height",this);
    mHeight->setObjectName("height");
    mHeight->setGeometry(QRect(1800, 390, 80, 24));

    mDoubleSpinBoxHeight = new QDoubleSpinBox(this);
    mDoubleSpinBoxHeight->setObjectName("mDoubleSpinBoxHeight");
    mDoubleSpinBoxHeight->setGeometry(QRect(1810, 430, 60, 22));
    mDoubleSpinBoxHeight->setMinimum(-100.0000000000000);
    mDoubleSpinBoxHeight->setMaximum(100.00000000000000);

    //Translate Button
    mTranslateButton = new QPushButton("Translate", this);
    mTranslateButton->setObjectName("mTranslateButton");
    mTranslateButton->setGeometry(QRect(1555, 490, 80, 24));

    //Translate by X
    QLabel* labelTranslateX = new QLabel("X :", this);
    labelTranslateX->setObjectName("label_3");
    labelTranslateX->setGeometry(QRect(1645, 485, 21, 31));

    mDoubleSpinBoxTranslateX = new QDoubleSpinBox(this);
    mDoubleSpinBoxTranslateX->setObjectName("doubleSpinBoxTranslate");
    mDoubleSpinBoxTranslateX->setGeometry(QRect(1670, 490, 60, 22));
    mDoubleSpinBoxTranslateX->setMinimum(-100.0000000000000);
    mDoubleSpinBoxTranslateX->setMaximum(100.00000000000000);

    //Translate by Y
    QLabel* labelTranslateY = new QLabel("Y :", mCentralWidget);
    labelTranslateY->setObjectName("label_3");
    labelTranslateY->setGeometry(QRect(1740, 485, 21, 31));

    mDoubleSpinBoxTranslateY = new QDoubleSpinBox(this);
    mDoubleSpinBoxTranslateY->setObjectName("doubleSpinBoxTranslate");
    mDoubleSpinBoxTranslateY->setGeometry(QRect(1760, 490, 60, 22));
    mDoubleSpinBoxTranslateY->setMinimum(-100.0000000000000);
    mDoubleSpinBoxTranslateY->setMaximum(100.00000000000000);

    //Translate by Z
    QLabel* labelTranslateZ = new QLabel("Z :", mCentralWidget);
    labelTranslateZ->setObjectName("label_3");
    labelTranslateZ->setGeometry(QRect(1830, 485, 21, 31));

    mDoubleSpinBoxTranslateZ = new QDoubleSpinBox(this);
    mDoubleSpinBoxTranslateZ->setObjectName("doubleSpinBoxTranslate");
    mDoubleSpinBoxTranslateZ->setGeometry(QRect(1850, 490, 60, 22));
    mDoubleSpinBoxTranslateZ->setMinimum(-100.0000000000000);
    mDoubleSpinBoxTranslateZ->setMaximum(100.00000000000000);

    //Reset screen
    mResetButton = new QPushButton("Reset", this);
    mResetButton->setGeometry(QRect(1660, 590, 80, 24));

    setCentralWidget(mCentralWidget);
    showMaximized();

} 

//slot to display cubes
void Application::displayCubes()
{
    mVertices.clear();
    mColors.clear();
    for (Cube cube : mCubes)
    {
        QVector<GLfloat> vertices;
        QVector<GLfloat> colors;

        const std::vector<Triangle> gt = cube.getTriangles();
        for (Triangle t : gt)
        {
            Point3D p1 = t.getPoint1();
            Point3D p2 = t.getPoint2();
            Point3D p3 = t.getPoint3();

            vertices << p1.x() << p1.y() << p1.z();
            vertices << p2.x() << p2.y() << p2.z();
            vertices << p3.x() << p3.y() << p3.z();

            colors << 1 << 1 << 1;
            colors << 1 << 1 << 1;
            colors << 1 << 1 << 1;
        }

        mVertices.push_back(vertices);
        mColors.push_back(colors);
    }
    mRenderer->updateData(mVertices, mColors);
}

//slot to add new wall
void Application::addWall()
{
    Cube c;
    mCubes.push_back(c);
    displayCubes();

    QString itemText = QString("Wall %1").arg(mCubes.size());
    QListWidgetItem* newItem = new QListWidgetItem(itemText);
    mWallList->addItem(newItem);
}

//slot to change length of wall
void Application::changeLength()
{
    double changeLength = mDoubleSpinBoxLength->value();
    int selectedIndex = mSpinBoxWallIndex->value();
    mCubes[selectedIndex].setLength(changeLength);
    displayCubes();
}

//slot to change width of wall
void Application::changeWidth()
{
    double changeWidth = mDoubleSpinBoxWidth->value();
    int selectedIndex = mSpinBoxWallIndex->value();
    mCubes[selectedIndex].setWidth(changeWidth);
    displayCubes();
}

//slot to change height of wall
void Application::changeHeight()
{
    double changeHeight = mDoubleSpinBoxHeight->value();
    int selectedIndex = mSpinBoxWallIndex->value();
    mCubes[selectedIndex].setHeight(changeHeight);
    displayCubes();
}

//slot to move wall
void Application::translateWall()
{
    double translateX = mDoubleSpinBoxTranslateX->value();
    double translateY = mDoubleSpinBoxTranslateY->value();
    double translateZ = mDoubleSpinBoxTranslateZ->value();

    int selectedIndex = mSpinBoxWallIndex->value();
    mCubes[selectedIndex].translate(translateX, translateY, translateZ);
    displayCubes();
}