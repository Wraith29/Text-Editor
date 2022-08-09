#pragma once

#include <QWidget>
#include <QString>
#include <QPlainTextEdit>

class EditorTab : public QWidget
{
Q_OBJECT

public:
    EditorTab(QString filename);

private:
    QPlainTextEdit *edit;
};