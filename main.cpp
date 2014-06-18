#include "dfeditgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DFeditGUI dfe;
    dfe.show();

    return a.exec();
}
