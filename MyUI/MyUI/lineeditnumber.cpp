#include "lineeditnumber.h"

LineEditNumber::LineEditNumber(QLineEdit *parent)
    : QLineEdit{parent}
{

    // Integer by default
    in_type = 0;
    isSpan = 0;

}


void LineEditNumber::checkInput() {

    QString in_str;
    bool convert_flag;
    QString err_msg;

    in_str = text();


    // Check if input is a number
    in_str.toDouble(&convert_flag);
    if (!convert_flag) {
        err_msg = whatsThis() + " must be a number";
        throw invalid_argument(err_msg.toStdString());
    }

    // Check integer bounds
    if (in_type == 0) {
        int val = in_str.toInt(&convert_flag);
        if (val <= 1) {
            err_msg = whatsThis() + " must be > 1";
            throw invalid_argument(err_msg.toStdString());
        }
    }
    // Check span bounds
    else if (in_type == 1) {
        double val = in_str.toDouble(&convert_flag);
        if ( (isSpan) && (val <= 0) ) {
            err_msg = whatsThis() + " must be >= 0";
            throw invalid_argument(err_msg.toStdString());
        }
    }
    else {
        throw runtime_error("Bad LineEdit type");
    }


    return;

}


