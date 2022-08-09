#pragma once

#include "tabContainer.h"

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>

class Solstice : public QMainWindow
{
Q_OBJECT

public:
    Solstice();

private:
    QWidget *centralWidget;
    QHBoxLayout *layout;
    TabContainer *tabContainer;

    void configure();
    void openFile();
    void openFolder();
    void configureMenus();
};