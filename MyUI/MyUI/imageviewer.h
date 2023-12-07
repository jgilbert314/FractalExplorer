#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include "setimage.h"

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QLCDNumber>

//#include <QtGamepad>
#include <QCursor>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>

#include <vector>  	 // Defines vector type
#include <complex>
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

    void updateImage(QLabel* imSpace, vector<unsigned int> b_set, int num_R, int num_I); \
    void updateParamDisplay(double bound_RL, double bound_RU, double bound_IL, double bound_IU, int num_R, int num_I, int num_K);

    bool checkClickTarget(QWidget* targ_test);

    void testPalette();
    vector<QColor> calcHSV(int s_val, int v_val, int N);


private slots:
    void updateSet();

private:
    Ui::ImageViewer *ui;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    SetImage mapImage;
    SetImage pointImage;
    bool initFlag;

protected:
    void keyPressEvent(QKeyEvent *event) override; /*! Handles keyboard input */
    void mousePressEvent(QMouseEvent *event) override; /*! Handles mouse clicks */
    void mouseMoveEvent(QMouseEvent *event) override; /*! Handles mouse movement */
    void wheelEvent(QWheelEvent *event) override; /*! Handles mouse scroll */
};
#endif // IMAGEVIEWER_H
