#include <QCoreApplication>
#include "qzlib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const char* password = "123";

    QZlib zipClass;
    zipClass.AddDir("./1");
    zipClass.AddDir("./2");
    zipClass.AddDir("./3");

    zipClass.GenerateZip("first.zip",password);

    return a.exec();
}
