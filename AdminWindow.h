#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

private slots:
    void on_PushButton_BackTMain_clicked();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
