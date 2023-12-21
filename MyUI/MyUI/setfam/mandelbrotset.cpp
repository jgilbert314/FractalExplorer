#include "mandelbrotset.h"

MandelbrotSet::MandelbrotSet()
{

        // Origin
        setRo(0);
        setIo(0);
        // Span
        setRs(4);
        setIs(4);

        calcSpanCoords();

        // Resolution
        setNR(100);
        setNI(100);
        // Iterations
        setNK(100);

        updateDelC();

        vector<QString> name_list = {"Ro", "Io", "Rs", "Is", "NR", "NI", "NK"};
        vector<char> spec_list = {'d', 'd', 's', 's', 'i', 'i', 'i'};
        inputPanel->buildPanel(name_list, spec_list);

        disp_data.label_dubvals.resize(4);
        disp_data.label_dubsets = {&SetImage::setRo, &SetImage::setIo, &SetImage::setRs, &SetImage::setIs};
        disp_data.label_dubgets = {&SetImage::getRo, &SetImage::getIo, &SetImage::getRs, &SetImage::getIs};

        linkTextInput();
        updateParamDisp();

}



/*! Calculates Mandelbrot set */
vector<double> MandelbrotSet::setFunc() {

    calcSpanCoords();
    linspace(axes_data.r_vals, getRL(), getRU(), getNR()); // TODO: check if these need recomputed
    linspace(axes_data.i_vals, getIL(), getIU(), getNI());

    int N_R = axes_data.r_vals.size();
    int N_I = axes_data.i_vals.size();
    int K = getNK();
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




/*
void MandelbrotSet::calcSet() {
    calcSpanCoords();
    auto t0 = high_resolution_clock::now();

    linspace(axes_data.r_vals, getRL(), getRU(), getNR()); // TODO: check if these need recomputed
    linspace(axes_data.i_vals, getIL(), getIU(), getNI());
    vector<double> z_set = setFunc();

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
*/
