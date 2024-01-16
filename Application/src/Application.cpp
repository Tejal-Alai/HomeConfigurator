#include "stdafx.h"
#include "Application.h"
#include "Wall.h"

Application::Application(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mAddWallButton, &QPushButton::clicked, this, &Application::addWall);
    connect(mDoubleSpinBoxLength, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Application::changeLength);
    connect(mDoubleSpinBoxWidth, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Application::changeWidth);
    connect(mDoubleSpinBoxHeight, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Application::changeHeight);
    connect(mDoubleSpinBoxTranslateX, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Application::onTranslateXValueChanged);
    connect(mDoubleSpinBoxTranslateY, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Application::onTranslateYValueChanged);
    connect(mDoubleSpinBoxTranslateZ, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Application::onTranslateZValueChanged);
    connect(mResetButton, &QPushButton::clicked, this, &Application::clear);
}

Application::~Application()
{

}

void Application::clear()
{
    mWallList->clear();
    mRenderer->clearScreen();
    mWalls.clear();
}

void Application::setupUi() {
    resize(1629, 836);

    mCentralWidget = new QWidget(this);

    //OpenGL Window
    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(10, 60, 1521, 920));
    setWindowTitle(QCoreApplication::translate("Home Configurator", "Home Configurator", nullptr));

    //Add Wall Button
    mAddWallButton = new QPushButton("Add Wall", this);
    mAddWallButton->setGeometry(QRect(1670, 50, 80, 24));
    mAddWallButton->setStyleSheet("QPushButton {"
      "   background-color: #9b59b6;"  // Purple background
    "   color: white;"               // White text
    "   border: 1px solid #9b59b6;"  // Purple border
    "}"
    "QPushButton:hover {"
    "   background-color: #8e44ad;"  // Darker purple on hover
    "}");

    //Wall List
    mWallList = new QListWidget(this);
    mWallList->setGeometry(QRect(1550, 80, 331,240));

    //Modify label
    QLabel* mModifyLabel = new QLabel("Modify", this);

    mModifyLabel->setGeometry(QRect(1670, 330, 80, 24));

    // Set text alignment to center

    mModifyLabel->setAlignment(Qt::AlignCenter);

    mModifyLabel->setStyleSheet("QLabel {"

        "   background-color:  #2ecc71;"  // Blue background

        "   color: white;"               // White text

        "   border: 1px solid #2ecc71;"  // Blue border

        "}"

        "QLabel:hover {"

        "   background-color:  #27ae60;"  // Darker blue on hover

        "}");


    //Change Length
    QLabel* mLengthLabel = new QLabel("Length", this);

    mLengthLabel->setGeometry(QRect(1570, 390, 80, 24));

    // Set text alignment to center

    mLengthLabel->setAlignment(Qt::AlignCenter);

    mLengthLabel->setStyleSheet("QLabel {"

        "   background-color: #3498db;"  // Blue background

        "   color: white;"               // White text

        "   border: 1px solid #3498db;"  // Blue border

        "}"

        "QLabel:hover {"

        "   background-color: #2980b9;"  // Darker blue on hover

        "}");


    mDoubleSpinBoxLength = new QDoubleSpinBox(this);
    mDoubleSpinBoxLength->setObjectName("doubleSpinBoxLength");
    mDoubleSpinBoxLength->setGeometry(QRect(1580, 430, 60, 22));
    mDoubleSpinBoxLength->setMinimum(-100.0000000000000);
    mDoubleSpinBoxLength->setMaximum(100.00000000000000);
    //change width

    QLabel* mWidthLabel = new QLabel("Width", this);

    mWidthLabel->setGeometry(QRect(1685, 390, 80, 24));

    // Set text alignment to center
    mWidthLabel->setAlignment(Qt::AlignCenter);

    mWidthLabel->setStyleSheet("QLabel {"

        "   background-color: #3498db;"  // Blue background

        "   color: white;"               // White text

        "   border: 1px solid #3498db;"  // Blue border

        "}"

        "QLabel:hover {"

        "   background-color: #2980b9;"  // Darker blue on hover

        "}");

    mDoubleSpinBoxWidth = new QDoubleSpinBox(this);
    mDoubleSpinBoxWidth->setObjectName("doubleSpinBoxWidth");
    mDoubleSpinBoxWidth->setGeometry(QRect(1695, 430, 60, 22));
    mDoubleSpinBoxWidth->setMinimum(-100.0000000000000);
    mDoubleSpinBoxWidth->setMaximum(100.00000000000000);
    
    //Change Height

    QLabel* mHeightLabel = new QLabel("Height", this);

    mHeightLabel->setGeometry(QRect(1800, 390, 80, 24));

    // Set text alignment to center
    mHeightLabel->setAlignment(Qt::AlignCenter);

    mHeightLabel->setStyleSheet("QLabel {"

        "   background-color: #3498db;"  // Blue background

        "   color: white;"               // White text

        "   border: 1px solid #3498db;"  // Blue border

        "}"

        "QLabel:hover {"

        "   background-color: #2980b9;"  // Darker blue on hover

        "}");

    mDoubleSpinBoxHeight = new QDoubleSpinBox(this);
    mDoubleSpinBoxHeight->setObjectName("mDoubleSpinBoxHeight");
    mDoubleSpinBoxHeight->setGeometry(QRect(1810, 430, 60, 22));
    mDoubleSpinBoxHeight->setMinimum(-100.0000000000000);
    mDoubleSpinBoxHeight->setMaximum(100.00000000000000);

    //Translate label

    QLabel* mTranslateLabel = new QLabel("Translate", this);

    mTranslateLabel->setGeometry(QRect(1555, 490, 80, 24));

    // Set text alignment to center

    mTranslateLabel->setAlignment(Qt::AlignCenter);

    mTranslateLabel->setStyleSheet("QLabel {"
        "   background-color: #e74c3c;"  // Red background
        "   color: white;"                // White text
        "   border: 1px solid #e74c3c;"   // Red border
        "}"
        "QLabel:hover {"
        "   background-color: #c0392b;"  // Darker red on hover
        "}");


    //Translate by X
    QLabel* labelTranslateX = new QLabel("X :", this);
    labelTranslateX->setGeometry(QRect(1645, 485, 21, 31));

    mDoubleSpinBoxTranslateX = new QDoubleSpinBox(this);
    mDoubleSpinBoxTranslateX->setObjectName("doubleSpinBoxTranslate");
    mDoubleSpinBoxTranslateX->setGeometry(QRect(1670, 490, 60, 22));
    mDoubleSpinBoxTranslateX->setMinimum(-100.0000000000000);
    mDoubleSpinBoxTranslateX->setMaximum(100.00000000000000);

    //Translate by Y
    QLabel* labelTranslateY = new QLabel("Y :", mCentralWidget);
    labelTranslateY->setGeometry(QRect(1740, 485, 21, 31));

    mDoubleSpinBoxTranslateY = new QDoubleSpinBox(this);
    mDoubleSpinBoxTranslateY->setObjectName("doubleSpinBoxTranslate");
    mDoubleSpinBoxTranslateY->setGeometry(QRect(1760, 490, 60, 22));
    mDoubleSpinBoxTranslateY->setMinimum(-100.0000000000000);
    mDoubleSpinBoxTranslateY->setMaximum(100.00000000000000);

    //Translate by Z
    QLabel* labelTranslateZ = new QLabel("Z :", mCentralWidget);
    labelTranslateZ->setGeometry(QRect(1830, 485, 21, 31));

    mDoubleSpinBoxTranslateZ = new QDoubleSpinBox(this);
    mDoubleSpinBoxTranslateZ->setObjectName("doubleSpinBoxTranslate");
    mDoubleSpinBoxTranslateZ->setGeometry(QRect(1850, 490, 60, 22));
    mDoubleSpinBoxTranslateZ->setMinimum(-100.0000000000000);
    mDoubleSpinBoxTranslateZ->setMaximum(100.00000000000000);

    //Reset screen
    mResetButton = new QPushButton("Reset", this);
    mResetButton->setGeometry(QRect(1660, 590, 80, 24));
    mResetButton->setStyleSheet("QPushButton {"
        "   background-color: #95a5a6;"    // Gray background
        "   color: white;"                 // White text
        "   border: 1px solid #95a5a6;"    // Gray border
        "}"
        "QPushButton:hover {"
        "   background-color: #7f8c8d;"    // Darker gray on hover
        "}");

    setCentralWidget(mCentralWidget);
    showMaximized();

} 

//slot to display Walls
void Application::displayWalls()
{
    mVertices.clear();
    mColors.clear();

    for (Wall& Wall : mWalls)
    {
        QVector<GLfloat> vertices;
        QVector<GLfloat> colors;
        QVector<GLfloat> normals;

        const std::vector<Triangle> allTriangles = Wall.getTriangles();
        for (Triangle triangle : allTriangles)
        {
            Point3D point1 = triangle.point1();
            Point3D point2 = triangle.point2();
            Point3D point3 = triangle.point3();

            vertices << point1.x() << point1.y() << point1.z();
            vertices << point2.x() << point2.y() << point2.z();
            vertices << point3.x() << point3.y() << point3.z();

            colors << 1 << 1 << 1;
            colors << 1 << 1 << 1;
            colors << 1 << 1 << 1;

        }

        mVertices.push_back(vertices);
        mColors.push_back(colors);
    }
    mRenderer->updateShapesData(mVertices, mColors);
}

//slot to add new wall
void Application::addWall()
{ 
    Wall* Wall = Wall::getWall();
    mWalls.push_back(*Wall);
    displayWalls();

    int WallSize =mWalls.size();

    QString itemText = QString("Wall %1").arg(WallSize);
    QListWidgetItem* newItem = new QListWidgetItem(itemText);
    mWallList->addItem(newItem);
}

//slot to change length of wall
void Application::changeLength()
{
    QModelIndex currentIndex = mWallList->currentIndex();
   double changeLength = mDoubleSpinBoxLength->value();
  
    int currInd = currentIndex.row();
    mWalls[currInd].setLength(changeLength);
    displayWalls();     
}

//slot to change width of wall
void Application::changeWidth()
{
    QModelIndex currentIndex = mWallList->currentIndex();
    double changeWidth = mDoubleSpinBoxWidth->value();

    int currInd = currentIndex.row();
    mWalls[currInd].setWidth(changeWidth);
    displayWalls();
}

//slot to change height of wall
void Application::changeHeight()
{
    QModelIndex currentIndex = mWallList->currentIndex();
    double changeHeight = mDoubleSpinBoxHeight->value();

    int currInd = currentIndex.row();
    mWalls[currInd].setHeight(changeHeight);
    displayWalls();
}

//slot to move wall

void Application::onTranslateXValueChanged(double newValue)
{
    double translateX = newValue;
    double translateY = 0;
    double translateZ = 0;
    QModelIndex currentIndex = mWallList->currentIndex();
    int currInd = currentIndex.row();
    mWalls[currInd].translate(translateX, translateY, translateZ);
    displayWalls();
}

void Application::onTranslateYValueChanged(double newValue)
{
    double translateX = 0;
    double translateY = newValue;
    double translateZ = 0;
    QModelIndex currentIndex = mWallList->currentIndex();
    int currInd = currentIndex.row();
    mWalls[currInd].translate(translateX, translateY, translateZ);
    displayWalls();
}

void Application::onTranslateZValueChanged(double newValue)
{
    double translateX = 0;
    double translateY = 0;
    double translateZ = newValue;
    QModelIndex currentIndex = mWallList->currentIndex();
    int currInd = currentIndex.row();
    mWalls[currInd].translate(translateX, translateY, translateZ);
    displayWalls();
}