#include <iostream>

#include <QApplication>

#include "solstice.h"

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        std::cout << "Error: Must include a filename";
        return 1;
    }
    auto filename = argv[1];

    QApplication app(argc, argv);
    Solstice mw(filename);
    mw.show();

    return app.exec();
}