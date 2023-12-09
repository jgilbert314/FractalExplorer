#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include "setimage.h"
#include "lcdpanel.h"

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

    void linkLCDTime(SetImage &setImage, LCDPanel* lcdPanel); // TODO: move to SetImage
    void updateImage(QLabel* imSpace, vector<unsigned int> b_set, int num_R, int num_I);
    void updateParamDisplay(double bound_RL, double bound_RU, double bound_IL, double bound_IU, int num_R, int num_I, int num_K);

    bool checkClickTarget(QWidget* targ_test);

    void testPalette();
    vector<QColor> calcHSV(int s_val, int v_val, int N);

    LCDPanel lcdPanelM_main;
    LCDPanel* lcdPanelM = &lcdPanelM_main;

    LCDPanel lcdPanelP_main;
    LCDPanel* lcdPanelP = &lcdPanelP_main;

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
