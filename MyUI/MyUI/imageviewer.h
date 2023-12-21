#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include "setimage.h"
#include "setfam/mandelbrotset.h"
#include "setfam/juliaset.h"
#include "widgets/lcdpanel.h"
#include "widgets/lineeditnumber.h"
#include "widgets/inputpanel.h"

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QLCDNumber>

//#include <QtGamepad>
#include <QComboBox>
#include <QCursor>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>

#include <vector>
using namespace std;

#include <chrono> // Timing library
using namespace chrono;


QT_BEGIN_NAMESPACE
namespace Ui { class ImageViewer; }
QT_END_NAMESPACE


/*! A class for managing Qt interface -- mainly UI */
class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();


    /*!
     *  @brief Uses main window mouse tracking to check for click target
     *  @param[in] targ_test pointer to widget being tested
     */
    bool checkClickTarget(QWidget* targ_test);

    /*!
     * @brief testPalette Stand-in for colour palette function
     */
    void testPalette();

    /*!
     * @brief Calculates an HSV colour palette
     * @param[in] s_val saturation [0-255]
     * @param[in] v_val value [0-255]
     * @param[in] N number of points in palette [0-359]
     */
    vector<QColor> calcHSV(int s_val, int v_val, int N);



private slots:
    void updateSet();
    void updatePalette();

private:
    Ui::ImageViewer *ui;
    QScrollArea *scrollAreaM;
    QScrollArea *scrollAreaP;
    QComboBox *testBox;
    MandelbrotSet mapImage;
    JuliaSet pointImage;
    bool initFlag;
    bool colrFlag;

protected:
    /*! Handles keyboard input */
    void keyPressEvent(QKeyEvent *event) override;
    /*! Handles mouse clicks */
    void mousePressEvent(QMouseEvent *event) override;
    /*! Handles mouse movement */
    void mouseMoveEvent(QMouseEvent *event) override;
    /*! Handles mouse scroll */
    void wheelEvent(QWheelEvent *event) override;

};
#endif // IMAGEVIEWER_H
