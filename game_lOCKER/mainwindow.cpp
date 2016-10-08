#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settime.h"
#include "ui_settime.h"
#include<QDragEnterEvent>
#include<QDropEvent>
#include<QMimeData>
#include<QDebug>
#include<QProcess>
#include<QIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time=" ";
    //ax="start ";
    ui->label->setAcceptDrops(true);
    ui->label->setMouseTracking(true);
     ui->label->installEventFilter(this);
     ui->label_2->setAcceptDrops(true);
     ui->label_2->setMouseTracking(true);
      ui->label_2->installEventFilter(this);
      Lcd1=false;
      Lcd2=false;
      //QIcon icon1(":/images/newPos");
     // ui->toolButton->setIcon(icon1);

}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==ui->label)
    {
        if(event->type()==QEvent::DragEnter)
        {
            QDragEnterEvent * draEvent=dynamic_cast<QDragEnterEvent*>(event);
            draEvent->acceptProposedAction();
        }
        else if(event->type()==QEvent::Drop)
        {  Lcd1=true;Lcd2=false;
            QDropEvent *droEvent=dynamic_cast<QDropEvent*>(event);


            QList<QUrl> urls = droEvent->mimeData()->urls();

            fileName = urls.first().toLocalFile();
            fileName.replace("/","\\");
           // fileName = ax+fileName;
            //fileName="C:\\Users\\Administrator\\Desktop\\jisuanqi.ico";
              fileName="move " +fileName + " d:\\";
            qDebug()<<fileName;
          //system(qPrintable(fileName));
            //system(fileName);
          //QProcess::execute(fileName);
          setTime *settime1=new setTime(this,&time);
           ui->lcdNumber->display("0:00");
          settime1->show();

        }
    }
    if(obj==ui->label_2)
    {
        if(event->type()==QEvent::DragEnter)
        {
            QDragEnterEvent * draEvent=dynamic_cast<QDragEnterEvent*>(event);
            draEvent->acceptProposedAction();
        }
        else if(event->type()==QEvent::Drop)
        { Lcd2=true;Lcd1=false;
            QDropEvent *droEvent=dynamic_cast<QDropEvent*>(event);


           // QList<QUrl> urls = droEvent->mimeData()->urls();

           // fileName = urls.first().toLocalFile();
            //fileName.replace("/","\\");
           // fileName = ax+fileName;
            //fileName="C:\\Users\\Administrator\\Desktop\\jisuanqi.ico";
              //fileName="move " +fileName + " d:\\";
            //qDebug()<<fileName;
          //system(qPrintable(fileName));
            //system(fileName);
          //QProcess::execute(fileName);
          setTime *settime2=new setTime(this,&time2);
           ui->lcdNumber_2->display("0:00");
          settime2->show();

        }
    }
    return false;
}

int MainWindow::LcdChange1()
{
    ui->lcdNumber->display(time);
    return 0;

}
int MainWindow::LcdChange2()
{
    ui->lcdNumber_2->display(time2);
    return 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
