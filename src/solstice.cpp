#include <iostream>

#include "solstice.h"

#include <QRect>
#include <QWidget>
#include <QString>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QHBoxLayout>

Solstice::Solstice()
{
    this->configure();
}

void Solstice::configure()
{
    this->setWindowTitle("Solstice Editor");
    this->setGeometry(QRect {160, 90, 1600, 900});
    centralWidget = new QWidget;
    layout = new QHBoxLayout;

    centralWidget->setLayout(layout);
    this->setCentralWidget(centralWidget);
    this->configureMenus();
}

void Solstice::openFile()
{
    std::cout << "Solstice::openFile()\n";
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
