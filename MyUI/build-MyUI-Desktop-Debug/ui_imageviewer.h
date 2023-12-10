/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QLabel *label_outputM;
    QLabel *label_outputP;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QFormLayout *formLayout;
    QWidget *tab_2;
    QFormLayout *formLayout_3;
    QGroupBox *diagBoxM;
    QGridLayout *gridLayout_3;
    QLabel *calcLabelM_calc;
    QLabel *calcLabelM_bit;
    QLCDNumber *calcLabelM_u_V;
    QLabel *calcLabelM_imag;
    QLabel *calcLabelM_u;
    QLCDNumber *calcLabelM_imag_V;
    QLCDNumber *calcLabelM_calc_V;
    QLCDNumber *calcLabelM_bit_V;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBoxM;
    QGridLayout *gridLayout;
    QLabel *label_M_Ro;
    QLineEdit *lineEdit_M_Rs;
    QLabel *label_M_Is;
    QLineEdit *lineEdit_M_NR;
    QSpacerItem *verticalSpacer;
    QLabel *label_M_NK;
    QLabel *label_M_RsV;
    QLabel *label_M_NIV;
    QLabel *label_M_IoV;
    QLineEdit *lineEdit_M_Io;
    QLineEdit *lineEdit_M_Is;
    QLineEdit *lineEdit_M_NK;
    QPushButton *updateButton;
    QLabel *label_M_NI;
    QLabel *label_M_NRV;
    QLabel *label_M_Rs;
    QLabel *label_M_NKV;
    QLineEdit *lineEdit_M_NI;
    QLabel *label_M_IsV;
    QLineEdit *lineEdit_M_Ro;
    QLabel *label_M_RoV;
    QLabel *label_M_Io;
    QLabel *label_M_NR;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_colourPalette;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QFormLayout *formLayout_2;
    QWidget *tab_4;
    QFormLayout *formLayout_4;
    QGroupBox *diagBoxP;
    QGridLayout *gridLayout_5;
    QLabel *calcLabelP_u;
    QLCDNumber *calcLabelP_u_V;
    QLabel *calcLabelP_calc;
    QLCDNumber *calcLabelP_calc_V;
    QLabel *calcLabelP_bit;
    QLCDNumber *calcLabelP_bit_V;
    QLabel *calcLabelP_imag;
    QLCDNumber *calcLabelP_imag_V;
    QSpacerItem *verticalSpacer_4;
    QScrollArea *scrollAreaP;
    QWidget *labelP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *imageLabelP;
    QGroupBox *groupBoxP;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_P_Ro;
    QLabel *label_P_RoV;
    QLabel *label_P_NKV;
    QLabel *label_P_Is;
    QLabel *label_P_IsV;
    QLineEdit *lineEdit_P_NK;
    QLabel *label_NI;
    QLineEdit *lineEdit_P_NR;
    QLabel *label_P_cR;
    QLineEdit *lineEdit_P_cR;
    QLabel *label_P_NIV;
    QLineEdit *lineEdit_P_Io;
    QLabel *label_P_NRV;
    QLabel *label_P_CrV;
    QLineEdit *lineEdit_P_Is;
    QLineEdit *lineEdit_P_Rs;
    QLineEdit *lineEdit_P_cI;
    QLabel *label_P_Ro;
    QLabel *label_P_cI;
    QLineEdit *lineEdit_P_NI;
    QLabel *label_NK;
    QLabel *label_P_IoV;
    QLabel *label_P_Io;
    QLabel *label_P_CiV;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_P_Rs;
    QLabel *label_P_RsV;
    QLabel *label_P_NR;
    QScrollArea *scrollAreaM;
    QWidget *labelM;
    QHBoxLayout *horizontalLayout;
    QLabel *imageLabelM;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QString::fromUtf8("ImageViewer"));
        ImageViewer->resize(1220, 729);
        ImageViewer->setAutoFillBackground(true);
        centralwidget = new QWidget(ImageViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_outputM = new QLabel(centralwidget);
        label_outputM->setObjectName(QString::fromUtf8("label_outputM"));
        label_outputM->setAutoFillBackground(false);
        label_outputM->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_outputM, 2, 3, 1, 1);

        label_outputP = new QLabel(centralwidget);
        label_outputP->setObjectName(QString::fromUtf8("label_outputP"));
        label_outputP->setAutoFillBackground(false);
        label_outputP->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_outputP, 4, 3, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setTabBarAutoHide(false);
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        formLayout = new QFormLayout(tab_1);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        formLayout_3 = new QFormLayout(tab_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        diagBoxM = new QGroupBox(tab_2);
        diagBoxM->setObjectName(QString::fromUtf8("diagBoxM"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(diagBoxM->sizePolicy().hasHeightForWidth());
        diagBoxM->setSizePolicy(sizePolicy1);
        diagBoxM->setAutoFillBackground(false);
        gridLayout_3 = new QGridLayout(diagBoxM);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        calcLabelM_calc = new QLabel(diagBoxM);
        calcLabelM_calc->setObjectName(QString::fromUtf8("calcLabelM_calc"));

        gridLayout_3->addWidget(calcLabelM_calc, 1, 0, 1, 1);

        calcLabelM_bit = new QLabel(diagBoxM);
        calcLabelM_bit->setObjectName(QString::fromUtf8("calcLabelM_bit"));

        gridLayout_3->addWidget(calcLabelM_bit, 2, 0, 1, 1);

        calcLabelM_u_V = new QLCDNumber(diagBoxM);
        calcLabelM_u_V->setObjectName(QString::fromUtf8("calcLabelM_u_V"));
        calcLabelM_u_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_3->addWidget(calcLabelM_u_V, 0, 1, 1, 1);

        calcLabelM_imag = new QLabel(diagBoxM);
        calcLabelM_imag->setObjectName(QString::fromUtf8("calcLabelM_imag"));

        gridLayout_3->addWidget(calcLabelM_imag, 3, 0, 1, 1);

        calcLabelM_u = new QLabel(diagBoxM);
        calcLabelM_u->setObjectName(QString::fromUtf8("calcLabelM_u"));
        calcLabelM_u->setAutoFillBackground(true);

        gridLayout_3->addWidget(calcLabelM_u, 0, 0, 1, 1);

        calcLabelM_imag_V = new QLCDNumber(diagBoxM);
        calcLabelM_imag_V->setObjectName(QString::fromUtf8("calcLabelM_imag_V"));
        calcLabelM_imag_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_3->addWidget(calcLabelM_imag_V, 3, 1, 1, 1);

        calcLabelM_calc_V = new QLCDNumber(diagBoxM);
        calcLabelM_calc_V->setObjectName(QString::fromUtf8("calcLabelM_calc_V"));
        calcLabelM_calc_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_3->addWidget(calcLabelM_calc_V, 1, 1, 1, 1);

        calcLabelM_bit_V = new QLCDNumber(diagBoxM);
        calcLabelM_bit_V->setObjectName(QString::fromUtf8("calcLabelM_bit_V"));
        calcLabelM_bit_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_3->addWidget(calcLabelM_bit_V, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 4, 0, 1, 1);


        formLayout_3->setWidget(0, QFormLayout::LabelRole, diagBoxM);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 1, 1, 1, 2);

        groupBoxM = new QGroupBox(centralwidget);
        groupBoxM->setObjectName(QString::fromUtf8("groupBoxM"));
        gridLayout = new QGridLayout(groupBoxM);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_M_Ro = new QLabel(groupBoxM);
        label_M_Ro->setObjectName(QString::fromUtf8("label_M_Ro"));
        label_M_Ro->setMouseTracking(false);

        gridLayout->addWidget(label_M_Ro, 0, 1, 1, 1);

        lineEdit_M_Rs = new QLineEdit(groupBoxM);
        lineEdit_M_Rs->setObjectName(QString::fromUtf8("lineEdit_M_Rs"));
        lineEdit_M_Rs->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(lineEdit_M_Rs, 2, 3, 1, 1);

        label_M_Is = new QLabel(groupBoxM);
        label_M_Is->setObjectName(QString::fromUtf8("label_M_Is"));

        gridLayout->addWidget(label_M_Is, 3, 1, 1, 1);

        lineEdit_M_NR = new QLineEdit(groupBoxM);
        lineEdit_M_NR->setObjectName(QString::fromUtf8("lineEdit_M_NR"));

        gridLayout->addWidget(lineEdit_M_NR, 4, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 1, 1, 1);

        label_M_NK = new QLabel(groupBoxM);
        label_M_NK->setObjectName(QString::fromUtf8("label_M_NK"));

        gridLayout->addWidget(label_M_NK, 6, 1, 1, 1);

        label_M_RsV = new QLabel(groupBoxM);
        label_M_RsV->setObjectName(QString::fromUtf8("label_M_RsV"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_M_RsV->sizePolicy().hasHeightForWidth());
        label_M_RsV->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_M_RsV, 2, 2, 1, 1);

        label_M_NIV = new QLabel(groupBoxM);
        label_M_NIV->setObjectName(QString::fromUtf8("label_M_NIV"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_M_NIV->sizePolicy().hasHeightForWidth());
        label_M_NIV->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_M_NIV, 5, 2, 1, 1);

        label_M_IoV = new QLabel(groupBoxM);
        label_M_IoV->setObjectName(QString::fromUtf8("label_M_IoV"));
        sizePolicy2.setHeightForWidth(label_M_IoV->sizePolicy().hasHeightForWidth());
        label_M_IoV->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_M_IoV, 1, 2, 1, 1);

        lineEdit_M_Io = new QLineEdit(groupBoxM);
        lineEdit_M_Io->setObjectName(QString::fromUtf8("lineEdit_M_Io"));
        lineEdit_M_Io->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(lineEdit_M_Io, 1, 3, 1, 1);

        lineEdit_M_Is = new QLineEdit(groupBoxM);
        lineEdit_M_Is->setObjectName(QString::fromUtf8("lineEdit_M_Is"));

        gridLayout->addWidget(lineEdit_M_Is, 3, 3, 1, 1);

        lineEdit_M_NK = new QLineEdit(groupBoxM);
        lineEdit_M_NK->setObjectName(QString::fromUtf8("lineEdit_M_NK"));

        gridLayout->addWidget(lineEdit_M_NK, 6, 3, 1, 1);

        updateButton = new QPushButton(groupBoxM);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        gridLayout->addWidget(updateButton, 11, 3, 1, 1);

        label_M_NI = new QLabel(groupBoxM);
        label_M_NI->setObjectName(QString::fromUtf8("label_M_NI"));

        gridLayout->addWidget(label_M_NI, 5, 1, 1, 1);

        label_M_NRV = new QLabel(groupBoxM);
        label_M_NRV->setObjectName(QString::fromUtf8("label_M_NRV"));
        sizePolicy3.setHeightForWidth(label_M_NRV->sizePolicy().hasHeightForWidth());
        label_M_NRV->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_M_NRV, 4, 2, 1, 1);

        label_M_Rs = new QLabel(groupBoxM);
        label_M_Rs->setObjectName(QString::fromUtf8("label_M_Rs"));

        gridLayout->addWidget(label_M_Rs, 2, 1, 1, 1);

        label_M_NKV = new QLabel(groupBoxM);
        label_M_NKV->setObjectName(QString::fromUtf8("label_M_NKV"));
        sizePolicy3.setHeightForWidth(label_M_NKV->sizePolicy().hasHeightForWidth());
        label_M_NKV->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_M_NKV, 6, 2, 1, 1);

        lineEdit_M_NI = new QLineEdit(groupBoxM);
        lineEdit_M_NI->setObjectName(QString::fromUtf8("lineEdit_M_NI"));

        gridLayout->addWidget(lineEdit_M_NI, 5, 3, 1, 1);

        label_M_IsV = new QLabel(groupBoxM);
        label_M_IsV->setObjectName(QString::fromUtf8("label_M_IsV"));
        sizePolicy2.setHeightForWidth(label_M_IsV->sizePolicy().hasHeightForWidth());
        label_M_IsV->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_M_IsV, 3, 2, 1, 1);

        lineEdit_M_Ro = new QLineEdit(groupBoxM);
        lineEdit_M_Ro->setObjectName(QString::fromUtf8("lineEdit_M_Ro"));
        lineEdit_M_Ro->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(lineEdit_M_Ro, 0, 3, 1, 1);

        label_M_RoV = new QLabel(groupBoxM);
        label_M_RoV->setObjectName(QString::fromUtf8("label_M_RoV"));
        sizePolicy2.setHeightForWidth(label_M_RoV->sizePolicy().hasHeightForWidth());
        label_M_RoV->setSizePolicy(sizePolicy2);
        label_M_RoV->setScaledContents(false);

        gridLayout->addWidget(label_M_RoV, 0, 2, 1, 1);

        label_M_Io = new QLabel(groupBoxM);
        label_M_Io->setObjectName(QString::fromUtf8("label_M_Io"));

        gridLayout->addWidget(label_M_Io, 1, 1, 1, 1);

        label_M_NR = new QLabel(groupBoxM);
        label_M_NR->setObjectName(QString::fromUtf8("label_M_NR"));

        gridLayout->addWidget(label_M_NR, 4, 1, 1, 1);


        gridLayout_2->addWidget(groupBoxM, 1, 3, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 68, 642));
        label_colourPalette = new QLabel(scrollAreaWidgetContents);
        label_colourPalette->setObjectName(QString::fromUtf8("label_colourPalette"));
        label_colourPalette->setGeometry(QRect(20, 21, 311, 581));
        QSizePolicy sizePolicy5(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_colourPalette->sizePolicy().hasHeightForWidth());
        label_colourPalette->setSizePolicy(sizePolicy5);
        label_colourPalette->setAutoFillBackground(true);
        label_colourPalette->setScaledContents(true);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 4, 3, 1);

        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        sizePolicy.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        formLayout_2 = new QFormLayout(tab_3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        formLayout_4 = new QFormLayout(tab_4);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        diagBoxP = new QGroupBox(tab_4);
        diagBoxP->setObjectName(QString::fromUtf8("diagBoxP"));
        sizePolicy.setHeightForWidth(diagBoxP->sizePolicy().hasHeightForWidth());
        diagBoxP->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(diagBoxP);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        calcLabelP_u = new QLabel(diagBoxP);
        calcLabelP_u->setObjectName(QString::fromUtf8("calcLabelP_u"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(calcLabelP_u->sizePolicy().hasHeightForWidth());
        calcLabelP_u->setSizePolicy(sizePolicy6);
        calcLabelP_u->setAutoFillBackground(true);

        gridLayout_5->addWidget(calcLabelP_u, 0, 0, 1, 1);

        calcLabelP_u_V = new QLCDNumber(diagBoxP);
        calcLabelP_u_V->setObjectName(QString::fromUtf8("calcLabelP_u_V"));
        calcLabelP_u_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_5->addWidget(calcLabelP_u_V, 0, 1, 1, 1);

        calcLabelP_calc = new QLabel(diagBoxP);
        calcLabelP_calc->setObjectName(QString::fromUtf8("calcLabelP_calc"));

        gridLayout_5->addWidget(calcLabelP_calc, 1, 0, 1, 1);

        calcLabelP_calc_V = new QLCDNumber(diagBoxP);
        calcLabelP_calc_V->setObjectName(QString::fromUtf8("calcLabelP_calc_V"));
        calcLabelP_calc_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_5->addWidget(calcLabelP_calc_V, 1, 1, 1, 1);

        calcLabelP_bit = new QLabel(diagBoxP);
        calcLabelP_bit->setObjectName(QString::fromUtf8("calcLabelP_bit"));

        gridLayout_5->addWidget(calcLabelP_bit, 2, 0, 1, 1);

        calcLabelP_bit_V = new QLCDNumber(diagBoxP);
        calcLabelP_bit_V->setObjectName(QString::fromUtf8("calcLabelP_bit_V"));
        calcLabelP_bit_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_5->addWidget(calcLabelP_bit_V, 2, 1, 1, 1);

        calcLabelP_imag = new QLabel(diagBoxP);
        calcLabelP_imag->setObjectName(QString::fromUtf8("calcLabelP_imag"));

        gridLayout_5->addWidget(calcLabelP_imag, 3, 0, 1, 1);

        calcLabelP_imag_V = new QLCDNumber(diagBoxP);
        calcLabelP_imag_V->setObjectName(QString::fromUtf8("calcLabelP_imag_V"));
        calcLabelP_imag_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_5->addWidget(calcLabelP_imag_V, 3, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 4, 0, 1, 1);


        formLayout_4->setWidget(0, QFormLayout::LabelRole, diagBoxP);

        tabWidget_2->addTab(tab_4, QString());

        gridLayout_2->addWidget(tabWidget_2, 3, 1, 1, 1);

        scrollAreaP = new QScrollArea(centralwidget);
        scrollAreaP->setObjectName(QString::fromUtf8("scrollAreaP"));
        scrollAreaP->setWidgetResizable(true);
        labelP = new QWidget();
        labelP->setObjectName(QString::fromUtf8("labelP"));
        labelP->setGeometry(QRect(0, 0, 465, 321));
        labelP->setMouseTracking(true);
        horizontalLayout_2 = new QHBoxLayout(labelP);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        imageLabelP = new QLabel(labelP);
        imageLabelP->setObjectName(QString::fromUtf8("imageLabelP"));
        imageLabelP->setAutoFillBackground(true);
        imageLabelP->setScaledContents(true);

        horizontalLayout_2->addWidget(imageLabelP);

        scrollAreaP->setWidget(labelP);

        gridLayout_2->addWidget(scrollAreaP, 3, 0, 1, 1);

        groupBoxP = new QGroupBox(centralwidget);
        groupBoxP->setObjectName(QString::fromUtf8("groupBoxP"));
        gridLayout_4 = new QGridLayout(groupBoxP);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_P_Ro = new QLineEdit(groupBoxP);
        lineEdit_P_Ro->setObjectName(QString::fromUtf8("lineEdit_P_Ro"));

        gridLayout_4->addWidget(lineEdit_P_Ro, 0, 2, 1, 1);

        label_P_RoV = new QLabel(groupBoxP);
        label_P_RoV->setObjectName(QString::fromUtf8("label_P_RoV"));
        sizePolicy2.setHeightForWidth(label_P_RoV->sizePolicy().hasHeightForWidth());
        label_P_RoV->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_P_RoV, 0, 1, 1, 1);

        label_P_NKV = new QLabel(groupBoxP);
        label_P_NKV->setObjectName(QString::fromUtf8("label_P_NKV"));
        sizePolicy3.setHeightForWidth(label_P_NKV->sizePolicy().hasHeightForWidth());
        label_P_NKV->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_P_NKV, 8, 1, 1, 1);

        label_P_Is = new QLabel(groupBoxP);
        label_P_Is->setObjectName(QString::fromUtf8("label_P_Is"));

        gridLayout_4->addWidget(label_P_Is, 3, 0, 1, 1);

        label_P_IsV = new QLabel(groupBoxP);
        label_P_IsV->setObjectName(QString::fromUtf8("label_P_IsV"));
        sizePolicy2.setHeightForWidth(label_P_IsV->sizePolicy().hasHeightForWidth());
        label_P_IsV->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_P_IsV, 3, 1, 1, 1);

        lineEdit_P_NK = new QLineEdit(groupBoxP);
        lineEdit_P_NK->setObjectName(QString::fromUtf8("lineEdit_P_NK"));

        gridLayout_4->addWidget(lineEdit_P_NK, 8, 2, 1, 1);

        label_NI = new QLabel(groupBoxP);
        label_NI->setObjectName(QString::fromUtf8("label_NI"));

        gridLayout_4->addWidget(label_NI, 7, 0, 1, 1);

        lineEdit_P_NR = new QLineEdit(groupBoxP);
        lineEdit_P_NR->setObjectName(QString::fromUtf8("lineEdit_P_NR"));

        gridLayout_4->addWidget(lineEdit_P_NR, 6, 2, 1, 1);

        label_P_cR = new QLabel(groupBoxP);
        label_P_cR->setObjectName(QString::fromUtf8("label_P_cR"));

        gridLayout_4->addWidget(label_P_cR, 4, 0, 1, 1);

        lineEdit_P_cR = new QLineEdit(groupBoxP);
        lineEdit_P_cR->setObjectName(QString::fromUtf8("lineEdit_P_cR"));

        gridLayout_4->addWidget(lineEdit_P_cR, 4, 2, 1, 1);

        label_P_NIV = new QLabel(groupBoxP);
        label_P_NIV->setObjectName(QString::fromUtf8("label_P_NIV"));
        sizePolicy3.setHeightForWidth(label_P_NIV->sizePolicy().hasHeightForWidth());
        label_P_NIV->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_P_NIV, 7, 1, 1, 1);

        lineEdit_P_Io = new QLineEdit(groupBoxP);
        lineEdit_P_Io->setObjectName(QString::fromUtf8("lineEdit_P_Io"));

        gridLayout_4->addWidget(lineEdit_P_Io, 1, 2, 1, 1);

        label_P_NRV = new QLabel(groupBoxP);
        label_P_NRV->setObjectName(QString::fromUtf8("label_P_NRV"));
        sizePolicy3.setHeightForWidth(label_P_NRV->sizePolicy().hasHeightForWidth());
        label_P_NRV->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_P_NRV, 6, 1, 1, 1);

        label_P_CrV = new QLabel(groupBoxP);
        label_P_CrV->setObjectName(QString::fromUtf8("label_P_CrV"));
        sizePolicy2.setHeightForWidth(label_P_CrV->sizePolicy().hasHeightForWidth());
        label_P_CrV->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_P_CrV, 4, 1, 1, 1);

        lineEdit_P_Is = new QLineEdit(groupBoxP);
        lineEdit_P_Is->setObjectName(QString::fromUtf8("lineEdit_P_Is"));

        gridLayout_4->addWidget(lineEdit_P_Is, 3, 2, 1, 1);

        lineEdit_P_Rs = new QLineEdit(groupBoxP);
        lineEdit_P_Rs->setObjectName(QString::fromUtf8("lineEdit_P_Rs"));

        gridLayout_4->addWidget(lineEdit_P_Rs, 2, 2, 1, 1);

        lineEdit_P_cI = new QLineEdit(groupBoxP);
        lineEdit_P_cI->setObjectName(QString::fromUtf8("lineEdit_P_cI"));

        gridLayout_4->addWidget(lineEdit_P_cI, 5, 2, 1, 1);

        label_P_Ro = new QLabel(groupBoxP);
        label_P_Ro->setObjectName(QString::fromUtf8("label_P_Ro"));

        gridLayout_4->addWidget(label_P_Ro, 0, 0, 1, 1);

        label_P_cI = new QLabel(groupBoxP);
        label_P_cI->setObjectName(QString::fromUtf8("label_P_cI"));

        gridLayout_4->addWidget(label_P_cI, 5, 0, 1, 1);

        lineEdit_P_NI = new QLineEdit(groupBoxP);
        lineEdit_P_NI->setObjectName(QString::fromUtf8("lineEdit_P_NI"));

        gridLayout_4->addWidget(lineEdit_P_NI, 7, 2, 1, 1);

        label_NK = new QLabel(groupBoxP);
        label_NK->setObjectName(QString::fromUtf8("label_NK"));

        gridLayout_4->addWidget(label_NK, 8, 0, 1, 1);

        label_P_IoV = new QLabel(groupBoxP);
        label_P_IoV->setObjectName(QString::fromUtf8("label_P_IoV"));
        sizePolicy2.setHeightForWidth(label_P_IoV->sizePolicy().hasHeightForWidth());
        label_P_IoV->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_P_IoV, 1, 1, 1, 1);

        label_P_Io = new QLabel(groupBoxP);
        label_P_Io->setObjectName(QString::fromUtf8("label_P_Io"));

        gridLayout_4->addWidget(label_P_Io, 1, 0, 1, 1);

        label_P_CiV = new QLabel(groupBoxP);
        label_P_CiV->setObjectName(QString::fromUtf8("label_P_CiV"));
        sizePolicy2.setHeightForWidth(label_P_CiV->sizePolicy().hasHeightForWidth());
        label_P_CiV->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_P_CiV, 5, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 9, 0, 1, 1);

        label_P_Rs = new QLabel(groupBoxP);
        label_P_Rs->setObjectName(QString::fromUtf8("label_P_Rs"));

        gridLayout_4->addWidget(label_P_Rs, 2, 0, 1, 1);

        label_P_RsV = new QLabel(groupBoxP);
        label_P_RsV->setObjectName(QString::fromUtf8("label_P_RsV"));
        sizePolicy2.setHeightForWidth(label_P_RsV->sizePolicy().hasHeightForWidth());
        label_P_RsV->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_P_RsV, 2, 1, 1, 1);

        label_P_NR = new QLabel(groupBoxP);
        label_P_NR->setObjectName(QString::fromUtf8("label_P_NR"));

        gridLayout_4->addWidget(label_P_NR, 6, 0, 1, 1);


        gridLayout_2->addWidget(groupBoxP, 3, 3, 1, 1);

        scrollAreaM = new QScrollArea(centralwidget);
        scrollAreaM->setObjectName(QString::fromUtf8("scrollAreaM"));
        scrollAreaM->setWidgetResizable(true);
        labelM = new QWidget();
        labelM->setObjectName(QString::fromUtf8("labelM"));
        labelM->setEnabled(true);
        labelM->setGeometry(QRect(0, 0, 465, 290));
        labelM->setMouseTracking(true);
        horizontalLayout = new QHBoxLayout(labelM);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imageLabelM = new QLabel(labelM);
        imageLabelM->setObjectName(QString::fromUtf8("imageLabelM"));
        sizePolicy.setHeightForWidth(imageLabelM->sizePolicy().hasHeightForWidth());
        imageLabelM->setSizePolicy(sizePolicy);
        imageLabelM->setAutoFillBackground(true);
        imageLabelM->setScaledContents(true);

        horizontalLayout->addWidget(imageLabelM);

        scrollAreaM->setWidget(labelM);

        gridLayout_2->addWidget(scrollAreaM, 1, 0, 1, 1);

        ImageViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ImageViewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1220, 22));
        ImageViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(ImageViewer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ImageViewer->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEdit_M_Ro, lineEdit_M_Io);
        QWidget::setTabOrder(lineEdit_M_Io, lineEdit_M_Rs);
        QWidget::setTabOrder(lineEdit_M_Rs, lineEdit_M_Is);
        QWidget::setTabOrder(lineEdit_M_Is, lineEdit_M_NR);
        QWidget::setTabOrder(lineEdit_M_NR, lineEdit_M_NI);
        QWidget::setTabOrder(lineEdit_M_NI, lineEdit_M_NK);
        QWidget::setTabOrder(lineEdit_M_NK, updateButton);
        QWidget::setTabOrder(updateButton, lineEdit_P_Ro);
        QWidget::setTabOrder(lineEdit_P_Ro, lineEdit_P_Io);
        QWidget::setTabOrder(lineEdit_P_Io, lineEdit_P_Rs);
        QWidget::setTabOrder(lineEdit_P_Rs, lineEdit_P_Is);
        QWidget::setTabOrder(lineEdit_P_Is, lineEdit_P_cR);
        QWidget::setTabOrder(lineEdit_P_cR, lineEdit_P_cI);
        QWidget::setTabOrder(lineEdit_P_cI, lineEdit_P_NR);
        QWidget::setTabOrder(lineEdit_P_NR, lineEdit_P_NI);
        QWidget::setTabOrder(lineEdit_P_NI, lineEdit_P_NK);
        QWidget::setTabOrder(lineEdit_P_NK, scrollAreaP);
        QWidget::setTabOrder(scrollAreaP, scrollAreaM);

        retranslateUi(ImageViewer);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewer)
    {
        ImageViewer->setWindowTitle(QCoreApplication::translate("ImageViewer", "ImageViewer", nullptr));
        label_outputM->setText(QCoreApplication::translate("ImageViewer", "Program Messages", nullptr));
        label_outputP->setText(QCoreApplication::translate("ImageViewer", "Program Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("ImageViewer", "Diagnostics", nullptr));
        diagBoxM->setTitle(QCoreApplication::translate("ImageViewer", "Map Diagnostics", nullptr));
        calcLabelM_calc->setText(QCoreApplication::translate("ImageViewer", "Calc", nullptr));
        calcLabelM_bit->setText(QCoreApplication::translate("ImageViewer", "Bitmap", nullptr));
        calcLabelM_imag->setText(QCoreApplication::translate("ImageViewer", "Image", nullptr));
        calcLabelM_u->setText(QCoreApplication::translate("ImageViewer", "Update", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ImageViewer", "Tab 2", nullptr));
        groupBoxM->setTitle(QCoreApplication::translate("ImageViewer", "Map Input", nullptr));
#if QT_CONFIG(tooltip)
        label_M_Ro->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label_M_Ro->setWhatsThis(QCoreApplication::translate("ImageViewer", "Real origin", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_M_Ro->setText(QCoreApplication::translate("ImageViewer", "Ro", nullptr));
        label_M_Is->setText(QCoreApplication::translate("ImageViewer", "Is", nullptr));
        label_M_NK->setText(QCoreApplication::translate("ImageViewer", "N_K", nullptr));
#if QT_CONFIG(whatsthis)
        label_M_RsV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Real span value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_M_RsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
#if QT_CONFIG(whatsthis)
        label_M_NIV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Imaginary resolution value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_M_NIV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
#if QT_CONFIG(whatsthis)
        label_M_IoV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Imaginary origin value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_M_IoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        updateButton->setText(QCoreApplication::translate("ImageViewer", "Calculate", nullptr));
        label_M_NI->setText(QCoreApplication::translate("ImageViewer", "N_I", nullptr));
#if QT_CONFIG(whatsthis)
        label_M_NRV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Real resolution value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_M_NRV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_Rs->setText(QCoreApplication::translate("ImageViewer", "Rs", nullptr));
#if QT_CONFIG(whatsthis)
        label_M_NKV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Iteration value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_M_NKV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
#if QT_CONFIG(whatsthis)
        label_M_IsV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Imaginary span value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_M_IsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
#if QT_CONFIG(whatsthis)
        label_M_RoV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Real origin value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_M_RoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_Io->setText(QCoreApplication::translate("ImageViewer", "Io", nullptr));
        label_M_NR->setText(QCoreApplication::translate("ImageViewer", "N_R", nullptr));
        label_colourPalette->setText(QCoreApplication::translate("ImageViewer", "TextLabel", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("ImageViewer", "Diagnostics", nullptr));
        diagBoxP->setTitle(QCoreApplication::translate("ImageViewer", "Point Diagnostics", nullptr));
        calcLabelP_u->setText(QCoreApplication::translate("ImageViewer", "Update", nullptr));
        calcLabelP_calc->setText(QCoreApplication::translate("ImageViewer", "Calc", nullptr));
        calcLabelP_bit->setText(QCoreApplication::translate("ImageViewer", "Bitmap", nullptr));
        calcLabelP_imag->setText(QCoreApplication::translate("ImageViewer", "Image", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("ImageViewer", "Tab 2", nullptr));
        imageLabelP->setText(QCoreApplication::translate("ImageViewer", "Point Set", nullptr));
        groupBoxP->setTitle(QCoreApplication::translate("ImageViewer", "Point Input", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_RoV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Real origin value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_RoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_NKV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Iteration value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_NKV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_P_Is->setText(QCoreApplication::translate("ImageViewer", "Is", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_IsV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Imaginary span value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_IsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_NI->setText(QCoreApplication::translate("ImageViewer", "N_I", nullptr));
        label_P_cR->setText(QCoreApplication::translate("ImageViewer", "cR", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_NIV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Imaginary resolution value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_NIV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_NRV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Real resolution value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_NRV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_CrV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Real comp value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_CrV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_P_Ro->setText(QCoreApplication::translate("ImageViewer", "Ro", nullptr));
        label_P_cI->setText(QCoreApplication::translate("ImageViewer", "cI", nullptr));
        label_NK->setText(QCoreApplication::translate("ImageViewer", "N_K", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_IoV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Imaginary origin value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_IoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_P_Io->setText(QCoreApplication::translate("ImageViewer", "Io", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_CiV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Imaginary comp value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_CiV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_P_Rs->setText(QCoreApplication::translate("ImageViewer", "Rs", nullptr));
#if QT_CONFIG(whatsthis)
        label_P_RsV->setWhatsThis(QCoreApplication::translate("ImageViewer", "Real span value", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_P_RsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_P_NR->setText(QCoreApplication::translate("ImageViewer", "N_R", nullptr));
        imageLabelM->setText(QCoreApplication::translate("ImageViewer", "Map Set", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
