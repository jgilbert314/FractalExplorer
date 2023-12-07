

#include <iostream>  // Input/Output
using namespace std; // Allow implicit use of standard library

#include "AuxiliaryCode.h" // Defines auxiliary functions

#include <chrono> // Timing library
using namespace chrono;

#include <omp.h> // Shared memory parallelism

#include <map>


vector< complex<double> > mandelbrot_calcS(vector<complex<double>> c, int N) {

	// Initialize output (z_0 = c)
	vector< complex<double> > output = c;

	for (int itrC = 0; itrC < output.size(); itrC++) {
		
		auto this_c = c[itrC];
		auto& this_z = output[itrC];
		// Start at n = 1, since n = 0 is calculated
		// through initialization
		for (int itrN = 1; itrN < N; itrN++) {
			this_z = this_z*this_z + this_c;
		}
	}
	
	return output;

}


vector< complex<double> > mandelbrot_calcP(vector<complex<double>> c, int K) {
    
    vector< complex<double> > output = c;

    #pragma omp parallel for
        for (int itrC = 0; itrC < c.size(); itrC++) {
            // Start at n = 1, since n = 0 is calculated
            // through initialization
            for (int itrK = 1; itrK < K; itrK++) {
                output[itrC] = output[itrC]*output[itrC] + c[itrC];
            }
        }

    return output;
};


vector< complex<double> > mandelbrot_calcV(vector<complex<double>> c, int K) {
    
    vector< complex<double> > output = c;

    // Start at n = 1, since n = 0 is calculated
    // through initialization
    for (int itrK = 1; itrK < K; itrK++) {
        #pragma omp simd
        for (int itrC = 0; itrC < c.size(); itrC++) {
                output[itrC] *= output[itrC];
                output[itrC] += c[itrC];
        }
    }

    return output;
};


vector<double> mandelbrot_calcN(vector<double> &r_vals, vector<double> &i_vals, int K) {
    
    int N_R = r_vals.size();
    int N_I = i_vals.size();
    int N = N_R*N_I;
    
    double R_old, I_old;
    int ind;

    vector<double> Z_vals(2*N);

    #pragma omp parallel for simd
        for (int itrR = 0; itrR < N_R; itrR++) {
            for (int itrI = 0; itrI < N_I; itrI++) {
                // Start at n = 1, since n = 0 is calculated
                // through initialization
                ind = itrR*N_I + itrI;
                for (int itrK = 1; itrK < K; itrK++) {
                    R_old = Z_vals[ind];
                    I_old = Z_vals[ind+N];

                    // Real component
                    Z_vals[ind] = (R_old*R_old - I_old*I_old) + r_vals[itrR];
                    // Imag component
                    Z_vals[ind+N] = (2*R_old*I_old) + i_vals[itrI];
                }
            }
        }

    return Z_vals;
};


vector<double> mandelbrot_calcNC(vector<double> &r_vals, vector<double> &i_vals, int K) {
    
    int N_R = r_vals.size();
    int N_I = i_vals.size();
    int N = N_R*N_I;
    
    double R_old, I_old;
    int ind = 0;

    vector<double> Z_vals(2*N);

    #pragma omp parallel for simd
        for (int itrR = 0; itrR < N_R; itrR++) {
            for (int itrI = 0; itrI < N_I; itrI++) {
                ind = 2*(itrR*N_I + itrI);
                for (int itrK = 0; itrK < K; itrK++) {
                    R_old = Z_vals[ind];
                    I_old = Z_vals[ind+1];

                    // Real component
                    Z_vals[ind] = (R_old*R_old - I_old*I_old) + r_vals[itrR];
                    // Imag component
                    Z_vals[ind+1] = (2*R_old*I_old) + i_vals[itrI];
                }
            }
        }
    

    return Z_vals;
};



vector<double> mandelbrot_calcNV(vector<double> &r_vals, vector<double> &i_vals, int K) {
    
    int N_R = r_vals.size();
    int N_I = i_vals.size();
    int N = N_R*N_I;
    
    double R_old, I_old;
    int ind;

    vector<double> Z_vals(2*N);

    for (int itrK = 1; itrK < K; itrK++) {
    #pragma omp parallel for simd
        for (int itrR = 0; itrR < N_R; itrR++) {
            for (int itrI = 0; itrI < N_I; itrI++) {
                // Start at n = 1, since n = 0 is calculated
                // through initialization
                ind = itrR*N_I + itrI;
                
                R_old = Z_vals[ind];
                I_old = Z_vals[ind+N];

                // Real component
                Z_vals[ind] = (R_old*R_old - I_old*I_old) + r_vals[itrR];
                // Imag component
                Z_vals[ind+N] = (2*R_old*I_old) + i_vals[itrI];
                }
            }
        }

    return Z_vals;
};



vector<double> mandelbrot_calcNVC(vector<double> &r_vals, vector<double> &i_vals, int K) {
    
    int N_R = r_vals.size();
    int N_I = i_vals.size();
    int N = N_R*N_I;
    
    double R_old, I_old;
    int ind = 0;

    vector<double> Z_vals(2*N);

    for (int itrK = 0; itrK < K; itrK++) {
        #pragma omp parallel for simd
        for (int itrR = 0; itrR < N_R; itrR++) {
            for (int itrI = 0; itrI < N_I; itrI++) {
                ind = 2*(itrR*N_I + itrI);
                
                R_old = Z_vals[ind];
                I_old = Z_vals[ind+1];

                // Real component
                Z_vals[ind] = (R_old*R_old - I_old*I_old) + r_vals[itrR];
                // Imag component
                Z_vals[ind+1] = (2*R_old*I_old) + i_vals[itrI];
                }
            }
        }
    

    return Z_vals;
};



vector<double> mag_calcNVC(vector<double> &Z_vals) {

	int N = Z_vals.size()/2;
	vector<double> m_vals(N);
    
    int ind;
	#pragma omp parallel for simd
	for (int itr = 0; itr < N; itr++) {
        ind = itr*2;
		m_vals[itr] = sqrt(Z_vals[ind]*Z_vals[ind] + Z_vals[ind+1]*Z_vals[ind+1]);
	}

	return m_vals;

};




int main() {

    double bound_RL = -2;
    double bound_RU =  2;
    double bound_IL = -2;
    double bound_IU =  2;
    int num_R = 1000;
    int num_I = 1000;
    int num_k = 100;

    int N = num_R*num_I;

    int N_procs = omp_get_num_procs();
    int N_threads = omp_get_num_threads();
    int N_spec = 16;
    omp_set_num_threads(N_spec);

    map<std::string, duration<double> > time_map; // For storing run times
    auto t0 = high_resolution_clock::now();
    auto t1 = high_resolution_clock::now();

    vector< complex<double> > c_set = rect_domain(bound_RL, bound_RU, bound_IL, bound_IU, num_R, num_I);
    vector<double> r_vals = linspace(bound_RL, bound_RU, num_R);
    vector<double> i_vals = linspace(bound_IL, bound_IU, num_I);

    t0 = high_resolution_clock::now();
    vector< complex<double> > z_set = mandelbrot_calcS(c_set, num_k);
    t1 = high_resolution_clock::now();
    time_map["z_ser"] = t1 - t0;

    
    // Parallel
    t0 = high_resolution_clock::now();
    vector< complex<double> > z_setP = mandelbrot_calcP(c_set, num_k);
    t1 = high_resolution_clock::now();
    time_map["z_par"] = t1 - t0;

    // Vectorized
    t0 = high_resolution_clock::now();
    vector< complex<double> > z_setV = mandelbrot_calcV(c_set, num_k);
    t1 = high_resolution_clock::now();
    time_map["z_vec"] = t1 - t0;

    // Vectorized (double)
    t0 = high_resolution_clock::now();
    vector<double> z_setN = mandelbrot_calcN(r_vals, i_vals, num_k);
    t1 = high_resolution_clock::now();
    time_map["N_vec"] = t1 - t0;

    // Vectorized (double, complex pairs)
    t0 = high_resolution_clock::now();
    vector<double> z_setC = mandelbrot_calcNC(r_vals, i_vals, num_k);
    t1 = high_resolution_clock::now();
    time_map["C_vec"] = t1 - t0;

    // Vectorized (double, outer loop)
    t0 = high_resolution_clock::now();
    vector<double> z_setNV = mandelbrot_calcV(r_vals, i_vals, num_k);
    t1 = high_resolution_clock::now();
    time_map["K_vec"] = t1 - t0;

    // Vectorized (double, complex pairs, outer loop)
    t0 = high_resolution_clock::now();
    vector<double> z_setNVC = mandelbrot_calcNVC(r_vals, i_vals, num_k);
    t1 = high_resolution_clock::now();
    time_map["P_vec"] = t1 - t0;

    
    // Serial
    t0 = high_resolution_clock::now();
    vector<double> m_setS(N);
    int itr;
    for (itr = 0; itr < z_set.size(); itr++) {
        m_setS[itr] = abs( z_set[itr] );
    };
    t1 = high_resolution_clock::now();
    time_map["m_ser"] = t1 - t0;

    // Parallel
    t0 = high_resolution_clock::now();
    vector<double> m_setP(N);
    #pragma omp parallel for simd
        for (itr = 0; itr < z_set.size(); itr++) {
            m_setP[itr] = abs( z_set[itr] );
        };
    t1 = high_resolution_clock::now();
    time_map["m_par"] = t1 - t0;

    // Mag Double
    t0 = high_resolution_clock::now();
    vector<double> m_setNV = mag_calc(z_setNV);
    t1 = high_resolution_clock::now();
    time_map["m_DNV"] = t1 - t0;

    // Mag Double (pairs)
    t0 = high_resolution_clock::now();
    vector<double> m_setNVC = mag_calcNVC(z_setNVC);
    t1 = high_resolution_clock::now();
    time_map["m_NVC"] = t1 - t0;


    cout << "Number of processors: " << N_spec << endl;
    // Write times
    for (const auto& [key, value] : time_map) {
        cout << key << ": " << value.count() << endl;
    }
    cout << endl;


    /*
    vector<unsigned int> b_set = formBitMap(z_setNV);
    
    int ind = 0;
    double mag_val;
    double max_val = 0;
    for (int itrR = 0; itrR < num_R; itrR++) {
        for (int itrI = 0; itrI < num_I; itrI++) {
            //ind = (itrR*num_I + itrI);

            mag_val = exp(-m_setNV[ind] );


            cout << b_set[ind] << " ";
            
            if ( isnan(mag_val) ) { 
                cout << 0 << " ";
            } 
            else {
                cout << 1 << " ";
            }
            
            ind++;
        }
        cout << endl;
        
    }
    */
    
    
    


    return 0;

}