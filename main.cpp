/* An event test : Observe the orders of events obtained from subclasses and parent classes
 *
 * author : liChengYang2019051604044
 * date : 2023-4-8
 *
 * branch : event
*/

#include "window.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();
    return a.exec();
}
