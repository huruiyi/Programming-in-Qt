#include "stawidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StaWidget w;
    w.show();

    return a.exec();
}
