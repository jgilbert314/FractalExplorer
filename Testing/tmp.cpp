
#include <vector>
#include <string>
#include <iostream>  // Input/Output
#include <sstream>

using namespace std; // Allow implicit use of standard library

int main(int argc, char *argv[]) {

    
    int N = 1000;
    double test = 0;
    vector<double> testV(N);
    auto full_size = sizeof(testV);
    for (int itr = 0; itr < testV.size(); itr++) {
        testV[itr] = itr*1.0;
        full_size += sizeof(testV[itr]);
    };

    //auto full_size = sizeof(test)*N + sizeof(testV); 

    cout << "Size single: " <<  sizeof(test) << endl;
    cout << "Size vector: " <<  sizeof(testV) << endl;
    cout << "Size contents: " << full_size/1000 << " KB" << endl;

    return 0;
}