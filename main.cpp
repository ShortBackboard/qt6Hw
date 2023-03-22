/*
 * A program : sortdialog using single inherit
 *
 * anthor:liChengYang
 * date:2023-3-18
 *
*/

#include "sortdialog.h"
#include <QDialog>
#include <QApplication>
#include <memory>

using std::unique_ptr;
using std::make_unique;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    unique_ptr<sortdialog> dialog = make_unique<sortdialog>();
    dialog->setColumnRange('C','F');
    dialog->show();
    return a.exec();
}
