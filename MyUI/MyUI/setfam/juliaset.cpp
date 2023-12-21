#include "juliaset.h"

JuliaSet::JuliaSet()
{

    // Set coordinates
    setRo(0);
    setIo(0);
    setRs(4);
    setIs(4);
    calcSpanCoords();

    // Set Seed Constant
    setCR(0.25);
    setCI(0);

    // Set resolutions
    setNR(100);
    setNI(100);
    setNK(100);
    updateDelC();

    vector<QString> name_list = {"Ro", "Io", "Rs", "Is", "cR", "cI", "NR", "NI", "NK"};
    vector<char> spec_list = {'d', 'd', 's', 's', 'd', 'd', 'i', 'i', 'i'};
    inputPanel->buildPanel(name_list, spec_list);

    //disp_data.label_dubvals = {&set_param.Ro, &set_param.Io, &set_param.Rs, &set_param.Is, &set_param.cR, &set_param.cI};
    disp_data.label_dubvals.resize(6);
    disp_data.label_dubsets = {&SetImage::setRo, &SetImage::setIo, &SetImage::setRs, &SetImage::setIs, &SetImage::setCR, &SetImage::setCI}; // TESTING - delete (init in subclasses)
    disp_data.label_dubgets = {&SetImage::getRo, &SetImage::getIo, &SetImage::getRs, &SetImage::getIs, &SetImage::getCR, &SetImage::getCI};

    linkTextInput();
    updateParamDisp();

}




/* Calculates Julia set */
vector<double> JuliaSet::setFunc()
{

    int N_R = axes_data.r_vals.size();
    int N_I = axes_data.i_vals.size();
    int N = N_R*N_I;

    int K = getNK();
    double cR = getCR();
    double cI = getCI();

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
                Z_vals[ind] = (R_old*R_old - I_old*I_old) + cR;
                // Imag component
                Z_vals[ind+N] = (2*R_old*I_old) + cI;
                }
            }
        }



    return Z_vals;

};
