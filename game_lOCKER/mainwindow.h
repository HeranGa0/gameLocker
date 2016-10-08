#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QString fileName;
     QString ax;
     QString time;
      QString time2;
     int LcdChange1();
     int LcdChange2();
     bool Lcd1;
     bool Lcd2;
protected:
     bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
