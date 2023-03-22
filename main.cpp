/*
 * A program : FindDialog in book chapter02
 *
 * anthor:liChengYang
 * date:2023-3-5
 * version 3.0: based on object-tree
 *              using findChild() and so on
 *
*/

#include <QApplication>
#include <memory>
#include "finddialog.h"


using std::unique_ptr;
using std::make_unique;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    auto finddialog = make_unique<FindDialog>();
    finddialog->show();

    return a.exec();
}





