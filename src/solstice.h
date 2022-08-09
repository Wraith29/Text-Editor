#pragma once

#include <string>

#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPlainTextEdit>

class Solstice : public QMainWindow
{
Q_OBJECT

public:
    Solstice(std::string filename);

private:
    std::string filename;
    QWidget *centralWidget;
    QHBoxLayout *layout;
    QPlainTextEdit *editor;
};