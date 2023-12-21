#ifndef MANDELBROTSET_H
#define MANDELBROTSET_H

#include "setimage.h"

class MandelbrotSet : public SetImage
{
public:
    MandelbrotSet();

    virtual vector<double> setFunc() override;
    //virtual void calcSet() override;
};

#endif // MANDELBROTSET_H
