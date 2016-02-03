#include "mainwindow.h"
#include <QApplication>
//#include <TFile.h>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.initializeDefaults();
    a.exec();

}
