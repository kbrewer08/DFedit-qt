#include <QApplication>
#include "MainContentHolder.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainContentHolder mch;
    mch.show();

    return a.exec();
}
