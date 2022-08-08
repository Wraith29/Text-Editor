#pragma once

#include <QWidget>
#include <QString>
#include <QPlainTextEdit>

class Editor : public QWidget 
{
Q_OBJECT

public:
    Editor();
    void openFile();

private:
    QPlainTextEdit *textEdit;
    QString currentFileName;

    void save();
};