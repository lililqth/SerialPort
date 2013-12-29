#include <QtGui/QApplication>
#include "serialportclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialPortclient w;
    w.show();

    return a.exec();
}
