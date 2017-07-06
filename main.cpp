#include "testnet.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Testnet w;
    w.show();

    return a.exec();
}
