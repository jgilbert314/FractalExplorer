#include "lcdpanel.h"

// Dec 7, 2023

LCDPanel::LCDPanel(QGroupBox *parent)
    : QGroupBox{parent}
{
    setLayout(this_layout);

    // LCD Background colour
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);

    QString root_name = "calcLabel_";                      // Object name root
    vector<QString> name_suff{"u", "calc", "bit", "imag"}; // Object name suffix
    vector<QString> label_text{"Update", "Calc", "Bitmap", "Image"};
    ///< \todo create explicit link to data represented by key_list strings
    vector<string> key_list{"update", "calc", "bitmap", "image"}; // Keys for map

    uint N_w = name_suff.size(); // Number of LCD displays (rows)

    // Allocate lists
    label_list.resize(N_w);
    LCD_list.resize(N_w);

    QString w_name; // Widget object name
    QLabel* this_label;
    QLCDNumber* this_LCD;
    for (uint itr = 0; itr < N_w; itr++) {
        w_name = root_name + name_suff[itr];

        // LCD Labels
        label_list[itr] = new QLabel(this);
        this_label = label_list[itr];
        this_label->setText(label_text[itr]);
        this_label->setObjectName(w_name);
        this_label->setAutoFillBackground(true);
        this_layout->addWidget(this_label, itr, 0, 1, 1);
        disp_map[key_list[itr]].label = this_label;

        // LCD Numbers
        this_LCD = new QLCDNumber(this);
        this_LCD->setObjectName(w_name + "_V");
        this_LCD->setAutoFillBackground(true);
        this_LCD->setPalette(pal);
        LCD_list[itr] = this_LCD;
        this_layout->addWidget(this_LCD, itr, 1, 1, 1);
        disp_map[key_list[itr]].lcd = this_LCD;
    }
}


