/*
 * A program : FindDialog rewrite
 *
 * anthor:2019051604044liChengYang
 * date:2023-4-20
 * 
 * 重写finddialog，用ui文件的桥梁类对象方法完成
 *
*/


#include <QApplication>
#include "finddialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Finddialog finddialog;
    finddialog.show();

    return a.exec();

}
