#include "tabContainer.h"

#include <fstream>
#include <QFileDialog>
#include <QString>

TabContainer::TabContainer()
{
    tabs = {};
}

void TabContainer::openFile()
{
    auto path = QFileDialog::getOpenFileName();
    auto name = path.split("/").last();
    auto tab = new EditorTab(path);
    tabs.push_back(tab);
    addTab(tab, name);
}

void TabContainer::openFile(QString path)
{
    auto name = path.split("/").last();
    auto tab = new EditorTab(path);
    tabs.push_back(tab);
    addTab(tab, name);
}
