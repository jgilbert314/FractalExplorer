
/*! \file */

// TODO: figure out how to flush left and indent equations

#include <stdexcept> // Error handling
#include <vector>  	 // Defines vector type
#include <complex>	 // Defines complex type
#include <iostream>  // Input/Output


using namespace std;




//////////////////////////////
/// Core Calculation
//////////////////////////////


/*! \fn vector<double> linspace(double bound_L, double bound_U, int N)
	\author Jason Gilbert
	\date February 16, 2020
	\date Last Updated: N/A

	\brief This function calculates a set of equally spaced points within a closed interval
	\param bound_L lower bound of interval
	\param bound_U upper bound of interval
	\param N 	   number of points in set
	\returns output a vector of points in the set
*/
vector<double> linspace(double bound_L, double bound_U, int N) {

	// Throw an error if the interval is improperly defined
	if (bound_L >= bound_U) {
		throw runtime_error( "Upper bound must be greater than lower bound." );
	}
	if (N <= 1) {
		throw invalid_argument( "The number of points must be greater than 1." );
	}

	// Distance between points in set
	double dist = (bound_U - bound_L) / (N - 1); 
	// Calculate points in set
	std::vector<double> output(N);
	for (int itr = 0; itr < N; itr++) {
		// x_n = x_0 + n*(x_f - x_0)/(N - 1)
		output[itr] = bound_L + itr*dist;
	}

	return output;

};



vector<double> mag_calc(vector<double> &Z_vals) {

	int N = Z_vals.size()/2;
	vector<double> m_vals(N);
 
	#pragma omp parallel for
	for (int itr = 0; itr < N; itr++) {
		m_vals[itr] = sqrt(Z_vals[itr]*Z_vals[itr] + Z_vals[itr+N]*Z_vals[itr+N]);
	}

	return m_vals;

};



/*! \fn vector<double> mandelbrot_calcV(vector<double> &r_vals, vector<double> &i_vals, int K)
	\author Jason Gilbert
	\date November, 2023
	\date Last Updated: N/A

	\brief Evaluates \p K iterations of the function \n
		    	    \f$z_{(n+1)} = (z_n)^2 + c\f$ \n
		for a set of complex constants \f$c\f$.
	\param r_vals a vector of doubles, representing the real components \f$c\f$
	\param i_vals a vector of doubles, representing the imaginary components of \f$c\f$
	\param K number of iterations to compute
	\return Z_vals a vector of doubles, representing \f$z_K\f$ for each element of \f$c\f$
			Format: Re(z_n) = Z_vals[ind], Im(z_n) = Z_vals[ind+N] where N is the number of 
			points in \f$c\f$
*/
vector<double> mandelbrot_calcV(vector<double> &r_vals, vector<double> &i_vals, int K) {
    
    int N_R = r_vals.size();
    int N_I = i_vals.size();
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
                Z_vals[ind] = (R_old*R_old - I_old*I_old) + r_vals[itrR];
                // Imag component
                Z_vals[ind+N] = (2*R_old*I_old) + i_vals[itrI];
                }
            }
        }

    return Z_vals;
};


/*! \fn vector<double> pointSet_calcV(vector<double> &r_vals, vector<double> &i_vals, double cR, double cI, int K)
	\author Jason Gilbert
	\date December 01, 2023
	\date Last Updated: N/A

	\brief Evaluates \p K iterations of the function \n
		    	    \f$z_{(n+1)} = (z_n)^2 + c_0\f$ \n
		for a set of complex constants \f$z_n\f$ and complex constant \f$c_0\f$.
	\param r_vals a vector of doubles, representing the real components of \f$z_0\f$
	\param i_vals a vector of doubles, representing the imaginary components of \f$z_0\f$
	\param K number of iterations to compute
	\return Z_vals a vector of doubles, representing \f$z_K\f$ for each element of \f$z_0\f$
			Format: Re(z_n) = Z_vals[ind], Im(z_n) = Z_vals[ind+N] where N is the number of 
			points in \f$z_0\f$
*/
vector<double> pointSet_calcV(vector<double> &r_vals, vector<double> &i_vals, double cR, double cI, int K) {

	int N_R = r_vals.size();
    int N_I = i_vals.size();
    int N = N_R*N_I;
    
    double R_old, I_old;
    int ind;

	// Initialize output (z_0)
	vector<double> Z_vals(2*N);
	#pragma omp parallel for private(ind)
	for (int itrR = 0; itrR < N_R; itrR++) {
		for (int itrI = 0; itrI < N_I; itrI++) {
			ind = itrR*N_I + itrI;
			Z_vals[ind] = r_vals[itrR];
			Z_vals[ind+N] = i_vals[itrI];		
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


//////////////////////////////
/// Visualization
//////////////////////////////

vector<unsigned int> formBitMap(vector<double> z_set) {

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


int printSet(FILE* target_file, int num_R, int num_I, vector< double > m_set) {


	// Print function values to file
	fprintf(stdout, "\n");
	int ind = 0;
	for (int itrR = 0; itrR < num_R; itrR++) {
		// Iterate over all but the last column
		for (int itrI = 0; itrI < num_I-1; itrI++) {
			fprintf(target_file, "%f ", m_set[ind]);
			ind++;
		}
		// Print last column
		fprintf(target_file, "%f", m_set[ind]);
		fprintf(target_file, "\n");
		ind++;
	}

	return 0;

}


//////////////////////////////
/// Deprecated
//////////////////////////////

/*! \fn vector< complex<double> > mandelbrot_calc(vector<complex<double>> c, int N)
	\deprecated std::complex is not easily vectorized by g++, use mandelbrot_calcV instead
	\author Jason Gilbert
	\date March 06, 2020
	\date Last Updated: N/A

	\brief Evaluates \p N iterations of the function \n
		    	    \f$z_{(n+1)} = (z_n)^2 + c\f$ \n
		for a set of complex constants \p c.
	\param c a vector of complex values, representing the complex domain
	\param N number of iterations to compute
	\return a vector of complex values, representing \f$z_N\f$ for each element of \f$c\f$
*/
vector< complex<double> > mandelbrot_calc(vector<complex<double>> c, int N) {

	// Initialize output (z_0 = c)
	vector< complex<double> > output = c;


	// Calcuate one iteration for each element of set
	// Easier to vectorize?
	/*
	for (int itrN = 1; itrN < N; itrN++) {
		for (int itrC = 0; itrC < output.size(); itrC++) {
			if ( !isinf(abs(output[itrC])) ) { // ToDO: would be better to keep list of indices and remove those which overflow -- better vectorization
				output[itrC] = output[itrC]*output[itrC] + c[itrC];
			}
		}
	}
	*/
	

	// Fully iterate each pixel
	// For each complex value, calculate f(c, N) 
	// Loop though c first, to allow each value to be 
	// kept in a smaller object 
	#pragma omp parallel for
    for (uint itrC = 0; itrC < output.size(); itrC++) {
		
		auto this_c = c[itrC];
		auto& this_z = output[itrC];
		// Start at n = 1, since n = 0 is calculated
		// through initialization
		for (int itrN = 1; itrN < N; itrN++) {
			this_z = this_z*this_z + this_c;
			/*
			if ( isinf(abs(this_z)) ) {
				break;
			}
			*/
		}
	}
	
	return output;

}


/*!	\fn vector< complex<double> > point_calc(vector<complex<double>> z_set, complex<double> c_0, int N)
	\author Jason Gilbert
	\date November, 2023

	\deprecated std::complex is not easily vectorized by g++, use point_calcV instead
*/
vector< complex<double> > point_calc(vector<complex<double>> z_set, complex<double> c_0, int N) {

	// Initialize output (z_0 = c)
	vector< complex<double> > output = z_set;

	// Fully iterate each pixel
	// For each complex value, calculate f(c, N) 
	// Loop though c first, to allow each value to be 
	// kept in a smaller object 
	#pragma omp parallel for
    for (uint itrC = 0; itrC < output.size(); itrC++) {
		
		auto& this_z = output[itrC];

        for (int itrN = 1; itrN < N; itrN++) {
			this_z = this_z*this_z + c_0;
		}
	}
	
	return output;

}


/*! \fn vector< complex<double> > rect_domain(double bound_RL, double bound_RU, double bound_IL, double bound_IU, int num_R, int num_I) {
	\author Jason Gilbert
	\date February 16, 2020
	\date Last Updated: N/A

	\brief This function calculates a grid of complex points in the complex plane
	\param bound values defining the boundaries of the
				domain. \n
				_R\--/_I\-- indicates real/imaginary \n
				_\--L/\--U indicates lower/upper
	\param num number of points along each dimension of 
				the grid \n
				_R/_I indicates the real/imaginary dimension
	\return a vector containing the points in the grid. 
	        May be mapped to a rectangle by indexing via: \code{.cpp} rect[indR, indI] = output[ num_R*indR + indI ] \endcode

	\deprecated std::complex is not easily vectorized by g++, replaced by working directly with linspace()
*/
vector< complex<double> > rect_domain(double bound_RL, double bound_RU, double bound_IL, double bound_IU, int num_R, int num_I) {

	// Calculate real parts of domain
	vector<double> real_vals = linspace(bound_RL, bound_RU, num_R);
	// Calculate imaginary parts of domain
	vector<double> imag_vals = linspace(bound_IL, bound_IU, num_I);

	// Initialize domain vector
	int num_pts = num_R*num_I; // Number of points in domain
	vector< complex<double> > output(num_pts);
	// Calculate complex values
	int ind = 0; // TODO: replace with pointer (copying output)
	for (auto& elem_R: real_vals) {
		for (auto& elem_I: imag_vals) {
			output[ind] = complex<double>(elem_R, elem_I);
			ind++;
		}
	}

	return output;

}
