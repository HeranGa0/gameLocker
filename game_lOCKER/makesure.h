#ifndef MAKESURE_H
#define MAKESURE_H
#include "settime.h"
#include "ui_settime.h"
#include <QDialog>

namespace Ui {
class MakeSure;
}

class MakeSure : public QDialog
{
    Q_OBJECT

public:
     explicit MakeSure(QWidget *parent = 0);
    ~MakeSure();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MakeSure *ui;
};

#endif // MAKESURE_H
