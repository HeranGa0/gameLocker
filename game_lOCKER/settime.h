#ifndef SETTIME_H
#define SETTIME_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include<QTimer>
namespace Ui {
class setTime;
}

class setTime : public QDialog
{
    Q_OBJECT

public:
    explicit setTime(MainWindow *parent = 0,QString* timE=NULL);
    ~setTime();
      bool ifContinue;
      QTimer time1;
        int start();
        int change();
        MainWindow *reciever;
        QString* time;
        bool whichLcd;
private slots:
    void on_pushButton_clicked();

private:
    Ui::setTime *ui;
};

#endif // SETTIME_H
