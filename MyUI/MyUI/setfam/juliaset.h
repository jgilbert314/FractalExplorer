#ifndef JULIASET_H
#define JULIASET_H

#include "setimage.h"

class JuliaSet : public SetImage
{
public:
    JuliaSet();

    virtual vector<double> setFunc() override;
    //virtual void calcSet() override;
};

#endif // JULIASET_H
