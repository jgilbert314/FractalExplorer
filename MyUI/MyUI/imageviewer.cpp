#include "imageviewer.h"
#include "ui_imageviewer.h"
#include "setimage.h"
#include "lcdpanel.h"
#include "lineeditnumber.h"

#include "../../AuxiliaryCode.h"

// TODO:
//      - Implement local variables (pixel arrays)
//      - Implement timer structure
//      - Memory estimation


ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageViewer)
    , scrollAreaM(new QScrollArea)
    , scrollAreaP(new QScrollArea)
{
    // TODO: initialize local variables
    //      - pixel arrays (need to check time vs mem for each approach)

    ui->setupUi(this);
    initFlag = 1; // Flag for setting default image

    setCentralWidget(ui->centralwidget);
    ui->scrollAreaM->setWidgetResizable(true);
    ui->imageLabelM->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->imageLabelM->setScaledContents(true);
    ui->imageLabelP->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->imageLabelP->setScaledContents(true);
    ui->centralwidget->layout()->setContentsMargins(0, 0, 0, 0); // Simplifies cursor tracking

    ui->label_colourPalette->setScaledContents(true); // TESTING

    connect(ui->updateButton, &QPushButton::released, this, &ImageViewer::updateSet);

    // Add widgets from SetImage
    ui->tab_1->layout()->addWidget(mapImage.lcdPanel);
    ui->tab_3->layout()->addWidget(pointImage.lcdPanel);


    ui->tab_1->layout()->addWidget(scrollAreaM);
    scrollAreaM->setWidgetResizable(true);
    scrollAreaM->setWidget(mapImage.inputPanel);
    scrollAreaM->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->tab_3->layout()->addWidget(scrollAreaP);
    scrollAreaP->setWidgetResizable(true);
    scrollAreaP->setWidget(pointImage.inputPanel);
    scrollAreaP->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


    /// Map Set
    // Initialize Display labels
    mapImage.disp_data.label_outputMsg = ui->label_outputM;
    mapImage.disp_data.label_image = ui->imageLabelM;

    // Set default values
    // TODO: subclass and include in constructor
    mapImage.initImage('M'); // M for Map
    mapImage.linkTextInput();
    mapImage.updateParamDisp();



    /// Point Set
    // Initialize Display labels
    pointImage.disp_data.label_image = ui->imageLabelP;
    pointImage.disp_data.label_outputMsg = ui->label_outputP;

    // Set default values
    // TODO: subclass and include in constructor
    pointImage.initImage('P'); // P for Point
    pointImage.linkTextInput();
    pointImage.updateParamDisp();

    /// Generate default images
    updateSet();

    // TESTING - start
    testPalette();
    // TESTING - end



}

ImageViewer::~ImageViewer()
{
    delete ui;
    // Assigned to layout -- handled by layout destructor
    //delete scrollAreaM;
    //delete scrollAreaP;
}


// Calculation Button
void ImageViewer::keyPressEvent(QKeyEvent *event)
{
    // TODO: global scale_factor for zooming ? -- add to SetImage
    if(event->key() == Qt::Key_Return) {
        updateSet();
    } else if (event->key() == Qt::Key_W) { // Zoom in
        pointImage.zoomImage(0.9);
        updateSet();
    } else if (event->key() == Qt::Key_S) {
        pointImage.zoomImage(1/0.9); // Zoom out
        updateSet();
    };
};

// Mouse Clicking
void ImageViewer::mousePressEvent(QMouseEvent *event)
{
    // Dec 01, 2023

    if (event->button() == Qt::LeftButton) {
        // Click in Map Set
        if ( checkClickTarget(ui->imageLabelM) ) {
            QWidget* target_test = ui->imageLabelM;
            vector<double> cN = mapImage.pixelToConst(target_test);

            if (event->modifiers() & Qt::ShiftModifier) {
                    mapImage.setRo(cN[0]);
                    mapImage.setIo(cN[1]);
            } else if (event->modifiers() & Qt::ControlModifier) {
                    pointImage.setCR(cN[0]);
                    pointImage.setCI(cN[1]);
            }
            updateSet();

        } else if (checkClickTarget(ui->imageLabelP)) {
            if (event->modifiers() & Qt::ShiftModifier) {
                // TODO: convert to function
                QWidget* target_test = ui->imageLabelP;
                vector<double> cN = pointImage.pixelToConst(target_test);
                pointImage.setRo(cN[0]);
                pointImage.setIo(cN[1]);

                updateSet();
            }
        }
    }
}



void ImageViewer::mouseMoveEvent(QMouseEvent *event)
{
    // Dec 02, 2023

    QWidget* target_test = ui->imageLabelM;

    if (event->modifiers() & Qt::ControlModifier) {
        if ( checkClickTarget(target_test) ) {
            // TODO: convert to function
            vector<double> cN = mapImage.pixelToConst(target_test);

            pointImage.setCR(cN[0]);
            pointImage.setCI(cN[1]);
            updateSet();
        }
    };
};


void ImageViewer::wheelEvent(QWheelEvent *event) {
    // Date: Dec 03, 2023
    double scale_in = 0.9;
    double scale_out = 1/scale_in;

    if (event->modifiers() & Qt::ShiftModifier) {
        if (!event->angleDelta().isNull()) {
            QPoint numDegrees = event->angleDelta() / 8;

            if ( checkClickTarget(ui->imageLabelM) ) {
                if (numDegrees.y() > 0) { // TODO: convert to function (in ImageViewer)
                    mapImage.zoomImage(scale_in);
                } else {
                    mapImage.zoomImage(scale_out);
                }
                updateSet();
            }
            else if (checkClickTarget(ui->imageLabelP)) {
                if (numDegrees.y() > 0) {
                    pointImage.zoomImage(scale_in);
                } else {
                    pointImage.zoomImage(scale_out);
                }
                updateSet();
            };
        };
    };
};

bool ImageViewer::checkClickTarget(QWidget* target_test) {
    QPoint cur_pos = target_test->mapFromGlobal( target_test->cursor().pos() );

    if ( (cur_pos.x() <= target_test->width()) && (cur_pos.y() < target_test->height()) ) {
        return true;
    } else {
        return false;
    }
};



void ImageViewer::updateSet()
{
    // TODO:
    //      - Update to reuse set memory (z_set, c_set) instead of reallocating each time (compare time/memory usage)


    // Timing Init
    map<std::string, duration<double> > time_map; // For storing run times
    auto t0 = high_resolution_clock::now();
    auto t1 = high_resolution_clock::now();

    auto t00 = high_resolution_clock::now(); // Full execution timer

    // On init: use defaults, otherwise
    if (initFlag) {
        initFlag = 0;
    } else {
        mapImage.readParamInput();
        pointImage.readParamInput();
    };

    // Map Set
    // TODO: convert to method in ImageViewer
    QPalette palM = QPalette(); // TODO: add colour palette to SetImage
    if ( mapImage.getCalcFlag() ) {
        t0 = high_resolution_clock::now();
        mapImage.calcSet();
        t1 = high_resolution_clock::now();
        mapImage.disp_data.time_data["update"].time_val = t1 - t0;

        palM.setColor(QPalette::Window, Qt::green);
        mapImage.updateTimeDisplay();
        mapImage.disp_data.label_outputMsg->setText( "Program Messages" );
    } else {
        palM.setColor(QPalette::Window, Qt::red);
    }
    ui->calcLabelM_u->setPalette(palM);
    mapImage.disp_data.time_data["update"].names_tag->setPalette(palM);



    // Point Set
    // TODO: convert to method in ImageViewer
    QPalette palP = QPalette(); // TODO: add colour palette to SetImage
    if ( pointImage.getCalcFlag() ) {
        t0 = high_resolution_clock::now();
        pointImage.calcSet();
        t1 = high_resolution_clock::now();
        pointImage.disp_data.time_data["update"].time_val = t1 - t0;

        palP.setColor(QPalette::Window, Qt::green);
        pointImage.updateTimeDisplay();
        pointImage.disp_data.label_outputMsg->setText( "Program Messages" );
    } else {
        palP.setColor(QPalette::Window, Qt::red);
    }
    ui->calcLabelP_u->setPalette(palP);
    pointImage.disp_data.time_data["update"].names_tag->setPalette(palP);

    auto tFF = high_resolution_clock::now();
    time_map["setUpdate"] = tFF - t00;

    return;
};






// TESTING
void ImageViewer::testPalette()
{

    // Pull points from HSV space, convert to RGB888

    int num_R = ui->label_colourPalette->width();
    int num_I = ui->label_colourPalette->height();

    vector<QColor> hsv_vec = calcHSV(200, 200, num_I);

    QImage imData(num_R, num_I, QImage::Format_RGB888);
    QColor val;
    int indC;
    for (int itrR = 0; itrR < num_R; itrR++) {
        for (int itrC = 0; itrC < num_I; itrC++) {
            indC = num_I - (itrC + 1); // Image display is flipped by default
            val = hsv_vec[itrC];
            imData.setPixel ( itrR, indC, qRgb(val.red(), val.green(), val.blue()) );
        }
    }


    ui->label_colourPalette->setPixmap(QPixmap::fromImage(imData));
    return;
}



// TESTING - create colour class (?)
vector<QColor> ImageViewer::calcHSV(int s_val, int v_val, int N) {

    int N_h = 359;
    vector<double> h_vec = linspace(0, N_h, N);

    double omega = 2*(3.14159) * 10;
    vector<double> cos_vec(N);
    for (uint itr = 0; itr < cos_vec.size(); itr++) {
        cos_vec[itr] = ( cos(omega*itr/N) );
        //h_vec[itr] = h_vec[itr]*cos_vec[itr]*cos_vec[itr];
        h_vec[itr] = N_h*cos_vec[itr]*cos_vec[itr];
    };


    vector<QColor> hsv_vec(N);
    for (uint itr = 0; itr < hsv_vec.size(); itr++) {
        if (itr == 0) {
            hsv_vec[itr] = QColor::fromHsv(0, 0, 0);
        } else {
            hsv_vec[itr] = QColor::fromHsv(h_vec[itr], s_val, v_val);
        };
        hsv_vec[itr] = hsv_vec[itr].toRgb();
    };

    return hsv_vec;

};

