#include "button.h"
#include <QDebug>
#include <QApplication>
#define TIMER_INTERVAL 300 //定义时间间隔300ms


Button::Button(QWidget *parent):QPushButton(parent)
{
    setText("Exit");
    setGeometry(10,50,80,30);
}


void Button::mouseClickEvent(QMouseEvent *e)
{
    qDebug() << "mouse click in Button::mouseClickEvent().";
    qApp->exit();//异步
    qDebug() << "after exit() in Button::mouseClickEvent().";
}



bool Button::event(QEvent *e)
{
    switch (e->type()) {

    case QEvent::MouseButtonPress:
        qDebug() << "\nmousePress().";
        if(!singleShotTimer.isActive()){
            singleShotTimer.start(TIMER_INTERVAL,this);//开启定时器
        }
        break;

    case QEvent::MouseButtonRelease:
        qDebug() << "mouseRelease().";
        if(singleShotTimer.isActive()){//在间隔时间之内
            singleShotTimer.stop();//停止定时器
            mouseClickEvent((QMouseEvent *)e);//关闭窗口函数
        }
        break;
    }
    return QPushButton::event(e);
}


void Button::timerEvent(QTimerEvent *e)//定时器超时自动触发事件
{
    singleShotTimer.stop();  //自动重复循环计时,需手动主动关闭
    qDebug() << "singleShotTimer stop.";
}
