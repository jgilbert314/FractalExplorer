#ifndef SETIMAGE_H
#define SETIMAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>
#include <QComboBox>

#include <QString>

#include "widgets/lcdpanel.h"
#include "widgets/inputpanel.h"

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

#include <chrono> // Timing for debugging
using namespace chrono;


/// \todo - Find all accesses of set_param and wrap with setter
/// \todo - Move set calculations to class (?). Might be good to modularize for testing

/*!
 * A class representing a set and its UI components
 * Instances of this class are used to seperate map sets from point sets
*/

class SetImage
{
public:
    SetImage();
    ~SetImage();


    struct SetParam {
        double Ro, ///< Origin on real axis
               Io, ///< Origin on imaginary axis
               Rs, ///< Span of real numbers
               Is; ///< Span of imaginary numbers
        double bound_RL, ///< Lower bound of real numbers (Ro - Rs/2)
               bound_RU, ///< Upper bound of real numbers (Ro + Rs/2)
               bound_IL, ///< Lower bound of imaginary numbers (Io - Rs/2)
               bound_IU; ///< Upper bound of imaginary numbers (Io + Rs/2)
        double cR, ///< Real component of complex constant (used by Point set)
               cI; ///< Imaginary component of complex constant (used by Point set)
        int num_R, ///< Number of points (pixels) along real axis
            num_I, ///< Number of points (pixels) along imaginary axis
            num_K; ///< Number of iterations used to calculate set
        double dR, ///< Distance between points on real axis
               dI; ///< Distance between points on imaginary axis
    };
    // Getters
    bool getCalcFlag() { return updateSetFlag; }
    double getRo() { return set_param.Ro; }
    double getIo() { return set_param.Io; }
    double getRs() { return set_param.Rs; }
    double getIs() { return set_param.Is; }
    double getRL() { return set_param.bound_RL; }
    double getRU() { return set_param.bound_RU; }
    double getIL() { return set_param.bound_IL; }
    double getIU() { return set_param.bound_IU; }
    double getCR() { return set_param.cR; }
    double getCI() { return set_param.cI; }
    uint getNR() { return set_param.num_R; }
    uint getNI() { return set_param.num_I; }
    uint getNK() { return set_param.num_K; }
    // Setters
    //      Doubles
    void setRo(double Ro) { set_param.Ro = Ro; setCalcFlag(true); }
    void setIo(double Io) { set_param.Io = Io; setCalcFlag(true); }
    void setRs(double Rs) { set_param.Rs = Rs; setCalcFlag(true); }
    void setIs(double Is) { set_param.Is = Is; setCalcFlag(true); }
    void setCR(double cR) { set_param.cR = cR; setCalcFlag(true); }
    void setCI(double cI) { set_param.cI = cI; setCalcFlag(true); }
    //      Integers
    void setNR(double num_R) {set_param.num_R = num_R; setCalcFlag(true); };
    void setNI(double num_I) {set_param.num_I = num_I; setCalcFlag(true); };
    void setNK(double num_K) {set_param.num_K = num_K; setCalcFlag(true); };

    void setCalcFlag(bool flag_val) { updateSetFlag = flag_val; } ///< Specifies whether a set should be recalculated \callergraph


    /*! Struct for storing timing data */
    struct TimeData {
        QLabel* names_tag;      ///< Labels for name display
        QLCDNumber* names_val;  ///< LCD for value display
        duration<double> time_val; ///< Result of time measurement
    };


    /*! Label names and values for parameter displays */
    struct DispData {
        QLabel* label_image; ///< Label for displaying set image
        vector<QLabel*> label_dub; ///< Labels for parameter names (doubles)
        vector<QLabel*> label_int; ///< Labels for parameter names (ints)
        vector<double> label_dubvals; ///< Labels for parameter values (doubles)
        vector<int*> label_intvals; ///< Labels for parameter values (ints)
        QLabel* label_outputMsg; ///< Label for displaying program output (ex: error messages)

        map<string, TimeData> time_data; ///< Maps display widgets to timing data

        vector<void (SetImage::*)(double)> label_dubsets; ///< List of setters used to access set parameters
        vector<double (SetImage::*)(void)> label_dubgets; ///< List of getters used to access set parameters
    };
    DispData disp_data;


    /*! Label names for parameter input */
    struct ParamInput {
        vector<LineEditNumber*> input_dub;
        vector<LineEditNumber*> input_int;
    };
    ParamInput param_input;


    /*! Vectors storing real/imaginary components of image coordinates */
    struct AxesData {
        vector<double> r_vals;
        vector<double> i_vals;
    };
    AxesData axes_data;


    // Set Calculations
    virtual void calcSet();
    virtual vector<double> setFunc();
    vector<double> mandelbrot_calc();
    vector<double> julia_calc();
    // Intermediate calculations
    vector<double> mag_calc(vector<double> &Z_vals); ///< Calculates magnitudes of N complex numbers stored in 2N long vector
    void linspace(vector<double> &lin_vec, double bound_L, double bound_U, uint N); ///< Calculates vector of N equally spaced points


    // UI Functions
    void updateParamDisp(); ///< Updates display of set parameters
    void updateTimeDisplayElem(string field); ///< Updates single time display
    void updateTimeDisplay(); ///< Updates array of time displays
    void readParamInput();    ///< Reads parameters from user input

    void linkLCDTime();
    void linkTextInput();

    // UI Elements
    LCDPanel* lcdPanel; ///< Panel used for timing display
    InputPanel* inputPanel; ///< Panel used for user input
    QComboBox* colourSelect; ///< Menu for selecting colours



    // Coordinate functions
    void calcSpanCoords(); ///< Updates bounds from center-span coordinates
    void updateDelC(); ///< Updates the delta values for each axis
    void panImage(double scaleR, double scaleI); ///< Translates the images origin
    void zoomImage(double scale); ///< Scales and updates span coordinates


    // Pixel/c-constant functions
    vector<double> calcConstFromInd(int nR, int nI); ///< Calculates constant value from axis index
    vector<double> pixelToConst(QWidget* im_target); ///< Converts pixel location from image to corresponding complex constant


    // Image Functions
    void updateImage(vector<unsigned int> &b_set);
    vector<uint> formBitMap(vector<double> z_set); ///< Calculates bitmap values from complex values
    vector<QColor> calcHSV(int s_val, int v_val, int N);   ///< Calculates HSV colour palette

    /*! Pointer to set calculation function -- configurable */
    vector<double> (SetImage::*setDefFunc)(); ///< \todo Create subclasses of SetImage (map and point) -- one for each set function?

    bool colrFlag; // TESTING - colour
    void updatePalette(QString in_text); // TESTING - colour

private:
    /*! Specifies if a set should be updated. Controlled by setter */
    bool updateSetFlag;
    SetParam set_param; // Parameters private to track modification requiring updates


};

#endif // SETIMAGE_H
