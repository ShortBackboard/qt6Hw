#include "finddialog.h"
#include "ui_find.h"


Finddialog::Finddialog(QWidget *parent):
    QDialog(parent),
    _ui{new Ui::bridge{}}
{
    _ui->setupUi(this);//建立父子关系
}

Finddialog::~Finddialog()
{
    delete _ui;//堆对象
}

void Finddialog::on__close_clicked()
{
    exit(0);
}

