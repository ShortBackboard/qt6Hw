/*
 * A program : gotocelldialog using single inheit 
 *
 * anthor:liChengYang
 * date:2023-3-15
 *
*/

#include "gotocelldialog.h"
#include <QDialog>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    gotocelldialog *dialog = new gotocelldialog;
    dialog->show();

    return app.exec();
}
