#include <iostream>

#include "solstice.h"
#include "editor.h"

#include <QRect>
#include <QWidget>
#include <QString>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QHBoxLayout>

Solstice::Solstice()
{
    this->setWindowTitle("Solstice Editor");
    this->setGeometry(QRect {160, 90, 1600, 900});
    auto centralWidget = new QWidget;
    auto layout = new QHBoxLayout;
    editor = new Editor;

    centralWidget->setLayout(layout);
    this->setCentralWidget(centralWidget);
    this->configureMenus();
}

void Solstice::openFile()
{
    editor->openFile();
}

void Solstice::openFolder()
{
    std::cout << "Solstice::openFolder()\n";
}

void Solstice::configureMenus()
{
    auto fileMenu = menuBar()->addMenu("&File");
    auto openFileAction = fileMenu->addAction("Open");
    connect(openFileAction, &QAction::triggered, this, &Solstice::openFile);
    auto openFolderAction = fileMenu->addAction("Open Folder");
    connect(openFolderAction, &QAction::triggered, this, &Solstice::openFolder);
}
