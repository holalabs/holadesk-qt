#include <QtGui/QApplication>
#include "holadesk.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HolaDesk w;
    w.show();

    return a.exec();
}
