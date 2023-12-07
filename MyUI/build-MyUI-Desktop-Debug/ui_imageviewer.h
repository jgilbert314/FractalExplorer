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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollAreaP;
    QWidget *labelP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *imageLabelP;
    QScrollArea *scrollAreaM;
    QWidget *labelM;
    QHBoxLayout *horizontalLayout;
    QLabel *imageLabelM;
    QGroupBox *diagBoxM;
    QGridLayout *gridLayout_3;
    QLCDNumber *calcLabelM_V;
    QSpacerItem *verticalSpacer_2;
    QLabel *calcLabelM;
    QLabel *label_coord_R;
    QLabel *label_coord_I;
    QGroupBox *diagBoxP;
    QGridLayout *gridLayout_5;
    QLCDNumber *calcLabelP_V;
    QLabel *calcLabelP;
    QSpacerItem *verticalSpacer_4;
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
    QGroupBox *groupBoxP;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_P_Ro;
    QLabel *label_P_RoV;
    QLabel *label_P_NKV;
    QLabel *label_10;
    QLabel *label_P_IsV;
    QLineEdit *lineEdit_P_NK;
    QLabel *label_14;
    QLineEdit *lineEdit_P_NR;
    QLabel *label_5;
    QLineEdit *lineEdit_P_cR;
    QLabel *label_P_NIV;
    QLineEdit *lineEdit_P_Io;
    QLabel *label_P_NRV;
    QLabel *label_P_CrV;
    QLineEdit *lineEdit_P_Is;
    QLineEdit *lineEdit_P_Rs;
    QLineEdit *lineEdit_P_cI;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *lineEdit_P_NI;
    QLabel *label_15;
    QLabel *label_P_IoV;
    QLabel *label_2;
    QLabel *label_P_CiV;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_9;
    QLabel *label_P_RsV;
    QLabel *label_13;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_colourPalette;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QString::fromUtf8("ImageViewer"));
        ImageViewer->resize(1220, 683);
        ImageViewer->setAutoFillBackground(true);
        centralwidget = new QWidget(ImageViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollAreaP = new QScrollArea(centralwidget);
        scrollAreaP->setObjectName(QString::fromUtf8("scrollAreaP"));
        scrollAreaP->setWidgetResizable(true);
        labelP = new QWidget();
        labelP->setObjectName(QString::fromUtf8("labelP"));
        labelP->setGeometry(QRect(0, 0, 343, 321));
        labelP->setMouseTracking(true);
        horizontalLayout_2 = new QHBoxLayout(labelP);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        imageLabelP = new QLabel(labelP);
        imageLabelP->setObjectName(QString::fromUtf8("imageLabelP"));
        imageLabelP->setAutoFillBackground(true);
        imageLabelP->setScaledContents(true);

        horizontalLayout_2->addWidget(imageLabelP);

        scrollAreaP->setWidget(labelP);

        gridLayout_2->addWidget(scrollAreaP, 1, 0, 1, 1);

        scrollAreaM = new QScrollArea(centralwidget);
        scrollAreaM->setObjectName(QString::fromUtf8("scrollAreaM"));
        scrollAreaM->setWidgetResizable(true);
        labelM = new QWidget();
        labelM->setObjectName(QString::fromUtf8("labelM"));
        labelM->setEnabled(true);
        labelM->setGeometry(QRect(0, 0, 343, 290));
        labelM->setMouseTracking(true);
        horizontalLayout = new QHBoxLayout(labelM);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imageLabelM = new QLabel(labelM);
        imageLabelM->setObjectName(QString::fromUtf8("imageLabelM"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageLabelM->sizePolicy().hasHeightForWidth());
        imageLabelM->setSizePolicy(sizePolicy);
        imageLabelM->setAutoFillBackground(true);
        imageLabelM->setScaledContents(true);

        horizontalLayout->addWidget(imageLabelM);

        scrollAreaM->setWidget(labelM);

        gridLayout_2->addWidget(scrollAreaM, 0, 0, 1, 1);

        diagBoxM = new QGroupBox(centralwidget);
        diagBoxM->setObjectName(QString::fromUtf8("diagBoxM"));
        sizePolicy.setHeightForWidth(diagBoxM->sizePolicy().hasHeightForWidth());
        diagBoxM->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(diagBoxM);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        calcLabelM_V = new QLCDNumber(diagBoxM);
        calcLabelM_V->setObjectName(QString::fromUtf8("calcLabelM_V"));
        calcLabelM_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_3->addWidget(calcLabelM_V, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 1);

        calcLabelM = new QLabel(diagBoxM);
        calcLabelM->setObjectName(QString::fromUtf8("calcLabelM"));
        calcLabelM->setAutoFillBackground(true);

        gridLayout_3->addWidget(calcLabelM, 1, 0, 1, 1);

        label_coord_R = new QLabel(diagBoxM);
        label_coord_R->setObjectName(QString::fromUtf8("label_coord_R"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_coord_R->sizePolicy().hasHeightForWidth());
        label_coord_R->setSizePolicy(sizePolicy1);
        label_coord_R->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Ubuntu Mono\";"));

        gridLayout_3->addWidget(label_coord_R, 0, 0, 1, 1);

        label_coord_I = new QLabel(diagBoxM);
        label_coord_I->setObjectName(QString::fromUtf8("label_coord_I"));
        sizePolicy1.setHeightForWidth(label_coord_I->sizePolicy().hasHeightForWidth());
        label_coord_I->setSizePolicy(sizePolicy1);
        label_coord_I->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 11pt \"Ubuntu Mono\";"));

        gridLayout_3->addWidget(label_coord_I, 0, 1, 1, 1);


        gridLayout_2->addWidget(diagBoxM, 0, 2, 1, 1, Qt::AlignLeft);

        diagBoxP = new QGroupBox(centralwidget);
        diagBoxP->setObjectName(QString::fromUtf8("diagBoxP"));
        sizePolicy.setHeightForWidth(diagBoxP->sizePolicy().hasHeightForWidth());
        diagBoxP->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(diagBoxP);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        calcLabelP_V = new QLCDNumber(diagBoxP);
        calcLabelP_V->setObjectName(QString::fromUtf8("calcLabelP_V"));
        calcLabelP_V->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        gridLayout_5->addWidget(calcLabelP_V, 0, 1, 1, 1);

        calcLabelP = new QLabel(diagBoxP);
        calcLabelP->setObjectName(QString::fromUtf8("calcLabelP"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(calcLabelP->sizePolicy().hasHeightForWidth());
        calcLabelP->setSizePolicy(sizePolicy2);
        calcLabelP->setAutoFillBackground(true);

        gridLayout_5->addWidget(calcLabelP, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 1, 0, 1, 1);


        gridLayout_2->addWidget(diagBoxP, 1, 2, 1, 1);

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
        sizePolicy1.setHeightForWidth(label_M_RsV->sizePolicy().hasHeightForWidth());
        label_M_RsV->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(label_M_IoV->sizePolicy().hasHeightForWidth());
        label_M_IoV->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(label_M_IsV->sizePolicy().hasHeightForWidth());
        label_M_IsV->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_M_IsV, 3, 2, 1, 1);

        lineEdit_M_Ro = new QLineEdit(groupBoxM);
        lineEdit_M_Ro->setObjectName(QString::fromUtf8("lineEdit_M_Ro"));
        lineEdit_M_Ro->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(lineEdit_M_Ro, 0, 3, 1, 1);

        label_M_RoV = new QLabel(groupBoxM);
        label_M_RoV->setObjectName(QString::fromUtf8("label_M_RoV"));
        sizePolicy1.setHeightForWidth(label_M_RoV->sizePolicy().hasHeightForWidth());
        label_M_RoV->setSizePolicy(sizePolicy1);
        label_M_RoV->setScaledContents(false);

        gridLayout->addWidget(label_M_RoV, 0, 2, 1, 1);

        label_M_Io = new QLabel(groupBoxM);
        label_M_Io->setObjectName(QString::fromUtf8("label_M_Io"));

        gridLayout->addWidget(label_M_Io, 1, 1, 1, 1);

        label_M_NR = new QLabel(groupBoxM);
        label_M_NR->setObjectName(QString::fromUtf8("label_M_NR"));

        gridLayout->addWidget(label_M_NR, 4, 1, 1, 1);


        gridLayout_2->addWidget(groupBoxM, 0, 1, 1, 1);

        groupBoxP = new QGroupBox(centralwidget);
        groupBoxP->setObjectName(QString::fromUtf8("groupBoxP"));
        gridLayout_4 = new QGridLayout(groupBoxP);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_P_Ro = new QLineEdit(groupBoxP);
        lineEdit_P_Ro->setObjectName(QString::fromUtf8("lineEdit_P_Ro"));

        gridLayout_4->addWidget(lineEdit_P_Ro, 0, 2, 1, 1);

        label_P_RoV = new QLabel(groupBoxP);
        label_P_RoV->setObjectName(QString::fromUtf8("label_P_RoV"));
        sizePolicy1.setHeightForWidth(label_P_RoV->sizePolicy().hasHeightForWidth());
        label_P_RoV->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_P_RoV, 0, 1, 1, 1);

        label_P_NKV = new QLabel(groupBoxP);
        label_P_NKV->setObjectName(QString::fromUtf8("label_P_NKV"));
        sizePolicy3.setHeightForWidth(label_P_NKV->sizePolicy().hasHeightForWidth());
        label_P_NKV->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_P_NKV, 8, 1, 1, 1);

        label_10 = new QLabel(groupBoxP);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 3, 0, 1, 1);

        label_P_IsV = new QLabel(groupBoxP);
        label_P_IsV->setObjectName(QString::fromUtf8("label_P_IsV"));
        sizePolicy1.setHeightForWidth(label_P_IsV->sizePolicy().hasHeightForWidth());
        label_P_IsV->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_P_IsV, 3, 1, 1, 1);

        lineEdit_P_NK = new QLineEdit(groupBoxP);
        lineEdit_P_NK->setObjectName(QString::fromUtf8("lineEdit_P_NK"));

        gridLayout_4->addWidget(lineEdit_P_NK, 8, 2, 1, 1);

        label_14 = new QLabel(groupBoxP);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 7, 0, 1, 1);

        lineEdit_P_NR = new QLineEdit(groupBoxP);
        lineEdit_P_NR->setObjectName(QString::fromUtf8("lineEdit_P_NR"));

        gridLayout_4->addWidget(lineEdit_P_NR, 6, 2, 1, 1);

        label_5 = new QLabel(groupBoxP);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 4, 0, 1, 1);

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
        sizePolicy1.setHeightForWidth(label_P_CrV->sizePolicy().hasHeightForWidth());
        label_P_CrV->setSizePolicy(sizePolicy1);

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

        label_3 = new QLabel(groupBoxP);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        label_6 = new QLabel(groupBoxP);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_P_NI = new QLineEdit(groupBoxP);
        lineEdit_P_NI->setObjectName(QString::fromUtf8("lineEdit_P_NI"));

        gridLayout_4->addWidget(lineEdit_P_NI, 7, 2, 1, 1);

        label_15 = new QLabel(groupBoxP);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 8, 0, 1, 1);

        label_P_IoV = new QLabel(groupBoxP);
        label_P_IoV->setObjectName(QString::fromUtf8("label_P_IoV"));
        sizePolicy1.setHeightForWidth(label_P_IoV->sizePolicy().hasHeightForWidth());
        label_P_IoV->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_P_IoV, 1, 1, 1, 1);

        label_2 = new QLabel(groupBoxP);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        label_P_CiV = new QLabel(groupBoxP);
        label_P_CiV->setObjectName(QString::fromUtf8("label_P_CiV"));
        sizePolicy1.setHeightForWidth(label_P_CiV->sizePolicy().hasHeightForWidth());
        label_P_CiV->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_P_CiV, 5, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 9, 0, 1, 1);

        label_9 = new QLabel(groupBoxP);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        label_P_RsV = new QLabel(groupBoxP);
        label_P_RsV->setObjectName(QString::fromUtf8("label_P_RsV"));
        sizePolicy1.setHeightForWidth(label_P_RsV->sizePolicy().hasHeightForWidth());
        label_P_RsV->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_P_RsV, 2, 1, 1, 1);

        label_13 = new QLabel(groupBoxP);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 6, 0, 1, 1);


        gridLayout_2->addWidget(groupBoxP, 1, 1, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 343, 619));
        label_colourPalette = new QLabel(scrollAreaWidgetContents);
        label_colourPalette->setObjectName(QString::fromUtf8("label_colourPalette"));
        label_colourPalette->setGeometry(QRect(20, 21, 311, 581));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_colourPalette->sizePolicy().hasHeightForWidth());
        label_colourPalette->setSizePolicy(sizePolicy4);
        label_colourPalette->setAutoFillBackground(true);
        label_colourPalette->setScaledContents(true);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 3, 2, 1);

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

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewer)
    {
        ImageViewer->setWindowTitle(QCoreApplication::translate("ImageViewer", "ImageViewer", nullptr));
        imageLabelP->setText(QCoreApplication::translate("ImageViewer", "Point Set", nullptr));
        imageLabelM->setText(QCoreApplication::translate("ImageViewer", "Map Set", nullptr));
        diagBoxM->setTitle(QCoreApplication::translate("ImageViewer", "Map Diagnostics", nullptr));
        calcLabelM->setText(QCoreApplication::translate("ImageViewer", "Set Calc", nullptr));
        label_coord_R->setText(QCoreApplication::translate("ImageViewer", "Coord-R", nullptr));
        label_coord_I->setText(QCoreApplication::translate("ImageViewer", "Coord-I", nullptr));
        diagBoxP->setTitle(QCoreApplication::translate("ImageViewer", "Point Diagnostics", nullptr));
        calcLabelP->setText(QCoreApplication::translate("ImageViewer", "Set Calc", nullptr));
        groupBoxM->setTitle(QCoreApplication::translate("ImageViewer", "Map Input", nullptr));
#if QT_CONFIG(tooltip)
        label_M_Ro->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label_M_Ro->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        label_M_Ro->setText(QCoreApplication::translate("ImageViewer", "Ro", nullptr));
        label_M_Is->setText(QCoreApplication::translate("ImageViewer", "Is", nullptr));
        label_M_NK->setText(QCoreApplication::translate("ImageViewer", "N_K", nullptr));
        label_M_RsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_NIV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_IoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        updateButton->setText(QCoreApplication::translate("ImageViewer", "Calculate", nullptr));
        label_M_NI->setText(QCoreApplication::translate("ImageViewer", "N_I", nullptr));
        label_M_NRV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_Rs->setText(QCoreApplication::translate("ImageViewer", "Rs", nullptr));
        label_M_NKV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_IsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_RoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_Io->setText(QCoreApplication::translate("ImageViewer", "Io", nullptr));
        label_M_NR->setText(QCoreApplication::translate("ImageViewer", "N_R", nullptr));
        groupBoxP->setTitle(QCoreApplication::translate("ImageViewer", "Point Input", nullptr));
        label_P_RoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_P_NKV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_10->setText(QCoreApplication::translate("ImageViewer", "Is", nullptr));
        label_P_IsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_14->setText(QCoreApplication::translate("ImageViewer", "N_I", nullptr));
        label_5->setText(QCoreApplication::translate("ImageViewer", "cR", nullptr));
        label_P_NIV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_P_NRV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_P_CrV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_3->setText(QCoreApplication::translate("ImageViewer", "Ro", nullptr));
        label_6->setText(QCoreApplication::translate("ImageViewer", "cI", nullptr));
        label_15->setText(QCoreApplication::translate("ImageViewer", "N_K", nullptr));
        label_P_IoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_2->setText(QCoreApplication::translate("ImageViewer", "Io", nullptr));
        label_P_CiV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_9->setText(QCoreApplication::translate("ImageViewer", "Rs", nullptr));
        label_P_RsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_13->setText(QCoreApplication::translate("ImageViewer", "N_R", nullptr));
        label_colourPalette->setText(QCoreApplication::translate("ImageViewer", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
