#include "makesure.h"
#include "ui_makesure.h"

MakeSure::MakeSure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MakeSure)
{
    ui->setupUi(this);
}

MakeSure::~MakeSure()
{
    delete ui;
}

void MakeSure::on_pushButton_clicked()
{
   setTime *rec=dynamic_cast<setTime*>(this->parent());
   rec->ifContinue=true;
   this->close();
}

void MakeSure::on_pushButton_2_clicked()
{
   setTime *rec=dynamic_cast<setTime*>(this->parent());
    rec->ifContinue=false;
    this->close();
}
