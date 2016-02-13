#include "main_window.h"
#include <QApplication>

#include "TH1D.h"

int main(int argc, char *argv[])
{
    TH1D  th("th1tst","Test",100,-20.5,60.4);

    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.initializeDefaults();
    a.exec();


}
