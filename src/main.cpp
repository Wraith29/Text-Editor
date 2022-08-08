#include <iostream>

#include <QApplication>

#include "solstice.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Solstice mw;
    mw.show();

    return app.exec();
}