#pragma once

#include <list>

#include "editorTab.h"

#include <QTabWidget>

class TabContainer : public QTabWidget
{
Q_OBJECT

public:
    TabContainer();
    void openFile();
    void openFile(QString path);

private:
    std::list<EditorTab*> tabs;

};
