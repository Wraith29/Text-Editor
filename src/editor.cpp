#include <fstream>

#include "editor.h"
#include "utils.h"

#include <QFileDialog>
#include <QVBoxLayout>
#include <QPlainTextEdit>

Editor::Editor()
{
    this->setLayout(new QVBoxLayout);
    textEdit = new QPlainTextEdit;
    layout()->addWidget(textEdit);
}

void Editor::openFile()
{
    auto filename = QFileDialog::getOpenFileName();
    this->currentFileName = filename;
    if (file_exists(this->currentFileName)) {
        QString content;
        std::ifstream input(this->currentFileName.toStdString());
        for (std::string line; getline(input, line);)
            content.append(QString::fromStdString(line));
        this->textEdit->setPlainText(content);
    }
}