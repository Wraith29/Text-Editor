#pragma once

#include "tabContainer.h"

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QString>
#include <QModelIndex>

class Tree : public QWidget
{
Q_OBJECT

public:
    Tree(TabContainer *tabs);
    void openFolder();

private:
    TabContainer *tabs;
    QFileSystemModel *model;
    QTreeView *tree;
    QString folder;

    void onClick(QModelIndex index);
};