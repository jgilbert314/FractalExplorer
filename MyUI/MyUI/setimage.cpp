#include "setimage.h"


/////////////////////////////////////////
/// Initialzation
/////////////////////////////////////////

SetImage::SetImage()
{
    setCalcFlag(true);

    disp_data.label_intvals = {&set_param.num_R, &set_param.num_I, &set_param.num_K};
};


void SetImage::setParamVals(vector<double*> label_dubvals) {
    // Date: Dec 01, 2023

    // Pass values from ImageViewer to avoid SetImage access to UI
    disp_data.label_dubvals = label_dubvals;

    return;
};

void SetImage::setParamLabels(vector<QLabel*> label_dub, vector<QLabel*> label_int) {
    // Date: Dec 01, 2023

    // Pass values from ImageViewer to avoid SetImage access to UI
    disp_data.label_dub = label_dub;
    disp_data.label_int = label_int;

    return;
};


void SetImage::setParamInput(vector<QLineEdit*> input_dub, vector<QLineEdit*> input_int) {
    // Date: Dec 01, 2023

    // Pass values from ImageViewer to avoid SetImage access to UI
    param_input.input_dub = input_dub;
    param_input.input_int = input_int;

    return;
};



/////////////////////////////////////////
/// Set  Calculation
/////////////////////////////////////////

void SetImage::calcSet() {
    calcSpanCoords();
    auto t0 = high_resolution_clock::now();

    linspace(axes_data.r_vals, set_param.bound_RL, set_param.bound_RU, set_param.num_R); // TODO: check if these need recomputed
    linspace(axes_data.i_vals, set_param.bound_IL, set_param.bound_IU, set_param.num_I);
    vector<double> z_set = (this->*setDefFunc)(); // TODO: create subclasses of SetImage (map and point) -- one for each set function?

    auto t1 = high_resolution_clock::now();
    disp_data.time_data["calc"].time_val = t1 - t0;

    t0 = high_resolution_clock::now();
    vector<unsigned int> b_set = formBitMap(z_set);
    t1 = high_resolution_clock::now();
    disp_data.time_data["bitmap"].time_val = t1 - t0;

    t0 = high_resolution_clock::now();
    updateImage(b_set);
    t1 = high_resolution_clock::now();
    disp_data.time_data["image"].time_val = t1 - t0;

    updateParamDisp();
    updateDelC();

    setCalcFlag(false);

    return;
};


/*! Calculates Mandelbrot set */
vector<double> SetImage::mandelbrot_calc() {

    int N_R = axes_data.r_vals.size();
    int N_I = axes_data.i_vals.size();
    int K = set_param.num_K;
    int N = N_R*N_I;

    double R_old, I_old;
    int ind;

    vector<double> Z_vals(2*N);

    for (int itrK = 0; itrK < K; itrK++) {
    #pragma omp parallel for simd private(ind) private(R_old) private(I_old)
        for (int itrR = 0; itrR < N_R; itrR++) {
            for (int itrI = 0; itrI < N_I; itrI++) {
                ind = itrR*N_I + itrI;

                R_old = Z_vals[ind];
                I_old = Z_vals[ind+N];

                // Real component
                Z_vals[ind] = (R_old*R_old - I_old*I_old) + axes_data.r_vals[itrR];
                // Imag component
                Z_vals[ind+N] = (2*R_old*I_old) + axes_data.i_vals[itrI];
                }
            }
        }

    return Z_vals;
};


/* Calculates Julia set */
vector<double> SetImage::julia_calc()
{

    int N_R = axes_data.r_vals.size();
    int N_I = axes_data.i_vals.size();
    int N = N_R*N_I;

    int K = set_param.num_K;

    double R_old, I_old;
    int ind;

    // Initialize output (z_0)
    vector<double> Z_vals(2*N);
    #pragma omp parallel for private(ind)
    for (int itrR = 0; itrR < N_R; itrR++) {
        for (int itrI = 0; itrI < N_I; itrI++) {
            ind = itrR*N_I + itrI;
            Z_vals[ind] = axes_data.r_vals[itrR];
            Z_vals[ind+N] = axes_data.i_vals[itrI];
        }
    };

    // For each iteration, calculate the next value z_{n+1}
    // This approach is more ammenable to vectorization
    // (distributes blocks of pixels rather than blocks of loops)
    for (int itrK = 0; itrK < K; itrK++) {
    #pragma omp parallel for simd private(ind) private(R_old) private(I_old)
        for (int itrR = 0; itrR < N_R; itrR++) {
            for (int itrI = 0; itrI < N_I; itrI++) {
                ind = itrR*N_I + itrI;

                R_old = Z_vals[ind];
                I_old = Z_vals[ind+N];

                // Real component
                Z_vals[ind] = (R_old*R_old - I_old*I_old) + set_param.cR;
                // Imag component
                Z_vals[ind+N] = (2*R_old*I_old) + set_param.cI;
                }
            }
        }



    return Z_vals;

};


/*! Calculates a vector of equally spaced points */
void SetImage::linspace(vector<double> &lin_vec, double bound_L, double bound_U, uint N) {

    // Throw an error if the interval is improperly defined
    if (bound_L >= bound_U) {
        throw invalid_argument("Upper bound must be greater than lower bound.");
    }
    if (N <= 1) {
        throw invalid_argument("The number of points must be greater than 1.");
    }

    // Distance between points in set
    double dist = (bound_U - bound_L) / (N - 1);
    // Calculate points in set
    if (lin_vec.size() != N) { // Check if requested size exceeds allocated memory
        lin_vec.resize(N);
    }
    for (uint itr = 0; itr < N; itr++) {
        // x_n = x_0 + n*(x_f - x_0)/(N - 1)
        lin_vec[itr] = bound_L + itr*dist;
    }

    return;

};



vector<unsigned int> SetImage::formBitMap(vector<double> z_set) {

    // Calculate image height values
    double max_val = 0;
    vector<double> m_set = mag_calc(z_set);
    for (uint itr = 0; itr < m_set.size(); itr++) {
        if ( isnan(m_set[itr]) ) {
            m_set[itr] = 0;
        }
        else {
            m_set[itr] = exp( -m_set[itr] );
            if (m_set[itr] > max_val) {
                max_val = m_set[itr];
            }
        }
    };

    // Convert to bit values
    vector<unsigned int> b_set(m_set.size());
    if (max_val != 0) { // max_val == 0 when all m_set is zero, no need to compute
        for (uint itr = 0; itr < m_set.size(); itr++) {
            b_set[itr] = (m_set[itr] / max_val)*255;
        }
    }

    return b_set;
};


vector<double> SetImage::mag_calc(vector<double> &Z_vals) {

    int N = Z_vals.size()/2;
    vector<double> m_vals(N);

    #pragma omp parallel for
    for (int itr = 0; itr < N; itr++) {
        m_vals[itr] = sqrt(Z_vals[itr]*Z_vals[itr] + Z_vals[itr+N]*Z_vals[itr+N]);
    }

    return m_vals;

};



/////////////////////////////////////////
/// Parameter Methods
/////////////////////////////////////////

void SetImage::initImage(char set_type) { // ModParam

    // TODO: specify setDefFunc for each

    // Map Set
    if (set_type == 'M') {
        // Dec 01, 2023

        set_param.Ro = 0;
        set_param.Io = 0;
        set_param.Rs = 4;
        set_param.Is = 4;
        calcSpanCoords();

        set_param.num_R = 100;
        set_param.num_I = 100;
        set_param.num_K = 100;
        updateDelC();

        setDefFunc = &SetImage::mandelbrot_calc; // TODO: create subclasses of SetImage (map and point) -- one for each set function?

    }
    // Point Set
    else if (set_type == 'P') { // ModParam
        // Dec 01, 2023
        set_param.Ro = 0;
        set_param.Io = 0;
        set_param.Rs = 4;
        set_param.Is = 4;
        calcSpanCoords();

        set_param.cR = 0.25;
        set_param.cI = 0;

        set_param.num_R = 100;
        set_param.num_I = 100;
        set_param.num_K = 100;
        updateDelC();

        setDefFunc = &SetImage::julia_calc; // TODO: create subclasses of SetImage (map and point) -- one for each set function?

    } else {
        throw invalid_argument("Input must be 'M' for Map or 'P' for Point");
    };

        return;
};



void SetImage::updateDelC() { // ModParam
    // Date: Dec 02, 2023

    set_param.dR = (set_param.bound_RU - set_param.bound_RL)/(set_param.num_R - 1);
    set_param.dI = (set_param.bound_IU - set_param.bound_IL)/(set_param.num_I - 1);

    return;
};



void SetImage::calcSpanCoords() { // ModParam
    set_param.bound_RL = set_param.Ro - set_param.Rs/2;
    set_param.bound_RU = set_param.Ro + set_param.Rs/2;
    set_param.bound_IL = set_param.Io - set_param.Is/2;
    set_param.bound_IU = set_param.Io + set_param.Is/2;

    return;
};


void SetImage::zoomImage(double scale) { // ModParam
    set_param.Rs *= scale;
    set_param.Is *= scale;
    calcSpanCoords();

    setCalcFlag(true);

    return;
};



/////////////////////////////////////////
/// UI Methods
/////////////////////////////////////////

void SetImage::readParamInput() {
    // Dec 01, 2023

    // TODO: refactoring -- add error checking to labels via subclass (float, int, span)

    // Values seperated by type due to QString limits
    // Read values with type double
    double val;
    bool convert_flag = 1;
    QString err_msg;
    for (uint itr = 0; itr < param_input.input_dub.size(); itr++) {
        if (param_input.input_dub[itr]->isModified()) {

            // Argument checking
            try {
                val = param_input.input_dub[itr]->text().toDouble(&convert_flag);
                if (!convert_flag) {
                    err_msg = disp_data.label_dub[itr]->whatsThis() + " must be a number";
                    throw invalid_argument(err_msg.toStdString());
                }
                else if ( (itr > 1) && (val <= 0) ) {
                    err_msg = disp_data.label_dub[itr]->whatsThis() + " must be >= 0";
                    throw invalid_argument(err_msg.toStdString());
                }
                else {
                    *disp_data.label_dubvals[itr] = val;
                    setCalcFlag(true);
                }
            }
            catch (const invalid_argument &err_exc) {
                disp_data.label_outputMsg->setText( err_exc.what() );
            }
            // Reset input field
            param_input.input_dub[itr]->setText(""); // Resets isModified
        }
    }

    // Read values with type int
    int valI;
    for (uint itr = 0; itr < param_input.input_int.size(); itr++) {
        if (param_input.input_int[itr]->isModified()) {

            // Argument checking
            try {
                valI = param_input.input_int[itr]->text().toInt(&convert_flag);
                if (!convert_flag) {
                    err_msg = disp_data.label_int[itr]->whatsThis() + " must be an integer";
                }
                else if (valI <= 1) {
                    err_msg = disp_data.label_int[itr]->whatsThis() + " must be > 1";
                }
                else {
                    *disp_data.label_intvals[itr] = valI;
                    setCalcFlag(true);
                }
            }
            catch (const invalid_argument &err_exc) {
                disp_data.label_outputMsg->setText( err_exc.what() );
            }
            // Reset input field
            param_input.input_int[itr]->setText(""); // Resets isModified
        };
    };


    return;
};


void SetImage::updateParamDisp() {
    // Dec 01, 2023

    for (uint itr = 0; itr < disp_data.label_dub.size(); itr++) {
        disp_data.label_dub[itr]->setText(QString::number( *disp_data.label_dubvals[itr] ));
    };

    for (uint itr = 0; itr < disp_data.label_int.size(); itr++) {
        disp_data.label_int[itr]->setText(QString::number( *disp_data.label_intvals[itr] ));
    };

    return;
};


vector<double> SetImage::calcConstFromInd(int nR, int nI) {
    // Date: Dec 02, 2023

    double cR = set_param.bound_RL + nR*set_param.dR;
    double cI = set_param.bound_IL + nI*set_param.dI;
    vector<double> cN{cR, cI};

    return cN;
};


vector<double> SetImage::pixelToConst(QWidget* im_target)
{
    // Dec 01, 2023

    QPoint cur_pos = im_target->mapFromGlobal( im_target->cursor().pos() );

    double set_width = set_param.num_R;
    double set_height = set_param.num_I;

    double scale_x = set_width / im_target->width();
    double scale_y = set_height / im_target->height();

    int pix_x = cur_pos.x()*scale_x;
    int pix_y = set_height - cur_pos.y()*scale_y; // Pixel coordinates are flipped from complex coordinates

    vector<double> cN = calcConstFromInd(pix_x, pix_y);

    return cN;
};



void SetImage::updateTimeDisplayElem(string field) {
    disp_data.time_data[field].names_val->display( disp_data.time_data[field].time_val.count() );

    return;
}

void SetImage::updateTimeDisplay() {
    for (const auto& [key, value] : disp_data.time_data) {
        updateTimeDisplayElem(key);
    }

    return;
}



/////////////////////////////////////////
/// Image Methods
/////////////////////////////////////////


/*! Image writer */
void SetImage::updateImage(vector<unsigned int> &b_set) {

    vector<QColor> hsv_vec = calcHSV(200, 200, 255);
    QRgb col_val;

    QImage imData(set_param.num_R, set_param.num_I, QImage::Format_RGB888);
    unsigned int val;
    int indC;
    for (int itrR = 0; itrR < set_param.num_R; itrR++) {
        for (int itrC = 0; itrC < set_param.num_I; itrC++) {
            indC = set_param.num_I - (itrC + 1); // Image display is flipped by default
            val = b_set[set_param.num_I*itrR + itrC];
            col_val = qRgb(hsv_vec[val].red(), hsv_vec[val].green(), hsv_vec[val].blue());
            imData.setPixel( itrR, indC, col_val ); // TODO: doc says setPixel() is slow, try scanLine() or bits() instead
        }
    }


    disp_data.label_image->setPixmap(QPixmap::fromImage(imData));
    return;
}


// TESTING - consider creating colour class (?)
vector<QColor> SetImage::calcHSV(int s_val, int v_val, int N) {

    uint N_h = 359;
    vector<double> h_vec(N);
    linspace(h_vec, 0, N_h, N);

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
