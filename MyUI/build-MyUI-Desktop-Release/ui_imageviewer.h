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
    QGroupBox *groupBoxJ;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_J_NK;
    QLabel *label_J_NIV;
    QLineEdit *lineEdit_J_Ro;
    QLabel *label_J_RoV;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineEdit_J_Is;
    QLabel *label_2;
    QLabel *label_15;
    QLabel *label_J_RsV;
    QLabel *label_J_NKV;
    QLineEdit *lineEdit_J_NI;
    QLabel *label_13;
    QLineEdit *lineEdit_J_cI;
    QLabel *label_J_CrV;
    QLineEdit *lineEdit_J_Rs;
    QLabel *label_6;
    QLabel *label_J_NRV;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *lineEdit_J_NR;
    QLabel *label_9;
    QLabel *label_J_CiV;
    QLabel *label_J_IoV;
    QLabel *label_14;
    QLabel *label_10;
    QLineEdit *lineEdit_J_Io;
    QLabel *label_J_IsV;
    QLineEdit *lineEdit_J_cR;
    QGroupBox *groupBoxM;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_M_Is;
    QSpacerItem *verticalSpacer;
    QLabel *label_M_IoV;
    QLabel *label_M_Is;
    QLabel *label_M_RsV;
    QLabel *label_M_NIV;
    QLineEdit *lineEdit_M_NR;
    QLabel *label_M_IsV;
    QLabel *label_M_NK;
    QLabel *label_M_NKV;
    QPushButton *updateButton;
    QLineEdit *lineEdit_M_NI;
    QLabel *label_M_NRV;
    QLabel *label_M_RoV;
    QLabel *label_M_Io;
    QLineEdit *lineEdit_M_Io;
    QLineEdit *lineEdit_M_Rs;
    QLabel *label_M_NI;
    QLabel *label_M_NR;
    QLineEdit *lineEdit_M_Ro;
    QLabel *label_M_Ro;
    QLabel *label_M_Rs;
    QLineEdit *lineEdit_M_NK;
    QScrollArea *scrollAreaJ;
    QWidget *labelJ;
    QHBoxLayout *horizontalLayout_2;
    QLabel *imageLabelJ;
    QScrollArea *scrollAreaM;
    QWidget *labelP;
    QHBoxLayout *horizontalLayout;
    QLabel *imageLabelM;
    QGroupBox *diagBoxM;
    QGridLayout *gridLayout_3;
    QLCDNumber *calcLabelM_V;
    QSpacerItem *verticalSpacer_2;
    QLabel *calcLabelM;
    QLabel *label_19;
    QLabel *label_20;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLCDNumber *calcLabelJ_V;
    QLabel *calcLabelJ;
    QSpacerItem *verticalSpacer_4;
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
        groupBoxJ = new QGroupBox(centralwidget);
        groupBoxJ->setObjectName(QString::fromUtf8("groupBoxJ"));
        gridLayout_4 = new QGridLayout(groupBoxJ);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_J_NK = new QLineEdit(groupBoxJ);
        lineEdit_J_NK->setObjectName(QString::fromUtf8("lineEdit_J_NK"));

        gridLayout_4->addWidget(lineEdit_J_NK, 8, 2, 1, 1);

        label_J_NIV = new QLabel(groupBoxJ);
        label_J_NIV->setObjectName(QString::fromUtf8("label_J_NIV"));

        gridLayout_4->addWidget(label_J_NIV, 7, 1, 1, 1);

        lineEdit_J_Ro = new QLineEdit(groupBoxJ);
        lineEdit_J_Ro->setObjectName(QString::fromUtf8("lineEdit_J_Ro"));

        gridLayout_4->addWidget(lineEdit_J_Ro, 0, 2, 1, 1);

        label_J_RoV = new QLabel(groupBoxJ);
        label_J_RoV->setObjectName(QString::fromUtf8("label_J_RoV"));

        gridLayout_4->addWidget(label_J_RoV, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 9, 0, 1, 1);

        lineEdit_J_Is = new QLineEdit(groupBoxJ);
        lineEdit_J_Is->setObjectName(QString::fromUtf8("lineEdit_J_Is"));

        gridLayout_4->addWidget(lineEdit_J_Is, 3, 2, 1, 1);

        label_2 = new QLabel(groupBoxJ);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        label_15 = new QLabel(groupBoxJ);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 8, 0, 1, 1);

        label_J_RsV = new QLabel(groupBoxJ);
        label_J_RsV->setObjectName(QString::fromUtf8("label_J_RsV"));

        gridLayout_4->addWidget(label_J_RsV, 2, 1, 1, 1);

        label_J_NKV = new QLabel(groupBoxJ);
        label_J_NKV->setObjectName(QString::fromUtf8("label_J_NKV"));

        gridLayout_4->addWidget(label_J_NKV, 8, 1, 1, 1);

        lineEdit_J_NI = new QLineEdit(groupBoxJ);
        lineEdit_J_NI->setObjectName(QString::fromUtf8("lineEdit_J_NI"));

        gridLayout_4->addWidget(lineEdit_J_NI, 7, 2, 1, 1);

        label_13 = new QLabel(groupBoxJ);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 6, 0, 1, 1);

        lineEdit_J_cI = new QLineEdit(groupBoxJ);
        lineEdit_J_cI->setObjectName(QString::fromUtf8("lineEdit_J_cI"));

        gridLayout_4->addWidget(lineEdit_J_cI, 5, 2, 1, 1);

        label_J_CrV = new QLabel(groupBoxJ);
        label_J_CrV->setObjectName(QString::fromUtf8("label_J_CrV"));

        gridLayout_4->addWidget(label_J_CrV, 4, 1, 1, 1);

        lineEdit_J_Rs = new QLineEdit(groupBoxJ);
        lineEdit_J_Rs->setObjectName(QString::fromUtf8("lineEdit_J_Rs"));

        gridLayout_4->addWidget(lineEdit_J_Rs, 2, 2, 1, 1);

        label_6 = new QLabel(groupBoxJ);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 5, 0, 1, 1);

        label_J_NRV = new QLabel(groupBoxJ);
        label_J_NRV->setObjectName(QString::fromUtf8("label_J_NRV"));

        gridLayout_4->addWidget(label_J_NRV, 6, 1, 1, 1);

        label_5 = new QLabel(groupBoxJ);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(groupBoxJ);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_J_NR = new QLineEdit(groupBoxJ);
        lineEdit_J_NR->setObjectName(QString::fromUtf8("lineEdit_J_NR"));

        gridLayout_4->addWidget(lineEdit_J_NR, 6, 2, 1, 1);

        label_9 = new QLabel(groupBoxJ);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        label_J_CiV = new QLabel(groupBoxJ);
        label_J_CiV->setObjectName(QString::fromUtf8("label_J_CiV"));

        gridLayout_4->addWidget(label_J_CiV, 5, 1, 1, 1);

        label_J_IoV = new QLabel(groupBoxJ);
        label_J_IoV->setObjectName(QString::fromUtf8("label_J_IoV"));

        gridLayout_4->addWidget(label_J_IoV, 1, 1, 1, 1);

        label_14 = new QLabel(groupBoxJ);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 7, 0, 1, 1);

        label_10 = new QLabel(groupBoxJ);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 3, 0, 1, 1);

        lineEdit_J_Io = new QLineEdit(groupBoxJ);
        lineEdit_J_Io->setObjectName(QString::fromUtf8("lineEdit_J_Io"));

        gridLayout_4->addWidget(lineEdit_J_Io, 1, 2, 1, 1);

        label_J_IsV = new QLabel(groupBoxJ);
        label_J_IsV->setObjectName(QString::fromUtf8("label_J_IsV"));

        gridLayout_4->addWidget(label_J_IsV, 3, 1, 1, 1);

        lineEdit_J_cR = new QLineEdit(groupBoxJ);
        lineEdit_J_cR->setObjectName(QString::fromUtf8("lineEdit_J_cR"));

        gridLayout_4->addWidget(lineEdit_J_cR, 4, 2, 1, 1);


        gridLayout_2->addWidget(groupBoxJ, 1, 1, 1, 1);

        groupBoxM = new QGroupBox(centralwidget);
        groupBoxM->setObjectName(QString::fromUtf8("groupBoxM"));
        gridLayout = new QGridLayout(groupBoxM);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_M_Is = new QLineEdit(groupBoxM);
        lineEdit_M_Is->setObjectName(QString::fromUtf8("lineEdit_M_Is"));

        gridLayout->addWidget(lineEdit_M_Is, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 1, 1, 1);

        label_M_IoV = new QLabel(groupBoxM);
        label_M_IoV->setObjectName(QString::fromUtf8("label_M_IoV"));

        gridLayout->addWidget(label_M_IoV, 1, 2, 1, 1);

        label_M_Is = new QLabel(groupBoxM);
        label_M_Is->setObjectName(QString::fromUtf8("label_M_Is"));

        gridLayout->addWidget(label_M_Is, 3, 1, 1, 1);

        label_M_RsV = new QLabel(groupBoxM);
        label_M_RsV->setObjectName(QString::fromUtf8("label_M_RsV"));

        gridLayout->addWidget(label_M_RsV, 2, 2, 1, 1);

        label_M_NIV = new QLabel(groupBoxM);
        label_M_NIV->setObjectName(QString::fromUtf8("label_M_NIV"));

        gridLayout->addWidget(label_M_NIV, 5, 2, 1, 1);

        lineEdit_M_NR = new QLineEdit(groupBoxM);
        lineEdit_M_NR->setObjectName(QString::fromUtf8("lineEdit_M_NR"));

        gridLayout->addWidget(lineEdit_M_NR, 4, 3, 1, 1);

        label_M_IsV = new QLabel(groupBoxM);
        label_M_IsV->setObjectName(QString::fromUtf8("label_M_IsV"));

        gridLayout->addWidget(label_M_IsV, 3, 2, 1, 1);

        label_M_NK = new QLabel(groupBoxM);
        label_M_NK->setObjectName(QString::fromUtf8("label_M_NK"));

        gridLayout->addWidget(label_M_NK, 6, 1, 1, 1);

        label_M_NKV = new QLabel(groupBoxM);
        label_M_NKV->setObjectName(QString::fromUtf8("label_M_NKV"));

        gridLayout->addWidget(label_M_NKV, 6, 2, 1, 1);

        updateButton = new QPushButton(groupBoxM);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        gridLayout->addWidget(updateButton, 11, 3, 1, 1);

        lineEdit_M_NI = new QLineEdit(groupBoxM);
        lineEdit_M_NI->setObjectName(QString::fromUtf8("lineEdit_M_NI"));

        gridLayout->addWidget(lineEdit_M_NI, 5, 3, 1, 1);

        label_M_NRV = new QLabel(groupBoxM);
        label_M_NRV->setObjectName(QString::fromUtf8("label_M_NRV"));

        gridLayout->addWidget(label_M_NRV, 4, 2, 1, 1);

        label_M_RoV = new QLabel(groupBoxM);
        label_M_RoV->setObjectName(QString::fromUtf8("label_M_RoV"));

        gridLayout->addWidget(label_M_RoV, 0, 2, 1, 1);

        label_M_Io = new QLabel(groupBoxM);
        label_M_Io->setObjectName(QString::fromUtf8("label_M_Io"));

        gridLayout->addWidget(label_M_Io, 1, 1, 1, 1);

        lineEdit_M_Io = new QLineEdit(groupBoxM);
        lineEdit_M_Io->setObjectName(QString::fromUtf8("lineEdit_M_Io"));
        lineEdit_M_Io->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(lineEdit_M_Io, 1, 3, 1, 1);

        lineEdit_M_Rs = new QLineEdit(groupBoxM);
        lineEdit_M_Rs->setObjectName(QString::fromUtf8("lineEdit_M_Rs"));
        lineEdit_M_Rs->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(lineEdit_M_Rs, 2, 3, 1, 1);

        label_M_NI = new QLabel(groupBoxM);
        label_M_NI->setObjectName(QString::fromUtf8("label_M_NI"));

        gridLayout->addWidget(label_M_NI, 5, 1, 1, 1);

        label_M_NR = new QLabel(groupBoxM);
        label_M_NR->setObjectName(QString::fromUtf8("label_M_NR"));

        gridLayout->addWidget(label_M_NR, 4, 1, 1, 1);

        lineEdit_M_Ro = new QLineEdit(groupBoxM);
        lineEdit_M_Ro->setObjectName(QString::fromUtf8("lineEdit_M_Ro"));
        lineEdit_M_Ro->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(lineEdit_M_Ro, 0, 3, 1, 1);

        label_M_Ro = new QLabel(groupBoxM);
        label_M_Ro->setObjectName(QString::fromUtf8("label_M_Ro"));

        gridLayout->addWidget(label_M_Ro, 0, 1, 1, 1);

        label_M_Rs = new QLabel(groupBoxM);
        label_M_Rs->setObjectName(QString::fromUtf8("label_M_Rs"));

        gridLayout->addWidget(label_M_Rs, 2, 1, 1, 1);

        lineEdit_M_NK = new QLineEdit(groupBoxM);
        lineEdit_M_NK->setObjectName(QString::fromUtf8("lineEdit_M_NK"));

        gridLayout->addWidget(lineEdit_M_NK, 6, 3, 1, 1);


        gridLayout_2->addWidget(groupBoxM, 0, 1, 1, 1);

        scrollAreaJ = new QScrollArea(centralwidget);
        scrollAreaJ->setObjectName(QString::fromUtf8("scrollAreaJ"));
        scrollAreaJ->setWidgetResizable(true);
        labelJ = new QWidget();
        labelJ->setObjectName(QString::fromUtf8("labelJ"));
        labelJ->setGeometry(QRect(0, 0, 518, 321));
        labelJ->setMouseTracking(true);
        horizontalLayout_2 = new QHBoxLayout(labelJ);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        imageLabelJ = new QLabel(labelJ);
        imageLabelJ->setObjectName(QString::fromUtf8("imageLabelJ"));
        imageLabelJ->setAutoFillBackground(true);
        imageLabelJ->setScaledContents(true);

        horizontalLayout_2->addWidget(imageLabelJ);

        scrollAreaJ->setWidget(labelJ);

        gridLayout_2->addWidget(scrollAreaJ, 1, 0, 1, 1);

        scrollAreaM = new QScrollArea(centralwidget);
        scrollAreaM->setObjectName(QString::fromUtf8("scrollAreaM"));
        scrollAreaM->setWidgetResizable(true);
        labelP = new QWidget();
        labelP->setObjectName(QString::fromUtf8("labelP"));
        labelP->setEnabled(true);
        labelP->setGeometry(QRect(0, 0, 518, 290));
        labelP->setMouseTracking(true);
        horizontalLayout = new QHBoxLayout(labelP);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imageLabelM = new QLabel(labelP);
        imageLabelM->setObjectName(QString::fromUtf8("imageLabelM"));
        imageLabelM->setAutoFillBackground(true);
        imageLabelM->setScaledContents(true);

        horizontalLayout->addWidget(imageLabelM);

        scrollAreaM->setWidget(labelP);

        gridLayout_2->addWidget(scrollAreaM, 0, 0, 1, 1);

        diagBoxM = new QGroupBox(centralwidget);
        diagBoxM->setObjectName(QString::fromUtf8("diagBoxM"));
        gridLayout_3 = new QGridLayout(diagBoxM);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        calcLabelM_V = new QLCDNumber(diagBoxM);
        calcLabelM_V->setObjectName(QString::fromUtf8("calcLabelM_V"));

        gridLayout_3->addWidget(calcLabelM_V, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 1);

        calcLabelM = new QLabel(diagBoxM);
        calcLabelM->setObjectName(QString::fromUtf8("calcLabelM"));

        gridLayout_3->addWidget(calcLabelM, 1, 0, 1, 1);

        label_19 = new QLabel(diagBoxM);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 0, 0, 1, 1);

        label_20 = new QLabel(diagBoxM);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_3->addWidget(label_20, 0, 1, 1, 1);


        gridLayout_2->addWidget(diagBoxM, 0, 2, 1, 1, Qt::AlignLeft);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        calcLabelJ_V = new QLCDNumber(groupBox);
        calcLabelJ_V->setObjectName(QString::fromUtf8("calcLabelJ_V"));

        gridLayout_5->addWidget(calcLabelJ_V, 0, 1, 1, 1);

        calcLabelJ = new QLabel(groupBox);
        calcLabelJ->setObjectName(QString::fromUtf8("calcLabelJ"));

        gridLayout_5->addWidget(calcLabelJ, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 2, 1, 1);

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
        QWidget::setTabOrder(updateButton, lineEdit_J_Ro);
        QWidget::setTabOrder(lineEdit_J_Ro, lineEdit_J_Io);
        QWidget::setTabOrder(lineEdit_J_Io, lineEdit_J_Rs);
        QWidget::setTabOrder(lineEdit_J_Rs, lineEdit_J_Is);
        QWidget::setTabOrder(lineEdit_J_Is, lineEdit_J_cR);
        QWidget::setTabOrder(lineEdit_J_cR, lineEdit_J_cI);
        QWidget::setTabOrder(lineEdit_J_cI, lineEdit_J_NR);
        QWidget::setTabOrder(lineEdit_J_NR, lineEdit_J_NI);
        QWidget::setTabOrder(lineEdit_J_NI, lineEdit_J_NK);
        QWidget::setTabOrder(lineEdit_J_NK, scrollAreaJ);
        QWidget::setTabOrder(scrollAreaJ, scrollAreaM);

        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewer)
    {
        ImageViewer->setWindowTitle(QCoreApplication::translate("ImageViewer", "ImageViewer", nullptr));
        groupBoxJ->setTitle(QCoreApplication::translate("ImageViewer", "Julia Input", nullptr));
        label_J_NIV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_J_RoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_2->setText(QCoreApplication::translate("ImageViewer", "Io", nullptr));
        label_15->setText(QCoreApplication::translate("ImageViewer", "N_K", nullptr));
        label_J_RsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_J_NKV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_13->setText(QCoreApplication::translate("ImageViewer", "N_R", nullptr));
        label_J_CrV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_6->setText(QCoreApplication::translate("ImageViewer", "cI", nullptr));
        label_J_NRV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_5->setText(QCoreApplication::translate("ImageViewer", "cR", nullptr));
        label_3->setText(QCoreApplication::translate("ImageViewer", "Ro", nullptr));
        label_9->setText(QCoreApplication::translate("ImageViewer", "Rs", nullptr));
        label_J_CiV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_J_IoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_14->setText(QCoreApplication::translate("ImageViewer", "N_I", nullptr));
        label_10->setText(QCoreApplication::translate("ImageViewer", "Is", nullptr));
        label_J_IsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        groupBoxM->setTitle(QCoreApplication::translate("ImageViewer", "Mandelbrot Input", nullptr));
        label_M_IoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_Is->setText(QCoreApplication::translate("ImageViewer", "Is", nullptr));
        label_M_RsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_NIV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_IsV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_NK->setText(QCoreApplication::translate("ImageViewer", "N_K", nullptr));
        label_M_NKV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        updateButton->setText(QCoreApplication::translate("ImageViewer", "Calculate", nullptr));
        label_M_NRV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_RoV->setText(QCoreApplication::translate("ImageViewer", "<NULL>", nullptr));
        label_M_Io->setText(QCoreApplication::translate("ImageViewer", "Io", nullptr));
        label_M_NI->setText(QCoreApplication::translate("ImageViewer", "N_I", nullptr));
        label_M_NR->setText(QCoreApplication::translate("ImageViewer", "N_R", nullptr));
        label_M_Ro->setText(QCoreApplication::translate("ImageViewer", "Ro", nullptr));
        label_M_Rs->setText(QCoreApplication::translate("ImageViewer", "Rs", nullptr));
        imageLabelJ->setText(QCoreApplication::translate("ImageViewer", "Julia Set", nullptr));
        imageLabelM->setText(QCoreApplication::translate("ImageViewer", "Parent Set", nullptr));
        diagBoxM->setTitle(QCoreApplication::translate("ImageViewer", "Map Diagnostics", nullptr));
        calcLabelM->setText(QCoreApplication::translate("ImageViewer", "Set Calc", nullptr));
        label_19->setText(QCoreApplication::translate("ImageViewer", "Coord", nullptr));
        label_20->setText(QCoreApplication::translate("ImageViewer", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ImageViewer", "Julia Diagnostics", nullptr));
        calcLabelJ->setText(QCoreApplication::translate("ImageViewer", "Set Calc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
