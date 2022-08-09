#include "tree.h"
#include "tabContainer.h"

#include <QFileSystemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QModelIndex>

Tree::Tree(TabContainer *_tabs)
{
    tabs = _tabs;
    model = new QFileSystemModel;
    tree = new QTreeView;

    setLayout(new QVBoxLayout);
}

void Tree::openFolder()
{
    auto path = QFileDialog::getExistingDirectory();
    model->setRootPath(path);
    auto index = model->index(model->rootPath());
    tree->setModel(model);
    tree->setRootIndex(index);
}

void Tree::onClick(QModelIndex index)
{
    auto fileIndex = model->index(index.row(), 0, index.parent());
    if (model->fileInfo(fileIndex).isDir())
    {
        return;
    }
    auto path = model->fileInfo(fileIndex).absolutePath();
    tabs->openFile(path);
}