#pragma once

#include "editor.h"

#include <QMainWindow>

class Solstice : public QMainWindow
{
Q_OBJECT

public:
    Solstice();

private:
    Editor *editor;

    void openFile();
    void openFolder();

    void configureMenus();
};