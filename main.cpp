/*
 * A program : FindDialog in book chapter02
 *
 * anthor:liChengYang
 * date:2023-3-5
 * version 1.0: write by origin codes in book
 *
*/


#include <QApplication>
#include "finddialog.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    unique_ptr<FindDialog> dialog = make_unique<FindDialog>();
    dialog->show();
    return a.exec();
}
