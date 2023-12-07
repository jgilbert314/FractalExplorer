/*! \file */

#include <mpi.h>
#include <stdio.h>

#include "AuxiliaryCode.h" // Defines auxiliary functions
#include <iostream>  // Input/Output
#include <fstream>	 // File Read/Write
#include <chrono> // Timing library

using namespace std; // Allow implicit use of standard library
using namespace std::chrono; // Implicit use of chrono


/*! \fn main */
int main(int argc, char *argv[]) {

	map<std::string, duration<double> > time_map; // For storing run times
	const int arg_num = 9; // Number of input arguments expected

	// Start MPI
	auto t0 = high_resolution_clock::now();
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
	auto t1 = high_resolution_clock::now();
	time_map["MPI_init"] = t1 - t0;

	
	
	bool run_flag = 1; // Should flip to 0 after all lines have been read from stdin
	string parse_str;  // Holds each line from stdin
	bool default_flag = 0;
	if (std::getline(cin, parse_str)) {
	} else {
		default_flag = 1;
	}
	while( run_flag ) {

		auto t00 = high_resolution_clock::now(); // Start clock on primary program (exludes output writing)
		// Define variables (user input)
		double bound_RL;
		double bound_RU;
		double bound_IL;
		double bound_IU;
		int num_R;
		int num_I;
		int num_k;




		// Initialize program parameters	
		if (rank == 0) {

			if (default_flag) {
				bound_RL = -2;
				bound_RU =  2;
				bound_IL = -2;
				bound_IU =  2;
				num_R = 100;
				num_I = 100;
				num_k = 100;
			}
			else {

				// Parse user input --> convert to function
				// TODO: add timer for parsing
				vector<string> arg_vec(arg_num);

				int pos = 0;
				string delim = ",";
				string arg_str; 

				int ind = 0;
				while ( (pos = parse_str.find(delim)) != string::npos ) {
					arg_str = parse_str.substr(0, pos);
					arg_vec[ind] = arg_str;
					parse_str.erase(0, pos + delim.length());
					ind++;
				}

				// Convert arguments to appropriate datatypes
				// TODO: change to store pointers in array, Bcast via looping array
				//const int output_mode = stoi(argv[1]); // TODO: implement input parsing
				//char target_filename[] = argv[2];      // TODO: implement input parsing
				bound_RL = stof(arg_vec[2]);
				bound_RU =  stof(arg_vec[3]);
				bound_IL = stof(arg_vec[4]);
				bound_IU =  stof(arg_vec[5]);
				num_R = stoi(arg_vec[6]);
				num_I = stoi(arg_vec[7]);
				num_k = stoi(arg_vec[8]);
			}
		}
		MPI_Bcast(&bound_RL, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&bound_RU, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&bound_IL, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&bound_IU, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&num_R, 1, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&num_I, 1, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&num_k, 1, MPI_INT, 0, MPI_COMM_WORLD);
		 

		// Begin program
		// 		Input: param ranges
		//		Output: times

		// IO Parameters
		const int output_mode = 0; // 0 for stdout, 1 for file        // FIX - implement input parsing
		char target_filename[] = "test.txt"; // Filename for writing  // FIX - implement input parsing

		FILE* target_file; // TODO: check what this means
		char buffer [256];

		// Computational Variables
		int N = num_R*num_I; // Number of points in sets c and z
		int elem_per_proc = N/size;
		t0 = high_resolution_clock::now();
		vector< complex<double> > c_set;
		vector< complex<double> > c_loc;
		vector< complex<double> > z_set;
		vector< complex<double> > z_loc;
		vector<double> m_set; // Magnitudes of z_set 

		c_loc.resize(elem_per_proc);
		z_loc.resize(elem_per_proc);
		t1 = high_resolution_clock::now();
		time_map["Variable_Init"] = t1 - t0;


		// Run and time
		t0 = high_resolution_clock::now();
		if (rank == 0) {
			c_set = rect_domain(bound_RL, bound_RU, bound_IL, bound_IU, num_R, num_I);
			z_set.resize(N);
			m_set.resize(N);
		}
		t1 = high_resolution_clock::now();
		time_map["Domain_Init"] = t1 - t0;

		t0 = high_resolution_clock::now();
		// Send Constants
		MPI_Scatter(
			c_set.data(), elem_per_proc, MPI_DOUBLE_COMPLEX, c_loc.data(),
			elem_per_proc, MPI_DOUBLE_COMPLEX, 0, MPI_COMM_WORLD
		);
		// Send addresses for output
		MPI_Scatter(
			z_set.data(), elem_per_proc, MPI_DOUBLE_COMPLEX, z_loc.data(),
			elem_per_proc, MPI_DOUBLE_COMPLEX, 0, MPI_COMM_WORLD
		);
		t1 = high_resolution_clock::now();
		time_map["Scatter"] = t1 - t0;

		// Calculate set
		t0 = high_resolution_clock::now();
		z_loc = mandelbrot_calc(c_loc, num_k);
		t1 = high_resolution_clock::now();
		time_map["Set_Calc"] = t1 - t0;


		// Gather result
		t0 = high_resolution_clock::now();
		MPI_Gather(
			z_loc.data(), elem_per_proc, MPI_DOUBLE_COMPLEX, z_set.data(),
			elem_per_proc, MPI_DOUBLE_COMPLEX, 0, MPI_COMM_WORLD
		);
		t1 = high_resolution_clock::now();
		time_map["Gather"] = t1 - t0;

		
		if (rank == 0) {
			// Calc mags
			// TODO: parallellize (?) -- seems to extremely fast in serial, performance gain unlikely
			if (rank == 0)
			t0 = high_resolution_clock::now();
			for (int itr = 0; itr < z_set.size(); itr++) {
				m_set[itr] = abs( z_set[itr] );
			};
			t1 = high_resolution_clock::now();
			time_map["Mag"] = t1 - t0;


			auto tff = high_resolution_clock::now();
			time_map["Exec"] = tff - t00; // Execution time
			

			// Printing Output
			t0 = high_resolution_clock::now(); // Start clock for printings
			// TODO: refactor to wrap file writing in flag statement
			if (output_mode == 0) {
				target_file = stdout;
			} else if (output_mode == 1) {
				target_file = fopen(target_filename, "w+"); // Open file
				if (!target_file) { // Exit if file failed to open
					return -1;
				}
			}

			// Write set
			//printSet(target_file, num_R, num_I, m_set); // TESTING - uncomment
			t1 = high_resolution_clock::now();
			time_map["Print"] = t1 - t0;

			// Write times
			for (const auto& [key, value] : time_map) {
				cout << key << "---" << value.count() << " ";
			}
			cout << endl;
		}

		// Check for further input
		MPI_Barrier(MPI_COMM_WORLD);
		if (rank == 0) {
			if (std::getline(cin, parse_str)) { // Update parse_str, check of EOF
			}
			else {
				run_flag = 0;
			}
		}
		MPI_Bcast(&run_flag, 1, MPI_CXX_BOOL, 0, MPI_COMM_WORLD); // Update all ranks on program status
	}



	MPI_Finalize();
	return 0;
}
