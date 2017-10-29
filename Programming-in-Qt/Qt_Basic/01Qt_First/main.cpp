#include "mywidget.h"
#include <QApplication>


void test()
{
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget widget;

    widget.show();

    return a.exec();
}
