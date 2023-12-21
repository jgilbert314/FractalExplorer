
#include <vector>
#include <string>
#include <iostream>  // Input/Output
#include <sstream>

#include <chrono>
#include <map>

#include <cmath>
#include <complex>

using namespace std; // Allow implicit use of standard library
using namespace chrono;

#include "../AuxiliaryCode.h"

uint fact(uint N) {

    uint f_out = 1;
    for (uint itr = 1; itr <= N; itr++) {
        f_out *= itr;
    }

    return f_out;

}

void naive_calc(vector<double> &in_dat, double x, double y, uint N) {
    
    double sR = 0;
    double sI = 0;

    uint indM;
    double c_k, val;
    uint mod2, mod4;

    for (uint itrK = 0; itrK <= N; itrK++) {
        indM = N - itrK;

        c_k = fact(N) / fact(itrK) / fact(indM);
        val = c_k * pow(x, itrK) * pow(y, indM);


        mod4 = indM % 4;
        mod2 = mod4 % 2;
        if (mod2 == 0) {
            if (mod4 == 0) {
                sR += val;
            }
            else {
                sR -= val;
            }
        }
        else if (mod2 == 1) {
            if (mod4 == 1) {
                sI += val;
            }
            else {
                sI -= val;
            }
        }
    }

    in_dat[0] = sR;
    in_dat[1] = sI;
    return;

}


void preF_calc(vector<double> &in_dat, double x, double y, uint N) {
    
    double sR = 0;
    double sI = 0;

    uint indM;
    double c_k, val;
    uint mod2, mod4;

    // Pre-calc values
    vector<uint> f_vec(N+1);
    //vector<double> x_vec(N+1);
    //vector<double> y_vec(N+1);

    f_vec[0] = 1;
    //x_vec[0] = 1;
    //y_vec[0] = 1;
    for (uint itr = 1; itr <= N; itr++) {
        f_vec[itr] = f_vec[itr-1] * (itr);
        //x_vec[itr] = x_vec[itr-1]*x;
        //y_vec[itr] = y_vec[itr-1]*y;
    }




    for (uint itrK = 0; itrK <= N; itrK++) {
        indM = N - itrK;

        c_k = f_vec.back() / f_vec[itrK] / f_vec[indM];
        //val = c_k * x_vec[itrK] * y_vec[indM];
        val = c_k * pow(x, itrK) * pow(y, indM);
        
        mod4 = indM % 4;
        mod2 = mod4 % 2;
        if (mod2 == 0) {
            if (mod4 == 0) {
                sR += val;
            }
            else {
                sR -= val;
            }
        }
        else if (mod2 == 1) {
            if (mod4 == 1) {
                sI += val;
            }
            else {
                sI -= val;
            }
        }
    }

    in_dat[0] = sR;
    in_dat[1] = sI;
    return;

}

// Pixels on inner loop, apply SIMD
void loop_calc(vector<double> &in_dat, double x, double y, uint N) {

    double x_n = x;
    double y_n = y;
    double x_old;

    for (int itr = 0; itr < N-1; itr++) {
        x_old = x_n;
        // Inner Loop
        x_n = (x_n*x - y_n*y);
        y_n = (x_old*y + y_n*x);
    }

    in_dat[0] = x_n;
    in_dat[1] = y_n;

    return;

}


// Pixels on inner loop, apply SIMD
void loop_calcV(vector<double> &zN, vector<double> &cR, vector<double> &cI, uint N) {

    // TODO: try using z0 vector instead of cR, cI -- compare SIMD performance

    double x_n, y_n;
    double x, y;
    double x_old;

    uint Nz = zN.size()/2;
    uint Nr = cR.size();
    uint Ni = cI.size();

    uint ind = 0;
    for (uint itrN = 0; itrN < N-1; itrN++) {
        
        #pragma omp parallel for private(ind)
        for (uint itrR = 0; itrR < Nr; itrR++) {
            x = cR[itrR];
            for (uint itrI = 0; itrI < Ni; itrI++) {
                ind = itrR*Ni + itrI;

                x_n = zN[ind];
                y_n = zN[ind + Nz];
                y = cI[itrI];
                
                zN[ind] = (x_n*x - y_n*y);
                zN[ind + Nz] = (x_n*y + y_n*x);
            }
        }
    }


    return;

}






int main(int argc, char *argv[]) {

    // - Group indices
    //      - Real/Imag
    //      - Pos/Neg
    // - Compute binomial coeffs
    // - Compute z_n

    auto t0 = high_resolution_clock::now();
    auto t1 = high_resolution_clock::now();
    duration<double> dur = t1 - t0;
    map<string, double> time_map;
    time_map["Standard"] = 0;
    //time_map["Naive"] = 0;
    //time_map["PreF"] = 0;
    time_map["Loop"] = 0;
    uint N_run = 100;

    uint N = 5;
    double BL = -1;
    double BU = 1;
    uint N0 = 1000;
    uint Nc = N0*N0;


    // Allocate Loop
    vector<double> real_arr = linspace(BL, BU, N0);
    vector<double> imag_arr = linspace(BL, BU, N0);
    vector<double> zN(2*Nc);
    vector<double> zN0(2*Nc);

    // Allocate Standard
    complex<double> z0;
    vector< complex<double> > zS(Nc);
    vector< complex<double> > zS0(Nc);
    uint ind = 0;
    for (uint itrR = 0; itrR < N0; itrR++) {
        for (uint itrI = 0; itrI < N0; itrI++) {
            zN[ind] = real_arr[itrR];
            zN[ind+Nc] = imag_arr[itrI];
            zS[ind] = complex<double>(real_arr[itrR], imag_arr[itrI]);
            //cout << ind << ": " << zS[ind] << '\t' << "(" << zN[ind] << ", " << zN[ind+Nc] << ")" << endl;

            ind++;
        }
    }

    zS0 = zS;
    zN0 = zN;
    for (uint itrNR = 0; itrNR < N_run; itrNR++) {
        
        zS = zS0; // Reset values
        // Standard Ref
        t0 = high_resolution_clock::now();
        
        for (uint itr = 0; itr < zS.size(); itr++) {
            z0 = zS[itr];
            for (uint itrN = 0; itrN < N-1; itrN++) {
                zS[itr] *= z0;
            }
            //cout << itr << ": " << zS[itr] << endl;
        }
        t1 = high_resolution_clock::now();
        dur = t1 - t0;
        time_map["Standard"] += dur.count();


        // Loop Test
        zN = zN0;
        t0 = high_resolution_clock::now();
        loop_calcV(zN, real_arr, imag_arr, N);
        t1 = high_resolution_clock::now();
        dur = t1 - t0;
        time_map["Loop"] += dur.count();
    }


    // Error test
    double err = 0;
    double this_err = 0;
    for (uint itr = 0; itr < Nc; itr++) {
        z0 = complex<double>(zN[itr], zN[itr + Nc]);
        this_err = abs( z0 - zS[itr] );
        err += this_err;

        //cout << itr << ": " << this_err << '\t' << z0 << '\t' << zS[itr] << endl;
    }


    string comp_str = "Loop";

    for (const auto& [key, value] : time_map) {
            cout << key << ": " << value << endl;
        }
    cout << endl;

    cout << "Total L2 Err: " << err << endl;
    cout << "Ratio (S/M): " << time_map["Standard"] / time_map[comp_str] << endl;


    return 0;
}


/*


    // Runs
    for (uint itrN = 0; itrN < N_run; itrN++) {
        
        // Standard
        t0 = high_resolution_clock::now();
        zP = z0;
        for (uint itr = 0; itr < N-1; itr++) {
            zP *= z0;
        }
        //complex<double> zP = pow(z0, N);
        t1 = high_resolution_clock::now();
        dur = (t1 - t0);
        time_map["Standard"] += dur.count();

        // Naive
        // TODO: fix overflow issue with c_k
        t0 = high_resolution_clock::now();
        naive_calc(in_dat, x, y, N);
        t1 = high_resolution_clock::now();
        dur = (t1 - t0);
        time_map["Naive"] += dur.count();

        // Precalc Factorial
        t0 = high_resolution_clock::now();
        preF_calc(in_dat, x, y, N);
        t1 = high_resolution_clock::now();
        dur = (t1 - t0);
        time_map["PreF"] += dur.count();
        
        // Loop Calc
        t0 = high_resolution_clock::now();
        loop_calc(in_dat, x, y, N);
        t1 = high_resolution_clock::now();
        dur = (t1 - t0);
        time_map["Loop"] += dur.count();
    }
*/