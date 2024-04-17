//*-----------------------------------------------------------------------------------------------*//
//Purpose     :     This is a GUI application that can apply different filters to images
//Authors     :     Youssef Ahmed Mahmoud Mohamed Elebiary   -   20231208   -   S25
//                  Nagham Wael Mohamed   -   20231189   -   S25
//                  Zainab Mostafa Mohammad   -   20231071   -   S25
//Who did what:     Youssef → GUI/Invert/Rotate/Frame/Blur
//                  Nagham → B&W/Flip/Crop/Reszie/DarkRed/InfraRed/Purple/Sunlight/TV
//                  Zainab → GrayScale/Merge/Darken&Lighten/DetectEdges/OilPainting/Skew
//Demo Video  :     https://www.youtube.com/watch?v=htMccaki04Q
//*-----------------------------------------------------------------------------------------------*//



#include "babyphotoshop.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BabyPhotoshop w;
    w.setFixedSize(1000, 375);
    QWidget* central =  w.centralWidget();
    central -> setFixedSize(1000, 375);
    w.setWindowIcon(QIcon("icon.png"));
    w.show();
    return a.exec();
}
