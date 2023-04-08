/* An event test : Simply use eventFilter.
 *
 * author : liChengYang2019051604044
 * date : 2023-4-8
 *
 * branch : event
 *
 * 事件的分发方向，是从子控件一步步向上传递到祖宗控件的，如果子控件拦截了事件，那么父控件就接收不到事件了。
 *
 *
 * 事件过滤器:
 * 任意对象都可以提前拦截其他任意对象的事件，拦截到的事件都会在本对象的eventFilter函数中被接收到，程序员可以决定拦截并处理后是否继续放行。
 * 比如:我想在父控件先处理，处理完再让子控件处理
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
