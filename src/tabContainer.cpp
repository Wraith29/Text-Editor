#include "tabContainer.h"

#include <fstream>
#include <QFileDialog>

TabContainer::TabContainer()
{
    tabs = {};
}

void TabContainer::openFile()
{
    auto filepath = QFileDialog::getOpenFileName();
    auto filename = filepath.split("/").last();
    auto tab = new EditorTab(filepath);
    tabs.push_back(tab);
    addTab(tab, filename);
}