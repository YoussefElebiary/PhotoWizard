/********************************************************************************
** Form generated from reading UI file 'babyphotoshop.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BABYPHOTOSHOP_H
#define UI_BABYPHOTOSHOP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoWizard
{
public:
    QWidget *centralwidget;
    QPushButton *save;
    QLabel *credits;
    QPushButton *detect;
    QPushButton *resize;
    QLabel *image2;
    QPushButton *tv;
    QLabel *label_2;
    QPushButton *light;
    QPushButton *ir;
    QPushButton *gray;
    QPushButton *previous;
    QLabel *file_name;
    QPushButton *oil;
    QPushButton *frame;
    QPushButton *dark_red;
    QPushButton *blur;
    QPushButton *flip_h;
    QPushButton *purple;
    QPushButton *flip_v;
    QPushButton *invert;
    QPushButton *skew;
    QLabel *image1;
    QPushButton *crop;
    QPushButton *b_w;
    QPushButton *dark;
    QPushButton *rotate;
    QPushButton *load;
    QSlider *blur_s;
    QPushButton *slytherin;
    QPushButton *clear;
    QPushButton *sunlight;
    QPushButton *merge;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PhotoWizard)
    {
        if (PhotoWizard->objectName().isEmpty())
            PhotoWizard->setObjectName("PhotoWizard");
        PhotoWizard->resize(1000, 443);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PhotoWizard->setWindowIcon(icon);
        PhotoWizard->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: rgb(238, 229, 221);\n"
"}"));
        centralwidget = new QWidget(PhotoWizard);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(0, 400));
        save = new QPushButton(centralwidget);
        save->setObjectName("save");
        save->setGeometry(QRect(190, 310, 161, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        save->setFont(font);
        save->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        credits = new QLabel(centralwidget);
        credits->setObjectName("credits");
        credits->setGeometry(QRect(50, 350, 291, 21));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        credits->setFont(font1);
        credits->setTextInteractionFlags(Qt::NoTextInteraction);
        detect = new QPushButton(centralwidget);
        detect->setObjectName("detect");
        detect->setGeometry(QRect(760, 290, 101, 21));
        QFont font2;
        font2.setBold(true);
        detect->setFont(font2);
        detect->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        resize = new QPushButton(centralwidget);
        resize->setObjectName("resize");
        resize->setGeometry(QRect(760, 170, 101, 21));
        resize->setFont(font2);
        resize->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        image2 = new QLabel(centralwidget);
        image2->setObjectName("image2");
        image2->setGeometry(QRect(370, 40, 331, 251));
        image2->setFrameShape(QFrame::Box);
        image2->setFrameShadow(QFrame::Plain);
        image2->setScaledContents(true);
        image2->setTextInteractionFlags(Qt::NoTextInteraction);
        tv = new QPushButton(centralwidget);
        tv->setObjectName("tv");
        tv->setGeometry(QRect(760, 260, 101, 21));
        tv->setFont(font2);
        tv->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(760, 320, 31, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        light = new QPushButton(centralwidget);
        light->setObjectName("light");
        light->setGeometry(QRect(870, 80, 51, 21));
        light->setFont(font2);
        light->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        ir = new QPushButton(centralwidget);
        ir->setObjectName("ir");
        ir->setGeometry(QRect(760, 200, 101, 21));
        ir->setFont(font2);
        ir->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        gray = new QPushButton(centralwidget);
        gray->setObjectName("gray");
        gray->setGeometry(QRect(760, 20, 101, 21));
        gray->setFont(font2);
        gray->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        previous = new QPushButton(centralwidget);
        previous->setObjectName("previous");
        previous->setGeometry(QRect(370, 310, 161, 41));
        previous->setFont(font);
        previous->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        file_name = new QLabel(centralwidget);
        file_name->setObjectName("file_name");
        file_name->setGeometry(QRect(-60, 0, 300, 31));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(file_name->sizePolicy().hasHeightForWidth());
        file_name->setSizePolicy(sizePolicy);
        file_name->setMinimumSize(QSize(10, 31));
        file_name->setMaximumSize(QSize(300, 31));
        file_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 800 17pt \"Segoe UI\";\n"
"	color :rgb(0, 0, 255);\n"
"}"));
        file_name->setFrameShape(QFrame::NoFrame);
        file_name->setLineWidth(2);
        file_name->setMidLineWidth(2);
        file_name->setTextFormat(Qt::PlainText);
        file_name->setAlignment(Qt::AlignCenter);
        file_name->setTextInteractionFlags(Qt::NoTextInteraction);
        oil = new QPushButton(centralwidget);
        oil->setObjectName("oil");
        oil->setGeometry(QRect(760, 110, 101, 21));
        oil->setFont(font2);
        oil->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        frame = new QPushButton(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(870, 110, 101, 21));
        frame->setFont(font2);
        frame->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        dark_red = new QPushButton(centralwidget);
        dark_red->setObjectName("dark_red");
        dark_red->setGeometry(QRect(870, 170, 101, 21));
        dark_red->setFont(font2);
        dark_red->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        blur = new QPushButton(centralwidget);
        blur->setObjectName("blur");
        blur->setGeometry(QRect(760, 140, 101, 21));
        blur->setFont(font2);
        blur->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        flip_h = new QPushButton(centralwidget);
        flip_h->setObjectName("flip_h");
        flip_h->setGeometry(QRect(810, 80, 51, 21));
        flip_h->setFont(font2);
        flip_h->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        purple = new QPushButton(centralwidget);
        purple->setObjectName("purple");
        purple->setGeometry(QRect(760, 230, 101, 21));
        purple->setFont(font2);
        purple->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        flip_v = new QPushButton(centralwidget);
        flip_v->setObjectName("flip_v");
        flip_v->setGeometry(QRect(760, 80, 51, 21));
        flip_v->setFont(font2);
        flip_v->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        invert = new QPushButton(centralwidget);
        invert->setObjectName("invert");
        invert->setGeometry(QRect(760, 50, 101, 21));
        invert->setFont(font2);
        invert->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        invert->setFlat(false);
        skew = new QPushButton(centralwidget);
        skew->setObjectName("skew");
        skew->setGeometry(QRect(870, 200, 101, 21));
        skew->setFont(font2);
        skew->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        image1 = new QLabel(centralwidget);
        image1->setObjectName("image1");
        image1->setGeometry(QRect(20, 40, 331, 251));
        image1->setFrameShape(QFrame::Box);
        image1->setFrameShadow(QFrame::Plain);
        image1->setScaledContents(true);
        image1->setTextInteractionFlags(Qt::NoTextInteraction);
        crop = new QPushButton(centralwidget);
        crop->setObjectName("crop");
        crop->setGeometry(QRect(870, 140, 101, 21));
        crop->setFont(font2);
        crop->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        b_w = new QPushButton(centralwidget);
        b_w->setObjectName("b_w");
        b_w->setGeometry(QRect(870, 20, 101, 21));
        b_w->setFont(font2);
        b_w->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        b_w->setFlat(false);
        dark = new QPushButton(centralwidget);
        dark->setObjectName("dark");
        dark->setGeometry(QRect(920, 80, 51, 21));
        dark->setFont(font2);
        dark->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        rotate = new QPushButton(centralwidget);
        rotate->setObjectName("rotate");
        rotate->setGeometry(QRect(870, 50, 101, 21));
        rotate->setFont(font2);
        rotate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        load = new QPushButton(centralwidget);
        load->setObjectName("load");
        load->setGeometry(QRect(20, 310, 161, 41));
        load->setFont(font);
        load->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        blur_s = new QSlider(centralwidget);
        blur_s->setObjectName("blur_s");
        blur_s->setGeometry(QRect(790, 320, 181, 21));
        QFont font4;
        font4.setBold(false);
        blur_s->setFont(font4);
        blur_s->setMinimum(1);
        blur_s->setMaximum(100);
        blur_s->setOrientation(Qt::Horizontal);
        slytherin = new QPushButton(centralwidget);
        slytherin->setObjectName("slytherin");
        slytherin->setGeometry(QRect(870, 260, 101, 21));
        slytherin->setFont(font2);
        slytherin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        clear = new QPushButton(centralwidget);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(540, 310, 161, 41));
        clear->setFont(font);
        clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        sunlight = new QPushButton(centralwidget);
        sunlight->setObjectName("sunlight");
        sunlight->setGeometry(QRect(870, 230, 101, 21));
        sunlight->setFont(font2);
        sunlight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        merge = new QPushButton(centralwidget);
        merge->setObjectName("merge");
        merge->setGeometry(QRect(870, 290, 101, 21));
        merge->setFont(font2);
        merge->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(200, 198, 255);\n"
"	color: rgb(0, 0, 0);\n"
"	border: 1px;\n"
"	border-radius: 10px;\n"
"}"));
        PhotoWizard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PhotoWizard);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        PhotoWizard->setMenuBar(menubar);
        statusbar = new QStatusBar(PhotoWizard);
        statusbar->setObjectName("statusbar");
        PhotoWizard->setStatusBar(statusbar);

        retranslateUi(PhotoWizard);

        QMetaObject::connectSlotsByName(PhotoWizard);
    } // setupUi

    void retranslateUi(QMainWindow *PhotoWizard)
    {
        PhotoWizard->setWindowTitle(QCoreApplication::translate("PhotoWizard", "PhotoWizard", nullptr));
        save->setText(QCoreApplication::translate("PhotoWizard", "Save", nullptr));
#if QT_CONFIG(shortcut)
        save->setShortcut(QCoreApplication::translate("PhotoWizard", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        credits->setText(QCoreApplication::translate("PhotoWizard", "  Youssef Elebiary     Nagham Wael     Zainab Mostafa", nullptr));
        detect->setText(QCoreApplication::translate("PhotoWizard", "Detect Edges", nullptr));
        resize->setText(QCoreApplication::translate("PhotoWizard", "Resize", nullptr));
        image2->setText(QString());
        tv->setText(QCoreApplication::translate("PhotoWizard", "TV", nullptr));
        label_2->setText(QCoreApplication::translate("PhotoWizard", "Blur", nullptr));
        light->setText(QCoreApplication::translate("PhotoWizard", "Lighten", nullptr));
        ir->setText(QCoreApplication::translate("PhotoWizard", "Infrared", nullptr));
        gray->setText(QCoreApplication::translate("PhotoWizard", "GrayScale", nullptr));
        previous->setText(QCoreApplication::translate("PhotoWizard", "Previous", nullptr));
        file_name->setText(QCoreApplication::translate("PhotoWizard", "PhotoWizard", nullptr));
        oil->setText(QCoreApplication::translate("PhotoWizard", "Oil Painting", nullptr));
        frame->setText(QCoreApplication::translate("PhotoWizard", "Frame", nullptr));
        dark_red->setText(QCoreApplication::translate("PhotoWizard", "Dark Red", nullptr));
        blur->setText(QCoreApplication::translate("PhotoWizard", "Blur", nullptr));
        flip_h->setText(QCoreApplication::translate("PhotoWizard", "Flip H", nullptr));
        purple->setText(QCoreApplication::translate("PhotoWizard", "Purple", nullptr));
        flip_v->setText(QCoreApplication::translate("PhotoWizard", "Flip V", nullptr));
        invert->setText(QCoreApplication::translate("PhotoWizard", "Invert", nullptr));
        skew->setText(QCoreApplication::translate("PhotoWizard", "Skew", nullptr));
        image1->setText(QString());
        crop->setText(QCoreApplication::translate("PhotoWizard", "Crop", nullptr));
        b_w->setText(QCoreApplication::translate("PhotoWizard", "B/W", nullptr));
        dark->setText(QCoreApplication::translate("PhotoWizard", "Darken", nullptr));
        rotate->setText(QCoreApplication::translate("PhotoWizard", "Rotate", nullptr));
#if QT_CONFIG(whatsthis)
        load->setWhatsThis(QCoreApplication::translate("PhotoWizard", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        load->setText(QCoreApplication::translate("PhotoWizard", "Load", nullptr));
        slytherin->setText(QCoreApplication::translate("PhotoWizard", "Slytherin", nullptr));
        clear->setText(QCoreApplication::translate("PhotoWizard", "Clear", nullptr));
#if QT_CONFIG(shortcut)
        clear->setShortcut(QCoreApplication::translate("PhotoWizard", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        sunlight->setText(QCoreApplication::translate("PhotoWizard", "Sun Light", nullptr));
        merge->setText(QCoreApplication::translate("PhotoWizard", "Merge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhotoWizard: public Ui_PhotoWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BABYPHOTOSHOP_H
