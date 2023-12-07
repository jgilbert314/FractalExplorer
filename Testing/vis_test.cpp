

#include <iostream>  // Input/Output
using namespace std; // Allow implicit use of standard library

#include "AuxiliaryCode.h" // Defines auxiliary functions

#include <chrono> // Timing library
using namespace chrono;

#include <map>

// OpenGL
//#include <GL/glew.h>
#include <GL/freeglut.h>



vector<unsigned int> formBitMap(vector<complex<double>> z_set) {

    // Calculate image height values
    double max_val = 0;
    vector<double> m_set;
    m_set.resize( z_set.size() );
    for (int itr = 0; itr < z_set.size(); itr++) {
        m_set[itr] = exp( -abs(z_set[itr]) );
        if (m_set[itr] > max_val) {
            max_val = m_set[itr];
        }
    };
    
    // Convert to bit values
    vector<unsigned int> b_set;
    b_set.resize( z_set.size() );
    for (int itr = 0; itr < m_set.size(); itr++) {
        b_set[itr] = (m_set[itr] / max_val)*255;
    }

    return b_set;
}


void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}




int main(int argc, char** argv) {

    double bound_RL = -2;
    double bound_RU =  2;
    double bound_IL = -2;
    double bound_IU =  2;
    int num_R = 100;
    int num_I = 100;
    int num_k = 100;

    int N = num_R*num_I;

    map<std::string, duration<double> > time_map; // For storing run times
    auto t0 = high_resolution_clock::now();
    auto t1 = high_resolution_clock::now();

    vector< complex<double> > c_set = rect_domain(bound_RL, bound_RU, bound_IL, bound_IU, num_R, num_I);
    t0 = high_resolution_clock::now();
    vector< complex<double> > z_set = mandelbrot_calc(c_set, num_k);
    t1 = high_resolution_clock::now();
    time_map["z_ser"] = t1 - t0;

    vector<unsigned int> b_set = formBitMap(z_set);

    vector<unsigned int> tex_dat;
    tex_dat.resize( b_set.size()*3 );
    int ind = 0;
    for (int itr = 0; itr < b_set.size(); itr++) {
        tex_dat[ind] = b_set[itr];
        tex_dat[ind+1] = b_set[itr];
        tex_dat[ind+2] = b_set[itr];
        ind += 3;
    }


    // Print test
    for (int itrR = 0; itrR < num_R; itrR++) {
        for (int itrI = 0; itrI < num_I; itrI++) {
            ind = itrR*num_I + itrI;
            if (b_set[ind] == 0) {
                cout << 0;
            }
            else {
                cout << 1;
            }
            cout << " ";
        }
        cout << endl;
    }

    // OpenGL Test
    /*
    glTexImage2D(
    GL_TEXTURE_2D, 0,
    GL_RGB, num_R, num_I, 0,
    GL_RGB, GL_UNSIGNED_BYTE, &tex_dat[0]
    );
    */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mandelbrot Test");
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
            glTexImage2D(
            GL_TEXTURE_2D, 0,
            GL_RGB, num_R, num_I, 0,
            GL_RGB, GL_UNSIGNED_BYTE, &tex_dat[0]
            );
        glEnd();
        glFlush();
    glutMainLoop();
    return 0;


    // Write times
    for (const auto& [key, value] : time_map) {
        cout << key << ": " << value.count() << endl;
    }
    cout << endl;
    return 0;

}