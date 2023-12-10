#include "imageviewer.h"

#include <QApplication>


#include <chrono> // Timing library
using namespace chrono;
#include <iostream>
using namespace std;

#include <map>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViewer mainWindow;

    mainWindow.show();

    return a.exec();
}
