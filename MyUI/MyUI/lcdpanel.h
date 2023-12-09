#ifndef LCDPANEL_H
#define LCDPANEL_H

#include <QGroupBox>
#include <QGridLayout>

#include <QLabel>
#include <QLCDNumber>

#include <string>
#include <vector>

#include <iostream>
using namespace std;

#include <QStyle>
#include <QStyleOption>
#include <QPainter>


class LCDPanel : public QGroupBox
{
    Q_OBJECT
public:
    explicit LCDPanel(QGroupBox *parent = nullptr);

    vector<QLabel*> label_list;
    vector<QLCDNumber*> LCD_list;

    struct LabelLink {
        QLabel* label;
        QLCDNumber* lcd;
    };
    map<string, LabelLink> disp_map;


private:
    QGridLayout* this_layout = new QGridLayout;




signals:

};

#endif // LCDPANEL_H
