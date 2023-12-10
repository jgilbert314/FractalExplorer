#ifndef INPUTPANEL_H
#define INPUTPANEL_H

#include <QGroupBox>
#include <QLabel>
#include <QScrollArea>

#include <QGridLayout>

#include "lineeditnumber.h"


#include <vector>
#include <iostream> // Testing
using namespace std;

class InputPanel : public QGroupBox
{
    Q_OBJECT
public:
    explicit InputPanel(QGroupBox *parent = nullptr);


    vector<QLabel*> name_list;
    vector<QLabel*> value_list;
    vector<LineEditNumber*> input_list;

    void buildPanel(vector<QString> name_list, vector<char> spec_list);

private:
    QGridLayout* this_layout = new QGridLayout;

};

#endif // INPUTPANEL_H
