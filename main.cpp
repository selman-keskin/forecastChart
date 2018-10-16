#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.grabGesture(Qt::PanGesture);
    w.grabGesture(Qt::PinchGesture);

    return a.exec();
}
