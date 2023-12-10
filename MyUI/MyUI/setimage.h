#ifndef SETIMAGE_H
#define SETIMAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>

#include <QString>

#include "lcdpanel.h"
#include "inputpanel.h"

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

#include <chrono> // Timing for debugging
using namespace chrono;


//! A class representing a set and its UI components
/*!
 * Instances of this class are used to seperate map sets from point sets
*/


class SetImage
{
public:
    SetImage();


    struct SetParam {
        double Ro, Io, Rs, Is;
        double bound_RL, bound_RU, bound_IL, bound_IU;
        double cR, cI;
        int num_R, num_I, num_K;
        double dR, dI;
    };
    // Getters
    double& getRo() { return set_param.Ro; }
    double& getIo() { return set_param.Io; }
    double& getRs() { return set_param.Rs; }
    double& getIs() { return set_param.Is; }
    double& getCR() { return set_param.cR; }
    double& getCI() { return set_param.cI; }
    double& getBRL() { return set_param.bound_RL; }
    double& getBRU() { return set_param.bound_RU; }
    double& getBIL() { return set_param.bound_IL; }
    double& getBIU() { return set_param.bound_IU; }
    int& getNR() { return set_param.num_R; }
    int& getNI() { return set_param.num_I; }
    int& getNK() { return set_param.num_K; }
    bool getCalcFlag() { return updateSetFlag; }
    // Setters
    void setRo(double Ro) { set_param.Ro = Ro; updateSetFlag = 1; }
    void setIo(double Io) { set_param.Io = Io; updateSetFlag = 1; }
    //void setRs(double Rs) { set_param.Rs = Rs; }
    //void setIs(double Is) { set_param.Is = Is; }
    void setCR(double cR) { set_param.cR = cR; updateSetFlag = 1; }
    void setCI(double cI) { set_param.cI = cI; updateSetFlag = 1; }
    /*! Specifies whether a set should be recalculated
     *  \callergraph */
    void setCalcFlag(bool flag_val) { updateSetFlag = flag_val; }


    /*! Struct for storing timing data */
    struct TimeData {
        QLabel* names_tag;  // Labels for name display
        QLCDNumber* names_val; // Labels for value display
        duration<double> time_val; // Result of time measurement
    };


    /*! Label names and values for parameter displays */
    struct DispData {
        QLabel* label_image;
        vector<QLabel*> label_dub;
        vector<QLabel*> label_int;
        vector<double*> label_dubvals;
        vector<int*> label_intvals;
        QLabel* label_outputMsg;

        map<string, TimeData> time_data; // TODO: setter function
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


    void initImage(char set_type);


    // Set Calculations
    void calcSet();
    vector<double> mandelbrot_calc();
    vector<double> julia_calc();
    // Intermediate calculations
    vector<double> mag_calc(vector<double> &Z_vals);
    void linspace(vector<double> &lin_vec, double bound_L, double bound_U, uint N);


    // UI Functions
    void updateParamDisp();
    void updateTimeDisplayElem(string field);
    void updateTimeDisplay();
    void readParamInput();

    void linkLCDTime();
    void linkTextInput();

    // UI Elements
    LCDPanel lcdPanel_main;
    LCDPanel* lcdPanel = &lcdPanel_main;
    InputPanel inputPanel_main;
    InputPanel* inputPanel = &inputPanel_main;


    // Coordinate functions
    /*! Updates bounds from center-span coordinates */
    void calcSpanCoords();
    /*! Updates the delta values for each axis */
    void updateDelC();
    /*! Scales and updates span coordinates */
    void zoomImage(double scale);


    // Pixel/c-constant functions
    vector<double> calcConstFromInd(int nR, int nI);
    vector<double> pixelToConst(QWidget* im_target);


    // Image Functions
    void updateImage(vector<unsigned int> &b_set);
    vector<unsigned int> formBitMap(vector<double> z_set);
    vector<QColor> calcHSV(int s_val, int v_val, int N);

    /*! Pointer to set calculation function -- configurable */
    vector<double> (SetImage::*setDefFunc)(); // TODO: create subclasses of SetImage (map and point) -- one for each set function?

private:
    /*! Specifies if a set should be updated. Controlled by setter */
    bool updateSetFlag;
    SetParam set_param; // Parameters private to track modification requiring updates


};

#endif // SETIMAGE_H
