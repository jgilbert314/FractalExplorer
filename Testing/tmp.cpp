
#include <vector>
#include <string>
#include <iostream>  // Input/Output
#include <sstream>

#include <map>

using namespace std; // Allow implicit use of standard library

int main(int argc, char *argv[]) {

    
    map<string, double> test;

    struct Test { double val; string name; };
    Test test2;
    cout << "Size struct: " << sizeof(test2) << endl;

    cout << "Size init: " <<  sizeof(test) << endl;
    test["test"] = 10;
    cout << "Size one element: " <<  sizeof(test) << endl;
    
    int N = 100;
    for (int itr = 0; itr < N; itr++) {
        test[std::to_string(itr)] = itr;
    };
    cout << "Size " << N << " elements: " << sizeof(test) << endl;

    return 0;
}