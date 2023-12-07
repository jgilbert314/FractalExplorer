#include "imageviewer.h"
#include "ui_imageviewer.h"
#include "setimage.h"

#include "../../AuxiliaryCode.h"

// TODO:
//      - Implement local variables (pixel arrays)
//      - Implement timer structure
//      - Memory estimation


ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageViewer)
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


    /// Map Set
    // Connect display values
    vector<double*> label_dubvals{&mapImage.getRo(), &mapImage.getIo(), &mapImage.getRs(), &mapImage.getIs()};
    mapImage.setParamVals(label_dubvals);

    // Initialize Display labels
    vector<QLabel*> label_dub{ui->label_M_RoV, ui->label_M_IoV, ui->label_M_RsV, ui->label_M_IsV};
    vector<QLabel*> label_int{ui->label_M_NRV, ui->label_M_NIV, ui->label_M_NKV};
    mapImage.disp_data.label_image = ui->imageLabelM;
    mapImage.setParamLabels(label_dub, label_int);

    // Initialize input fields
    vector<QLineEdit*> input_dub{ui->lineEdit_M_Ro, ui->lineEdit_M_Io, ui->lineEdit_M_Rs, ui->lineEdit_M_Is};
    vector<QLineEdit*> input_int{ ui->lineEdit_M_NR,  ui->lineEdit_M_NI,  ui->lineEdit_M_NK};
    mapImage.setParamInput(input_dub, input_int);

    // Set default values
    mapImage.initImage('M'); // M for Map
    mapImage.updateParamDisp();

    /// Point Set
    // Connect display values
    vector<double*> label_dubvalsP{&pointImage.getRo(), &pointImage.getIo(), &pointImage.getRs(), &pointImage.getIs(), &pointImage.getCR(), &pointImage.getCI()};
    pointImage.setParamVals(label_dubvalsP);

    // Initialize Display labels
    pointImage.disp_data.label_image = ui->imageLabelP;
    vector<QLabel*> label_dubP{ui->label_P_RoV, ui->label_P_IoV, ui->label_P_RsV, ui->label_P_IsV, ui->label_P_CrV, ui->label_P_CiV};
    vector<QLabel*> label_intP{ui->label_P_NRV, ui->label_P_NIV, ui->label_P_NKV};
    pointImage.setParamLabels(label_dubP, label_intP);

    // Initialize input fields
    vector<QLineEdit*> input_dubP{ui->lineEdit_P_Ro, ui->lineEdit_P_Io, ui->lineEdit_P_Rs, ui->lineEdit_P_Is, ui->lineEdit_P_cR, ui->lineEdit_P_cI};
    vector<QLineEdit*> input_intP{ui->lineEdit_P_NR, ui->lineEdit_P_NI, ui->lineEdit_P_NK};
    pointImage.setParamInput(input_dubP, input_intP);

    // Set default values
    pointImage.initImage('P'); // P for Point
    pointImage.updateParamDisp();

    // Generate default images
    updateSet();

    // TESTING - start
    testPalette();
    // TESTING - end
}

ImageViewer::~ImageViewer()
{
    delete ui;
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

// Mouse Input
void ImageViewer::mousePressEvent(QMouseEvent *event)
{
    // Dec 01, 2023

    if (event->button() == Qt::LeftButton) {
        // Click in Map Set
        if ( checkClickTarget(ui->imageLabelM) ) {
            QWidget* target_test = ui->imageLabelM;
            vector<double> cN = mapImage.pixelToConst(target_test);

            ui->label_coord_R->setText( QString::number(cN[0], 'E', 6) ); // TODO: convert to function
            ui->label_coord_I->setText( QString::number(cN[1], 'E', 6) );

            if (event->modifiers() & Qt::ShiftModifier) {
                    mapImage.setRo(cN[0]);
                    mapImage.setIo(cN[1]);
            } else if (event->modifiers() & Qt::ControlModifier) {
                    pointImage.setCR(cN[0]);
                    pointImage.setCI(cN[1]);
            };
            updateSet();

        } else if (checkClickTarget(ui->imageLabelP)) {
            if (event->modifiers() & Qt::ShiftModifier) {
                // TODO: convert to function
                QWidget* target_test = ui->imageLabelP;
                vector<double> cN = pointImage.pixelToConst(target_test);
                pointImage.setRo(cN[0]);
                pointImage.setIo(cN[1]);

                updateSet();
            };
        } else {
            cout << "Outside click" << endl << endl;
        };
    };
};



void ImageViewer::mouseMoveEvent(QMouseEvent *event)
{
    // Dec 02, 2023

    QWidget* target_test = ui->imageLabelM;

    if (event->modifiers() & Qt::ControlModifier) {
        if ( checkClickTarget(target_test) ) {
            // TODO: convert to function
            vector<double> cN = mapImage.pixelToConst(target_test);

            ui->label_coord_R->setText( QString::number(cN[0], 'E', 6) );
            ui->label_coord_I->setText( QString::number(cN[1], 'E', 6) );

            pointImage.setCR(cN[0]);
            pointImage.setCI(cN[1]);
            updateSet();
        } else {
            cout << "Outside click" << endl << endl;
        };
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



// Image writer
void ImageViewer::updateImage(QLabel* imSpace, vector<unsigned int> b_set, int num_R, int num_I)
{

    vector<QColor> hsv_vec = calcHSV(200, 200, 255);
    QRgb col_val;

    QImage imData(num_R, num_I, QImage::Format_RGB888);
    unsigned int val;
    int indC;
    for (int itrR = 0; itrR < num_R; itrR++) {
        for (int itrC = 0; itrC < num_I; itrC++) {
            indC = num_I - (itrC + 1); // Image display is flipped by default
            val = b_set[num_I*itrR + itrC];
            col_val = qRgb(hsv_vec[val].red(), hsv_vec[val].green(), hsv_vec[val].blue());
            imData.setPixel ( itrR, indC, col_val ); // TODO: doc says setPixel() is slow, try scanLine() or bits() instead
        }
    }


    imSpace->setPixmap(QPixmap::fromImage(imData));
    return;
}




void ImageViewer::updateSet()
{
    // TODO:
    //      - Check for parameter modification before update
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
    QPalette palM = QPalette();
    if ( mapImage.getCalcFlag() ) {
        t0 = high_resolution_clock::now();
        mapImage.calcSet();
        t1 = high_resolution_clock::now();
        time_map["calcTime_M"] = t1 - t0;

        ui->calcLabelM_V->display(time_map["calcTime_M"].count());
        palM.setColor(QPalette::Window, Qt::green);
        mapImage.updateParamDisp();
    } else {
        palM.setColor(QPalette::Window, Qt::red);
    }
    ui->calcLabelM->setPalette(palM);


    // Point Set
    // TODO: convert to function (need to split Map/Point functions, or add function handle as local variable)
    QPalette palP = QPalette();
    if ( pointImage.getCalcFlag() ) {
        pointImage.setCalcFlag(false);

        pointImage.calcSpanCoords();
        vector<double> r_valsP = linspace(pointImage.getBRL(), pointImage.getBRU(), pointImage.getNR());
        vector<double> i_valsP = linspace(pointImage.getBIL(), pointImage.getBIU(), pointImage.getNI());
        pointImage.linspace(i_valsP, pointImage.getBIL(), pointImage.getBIU(), pointImage.getNI());
        t0 = high_resolution_clock::now();
        vector<double> p_set = pointSet_calcV(r_valsP, i_valsP, pointImage.getCR(), pointImage.getCI(), pointImage.getNK());
        t1 = high_resolution_clock::now();
        time_map["calcTime_P"] = t1 - t0;
        ui->calcLabelP_V->display(time_map["calcTime_P"].count());

        vector<unsigned int> b_setP = formBitMap(p_set);
        updateImage(ui->imageLabelP, b_setP, pointImage.getNR(), pointImage.getNI());
        pointImage.updateParamDisp();
        pointImage.updateDelC();

        palP.setColor(QPalette::Window, Qt::green);
    } else {
        palP.setColor(QPalette::Window, Qt::red);
    }
    ui->calcLabelP->setPalette(palP);

    auto tFF = high_resolution_clock::now();
    time_map["setUpdate"] = tFF - t00;
    /*
    // Write times (DEBUGGING)
    for (const auto& [key, value] : time_map) {
        cout << key << ": " << value.count() << endl;
    }
    cout << endl;
    */
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
        h_vec[itr] = h_vec[itr]*cos_vec[itr]*cos_vec[itr];
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

