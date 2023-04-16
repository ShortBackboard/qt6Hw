/* A program : An exit test from PPT-02 and further rewrite.
 *
 * author : liChengYang2019051604044
 * date : 2023-4-16
 *
 * branch : event
 *
 * 在Button中定义了信号
 * 在Window中定义了槽函数
 *
 */


#include <QApplication>

#include "window.h"

#include <memory>
using std::make_unique;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto window = make_unique<Window>();


    window->show();

    return a.exec();
}













