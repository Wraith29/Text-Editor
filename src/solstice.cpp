#include <iostream>

#include "solstice.h"

#include <QString>
#include <QRect>
#include <QWidget>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QHBoxLayout>

Solstice::Solstice()
{
    configure();
}

void Solstice::configure()
{
    setWindowTitle("Solstice Editor");
    setGeometry(QRect {160, 90, 1600, 900});
    centralWidget = new QWidget;
    layout = new QHBoxLayout;
    tabContainer = new TabContainer;
    layout->addWidget(tabContainer);
    tree = new Tree(tabContainer);
    treeViewEnabled = false;

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    configureMenus();
}

void Solstice::openFile()
{
    tabContainer->openFile();
}

void Solstice::openFolder()
{
    std::cout << "Opening Folder\n";
    if (!treeViewEnabled) 
    {
        layout->addWidget(tree);
        treeViewEnabled = true;
    }
    tree->openFolder();
}

void Solstice::configureMenus()
{
    auto fileMenu = menuBar()->addMenu("&File");
    auto openFileAction = fileMenu->addAction("Open");
    connect(openFileAction, &QAction::triggered, this, &Solstice::openFile);
    auto openFolderAction = fileMenu->addAction("Open Folder");
    connect(openFolderAction, &QAction::triggered, this, &Solstice::openFolder);
}
