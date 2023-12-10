#include "inputpanel.h"

InputPanel::InputPanel(QGroupBox *parent)
    : QGroupBox{parent}
{

}



void InputPanel::buildPanel(vector<QString> w_list, vector<char> spec_list) {

    setLayout(this_layout);

    QString name_root = "input_";
    uint N_w = w_list.size();

    name_list.resize(N_w);
    value_list.resize(N_w);
    input_list.resize(N_w);

    QString this_name;
    QLabel* this_label;
    QLabel* this_value;
    QScrollArea* this_scroll;
    LineEditNumber* this_input;
    char this_spec;
    for (uint itr = 0; itr < N_w; itr++) {
        this_name = name_root + w_list[itr];

        // Label
        this_label = new QLabel(this);
        name_list[itr] = this_label;
        this_label->setText(w_list[itr]);
        this_layout->addWidget(this_label, itr, 0, 1, 1);

        // Value
        this_value = new QLabel(this);
        value_list[itr] = this_value;
        this_value->setText("<NULL>");
        this_value->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        this_value->setAutoFillBackground(true);
        // Scroll area containing value
        this_scroll = new QScrollArea(this);
        this_scroll->setWidgetResizable(true);
        this_scroll->setWidget(this_value);
        this_scroll->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        this_scroll->setFixedHeight( 2*this_value->height() );
        this_scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        this_layout->addWidget(this_scroll, itr, 1, 1, 1);

        // Input
        this_input = new LineEditNumber;
        input_list[itr] = this_input;
        this_input->setWhatsThis(w_list[itr]);       
        this_spec = spec_list[itr];
         // Double
        if (this_spec == 'd') {
            this_input->in_type = 1;
            this_input->isSpan = 0;
        }
        // Span
        else if (this_spec == 's') {
            this_input->in_type = 1;
            this_input->isSpan = 1;
        }
        // Integer
        else if (this_spec == 'i') {
            this_input->in_type = 0;
            this_input->isSpan = 0;
        }
        else {
            throw runtime_error("Bad input specification");
        }
        this_layout->addWidget(this_input, itr, 2, 1, 1);

    }


    // Specify Tab Order
    for (uint itr = 0; itr < N_w-1; itr++) {
        setTabOrder(input_list[itr], input_list[itr+1]);
    }

}
