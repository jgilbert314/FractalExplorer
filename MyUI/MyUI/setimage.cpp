#include "setimage.h"


/////////////////////////////////////////
/// Initialzation
/////////////////////////////////////////

SetImage::SetImage()
    : lcdPanel(new LCDPanel)
    , inputPanel(new InputPanel)
    , colourSelect(new QComboBox)
{
    setCalcFlag(true);
    colrFlag = 1; // TESTING - colour

    disp_data.label_intvals = {&set_param.num_R, &set_param.num_I, &set_param.num_K};
    linkLCDTime(); // Connect widgets to values
};


void SetImage::linkLCDTime() {

    map<string, LCDPanel::LabelLink>::iterator it;
    string this_key;
    for (it = lcdPanel->disp_map.begin(); it != lcdPanel->disp_map.end(); it++) {
        this_key = it->first;
        disp_data.time_data[this_key].names_tag = lcdPanel->disp_map[this_key].label;
        disp_data.time_data[this_key].names_val = lcdPanel->disp_map[this_key].lcd;
    };

    return;
}


SetImage::~SetImage() {

    delete colourSelect;
    colourSelect = nullptr;

    if (lcdPanel != nullptr) {
        delete lcdPanel;
        lcdPanel = nullptr;
    }
    if (inputPanel != nullptr) {
        delete inputPanel;
        inputPanel = nullptr;
    }

}


void SetImage::linkTextInput() {

    uint N_int = 0;
    uint N_dub = 0;
    uint t_flag;
    for (uint itr = 0; itr < inputPanel->input_list.size(); itr++) {
        t_flag = inputPanel->input_list[itr]->in_type;
        if (t_flag == 0) { // Integer
            N_int++;
        } else if (t_flag == 1) { // Double
            N_dub++;
        }
    }

    disp_data.label_int.resize(N_int);
    disp_data.label_intvals.resize(N_int);
    param_input.input_int.resize(N_int);

    disp_data.label_dub.resize(N_dub);
    disp_data.label_dubvals.resize(N_dub);
    param_input.input_dub.resize(N_dub);

    uint indI = 0;
    uint indD = 0;
    for (uint itr = 0; itr < inputPanel->input_list.size(); itr++) {
        t_flag = inputPanel->input_list[itr]->in_type;
        if (t_flag == 0) {
            disp_data.label_int[indI] = inputPanel->value_list[itr];
            param_input.input_int[indI] = inputPanel->input_list[itr];

            indI++;
        }
        else if (t_flag == 1) {
            disp_data.label_dub[indD] = inputPanel->value_list[itr];
            param_input.input_dub[indD] = inputPanel->input_list[itr];

            indD++;
        }
    }


}


/////////////////////////////////////////
/// Set  Calculation
/////////////////////////////////////////

void SetImage::calcSet() {
    calcSpanCoords();
    auto t0 = high_resolution_clock::now();

    linspace(axes_data.r_vals, set_param.bound_RL, set_param.bound_RU, set_param.num_R); // TODO: check if these need recomputed
    linspace(axes_data.i_vals, set_param.bound_IL, set_param.bound_IU, set_param.num_I);
    vector<double> z_set = setFunc();
    //vector<double> z_set = (this->*setDefFunc)(); // TODO: create subclasses of SetImage (map and point) -- one for each set function?

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



void SetImage::updateDelC() {
    // Date: Dec 02, 2023

    set_param.dR = (set_param.bound_RU - set_param.bound_RL)/(set_param.num_R - 1);
    set_param.dI = (set_param.bound_IU - set_param.bound_IL)/(set_param.num_I - 1);

    return;
};



void SetImage::calcSpanCoords() {
    set_param.bound_RL = set_param.Ro - set_param.Rs/2;
    set_param.bound_RU = set_param.Ro + set_param.Rs/2;
    set_param.bound_IL = set_param.Io - set_param.Is/2;
    set_param.bound_IU = set_param.Io + set_param.Is/2;

    return;
};


void SetImage::panImage(double scaleR, double scaleI) {

    set_param.Ro += set_param.Rs*scaleR;
    set_param.Io += set_param.Is*scaleI;

    setCalcFlag(true);

    return;
}


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

    /// \todo Refactoring -- compress by running loop on proxy vector and function handle (toDouble, toInt)

    void (SetImage::*this_ptr)(double);
    double val = 0;

    // Values seperated by type due to QString limits
    // Read values with type double
    bool convert_flag = 1;
    QString err_msg;
    for (uint itr = 0; itr < param_input.input_dub.size(); itr++) {
        if (param_input.input_dub[itr]->isModified()) {

            // Argument checking
            try {
                param_input.input_dub[itr]->checkInput();

                this_ptr = disp_data.label_dubsets[itr];
                val = param_input.input_dub[itr]->text().toDouble(&convert_flag);
                (this->*this_ptr)(val); // Set parameter value
                disp_data.label_dubvals[itr] = val; // Set display value

                setCalcFlag(true);
            }
            catch (const invalid_argument &err_exc) {
                disp_data.label_outputMsg->setText( err_exc.what() );
            }
            // Reset input field
            param_input.input_dub[itr]->setText(""); // Resets isModified
        }
    }

    // Read values with type int
    for (uint itr = 0; itr < param_input.input_int.size(); itr++) {
        if (param_input.input_int[itr]->isModified()) {

            // Argument checking
            try {
                param_input.input_int[itr]->checkInput();

                *disp_data.label_intvals[itr] = param_input.input_int[itr]->text().toInt(&convert_flag);;
                setCalcFlag(true);
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

    double (SetImage::*this_ptr)(); // Temp variable for clarity


    for (uint itr = 0; itr < disp_data.label_dub.size(); itr++) {
        this_ptr = disp_data.label_dubgets[itr];
        disp_data.label_dub[itr]->setText(QString::number( (this->*this_ptr)() ));
    };

    for (uint itr = 0; itr < disp_data.label_int.size(); itr++) {
        disp_data.label_int[itr]->setText(QString::number( *disp_data.label_intvals[itr] ));
    };

    return;
};


/// \todo update to pull from axes_data
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
            imData.setPixel( itrR, indC, col_val ); /// \todo Doc says setPixel() is slow, try scanLine() or bits() instead
        }
    }

    disp_data.label_image->setPixmap( QPixmap::fromImage(imData) );

    return;

}


/// \todo Rename or seperate HSV and grayscale functions
vector<QColor> SetImage::calcHSV(int s_val, int v_val, int N) {

    int N_h = 359;
    vector<double> h_vec(N);
    vector<QColor> hsv_vec(N);

    if (colrFlag) {
        linspace(h_vec, 0, N_h, N);

        double omega = 2*(3.14159) * 10;
        vector<double> cos_vec(N);
        for (uint itr = 0; itr < cos_vec.size(); itr++) {
            cos_vec[itr] = ( cos(omega*itr/N) );
            //h_vec[itr] = h_vec[itr]*cos_vec[itr]*cos_vec[itr];
            h_vec[itr] = N_h*cos_vec[itr]*cos_vec[itr];
        };



        for (uint itr = 0; itr < hsv_vec.size(); itr++) {
            if (itr == 0) {
                hsv_vec[itr] = QColor::fromHsv(0, 0, 0);
            } else {
                hsv_vec[itr] = QColor::fromHsv(h_vec[itr], s_val, v_val);
            };
            hsv_vec[itr] = hsv_vec[itr].toRgb();
        };
    }
    else if (!colrFlag) {
        linspace(h_vec, 0, 255, N);
        uint val;

        for (uint itr = 0; itr < hsv_vec.size(); itr++) {
            val = h_vec[itr];
            hsv_vec[itr] = qRgb(val, val, val);
        }
    }

    return hsv_vec;

};


void SetImage::updatePalette(QString in_text) {


    if (in_text == "HSV") {
        colrFlag = true;
    }
    else if (in_text == "Gray") {
        colrFlag = false;
    }
    else {
        throw runtime_error("Bad colour spec");
    }

    setCalcFlag(true);

    return;
}




/// Function for calculating values of set
vector<double> SetImage::setFunc() {
    /// \todo TODO: rethink handling in base class (undefined) -- could be more elegant?

    throw runtime_error("Undefined set function");

    vector<double> output(0);
    return output;

}

