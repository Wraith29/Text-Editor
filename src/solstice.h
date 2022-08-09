#pragma once

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

    void configure();

    void openFile();
    void openFolder();

    void configureMenus();
};