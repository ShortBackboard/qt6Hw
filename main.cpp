/* An event test : ignore/accept function use.
 *
 * author : liChengYang2019051604044
 * date : 2023-4-12
 *
 * branch : event
 *
 */


#include "window.h"

#include <QApplication>
#include <memory>

using std::make_unique;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto w = make_unique<Window> ();
    w->show();
    return a.exec();
}
