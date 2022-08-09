#include <iostream>
#include <string>
#include <fstream>

#include "solstice.h"

#include <QRect>
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPlainTextEdit>

std::string readFile(std::string filename)
{
    std::ifstream input(filename);
    if (input.bad())
    {
        QMessageBox(
            QMessageBox::Icon::Critical,
            QString::fromStdString("IOError"),
            QString::fromStdString("Error opening file: " + filename)
        );
        return "";
    }

    std::string content;
    for (std::string line; getline(input, line);)
        content.append(line + '\n');
    return content;
}

Solstice::Solstice(std::string _filename) : filename(_filename)
{
    setWindowTitle("Solstice Editor");
    setGeometry(QRect {160, 90, 1600, 900});
    editor = new QPlainTextEdit;
    editor->setPlainText(QString::fromStdString(readFile(filename)));


    auto central = new QWidget;
    central->setLayout(new QVBoxLayout);
    central->layout()->addWidget(editor);
    setCentralWidget(central);
}
