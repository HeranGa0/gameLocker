#include "settime.h"
#include "ui_settime.h"
#include "makesure.h"
#include "ui_makesure.h"
#include<QTime>
#include<QMessageBox>
setTime::setTime(MainWindow *parent,QString* timE) :
    QDialog(parent),
    ui(new Ui::setTime)
{
    ui->setupUi(this);
    reciever=dynamic_cast<MainWindow*>(this->parent());
    connect(this,&setTime::hide,this,&setTime::start);
    connect(&time1,&QTimer::timeout,this,&setTime::change);
    time=timE;
     whichLcd=reciever->Lcd1;
}

setTime::~setTime()
{
    delete ui;

}

void setTime::on_pushButton_clicked()
{    QTime test=ui->timeEdit->time();
     if(QTime(0,0)==test)
     {
         QMessageBox warning2(this);
         warning2.setText("Please Set time!");
         warning2.exec();
     }
     else
     {
          MakeSure ms(this);
          ms.exec();
          if(ifContinue==true)
          {
            this->hide();
              this->start();
          }

     }

}

int setTime::start()
{
    time1.start(1000);
    return 0;
}

int setTime::change()
{
    QTime sub=ui->timeEdit->time().addSecs(-1);
     ui->timeEdit->setTime(sub);

     QString here=ui->timeEdit->text();

   //reciever->time=here;
     *time=here;
   if(whichLcd){ reciever->LcdChange1();}
   if(!whichLcd){reciever->LcdChange2();}
     if(sub == QTime(0, 0))
     {
        this->deleteLater();
     }
     return 0;
}
