#include <fstream>
#include <iostream>

#include "editorTab.h"

#include <QPlainTextEdit>
#include <QMessageBox>
#include <QVBoxLayout>

EditorTab::EditorTab(QString filename)
{
    edit = new QPlainTextEdit;
    setLayout(new QVBoxLayout);
    layout()->addWidget(edit);

    std::ifstream input(filename.toStdString());
    if (input.bad())
    {
        QMessageBox(
            QMessageBox::Icon::Critical,
            "Error Opening File",
            "An error occured when trying to open file: " + filename
        );
        return;
    }

    QString content;
    for (std::string line; getline(input, line) ; )
    {
        content.append(QString::fromStdString(line) + '\n');
    }

    edit->setPlainText(content);
}