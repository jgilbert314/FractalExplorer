#ifndef INPUTPANEL_H
#define INPUTPANEL_H

#include <QGroupBox>
#include <QLabel>
#include <QScrollArea>

#include <QGridLayout>

#include "widgets/lineeditnumber.h"

#include <vector>
using namespace std;

class InputPanel : public QGroupBox
{
    Q_OBJECT
public:
    explicit InputPanel(QGroupBox *parent = nullptr);


    vector<QLabel*> name_list; ///< Labels for input names
    vector<QLabel*> value_list; ///< Labels for input values
    vector<LineEditNumber*> input_list; ///< Labels for input fields

    /// \todo Convert to constructor -- should take arguments
    void buildPanel(vector<QString> name_list, vector<char> spec_list);

private:
    QGridLayout* this_layout = new QGridLayout;

};

#endif // INPUTPANEL_H
