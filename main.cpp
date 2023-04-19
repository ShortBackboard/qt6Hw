/*
 * A program : FindDialog rewrite
 *
 * anthor:2019051604044liChengYang
 * date:2023-4-19
 * 
 * 重写finddialog，用ui文件的桥梁类对象方法完成
 *
*/


#include <QApplication>
#include <memory>
#include <QDialog>
#include "ui_finddialog.h"
//#include "finddialog.h"


using std::make_unique;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ui::bridge uib;


    QDialog finddialog;
    uib.setupUi(&finddialog);

    finddialog.show();


    return a.exec();

}
