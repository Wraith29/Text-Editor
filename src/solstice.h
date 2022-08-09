#pragma once

#include "tabContainer.h"
#include "tree.h"

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>

class Solstice : public QMainWindow
{
Q_OBJECT

public:
    Solstice();

private:
    bool treeViewEnabled;

    QWidget *centralWidget;
    QHBoxLayout *layout;
    TabContainer *tabContainer;
    Tree *tree;

    void configure();
    void openFile();
    void openFolder();
    void configureMenus();
};