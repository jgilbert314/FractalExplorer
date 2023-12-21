
#include <vector>
#include <string>
#include <iostream>  // Input/Output
#include <sstream>

using namespace std; // Allow implicit use of standard library

#include <chrono>
using namespace chrono;

//         123456789
#define N 500000000

__global__
void vector_add(float *out, float *a, float *b, int n) {
    for (int itr = 0; itr < n; itr++) {
        out[itr] = a[itr] + b[itr];
    }
}

void vector_addC(float *out, float *a, float *b, int n) {
    for (int itr = 0; itr < n; itr++) {
        out[itr] = a[itr] + b[itr];
    }
}


int main(int argc, char *argv[]) {


    auto t0 = high_resolution_clock::now();
    auto t1 = high_resolution_clock::now();

    float *a, *b, *out;

    // Memory
    uint N_f = sizeof(float);
    a = (float*)malloc(N_f*N);
    b = (float*)malloc(N_f*N);
    out = (float*)malloc(N_f*N);
    uint mem_tot = 3*N_f*N / 1e6;

    // Initialize
    for (int itr = 0; itr < N; itr++) {
        a[itr] = 1.0f;
        b[itr] = 2.0f;
    }

    t0 = high_resolution_clock::now();
    vector_add<<<1, 1>>>(out, a, b, N);
    t1 = high_resolution_clock::now();
    duration<double> countG = (t1 - t0);
    
    t0 = high_resolution_clock::now();
    vector_addC(out, a, b, N);
    t1 = high_resolution_clock::now();
    duration<double> countC = (t1 - t0);

    delete [] a;
    delete [] b;
    delete [] out;

    cout << "Mem: " << mem_tot << endl;
    cout << "CPU: " << countC.count() << endl;
    cout << "GPU: " << countG.count() << endl;
    


    return 0;
}