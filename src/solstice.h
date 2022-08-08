#pragma once

#include "tabs.h"

#include <QMainWindow>

class Solstice : public QMainWindow
{
Q_OBJECT

public:
    Solstice();

private:
    Tabs *tabs;

    void openFile();
    void openFolder();

    void configureMenus();
};