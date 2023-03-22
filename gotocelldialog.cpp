#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QtWidgets>
#include <QtGui>


gotocelldialog::gotocelldialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);
    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");//正则表达式
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, this));//设置文本框内容规则

    connect(ui->okButton,SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->cancelButton,SIGNAL(clicked()) ,this, SLOT(reject()));

}

void gotocelldialog::on_lineEdit_textChanged(){
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());//判断文本框的内容是否有效
}


gotocelldialog::~gotocelldialog()
{
    delete ui;
}

