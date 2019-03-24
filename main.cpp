#include "xmlparser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XMLParser w;
    w.show();

    return a.exec();
}
