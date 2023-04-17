#include "button.h"
#include <QDebug>
#include <QApplication>


Button::Button(QWidget *parent):QPushButton(parent)
{
    setText("Exit");
    setGeometry(10,50,80,30);
}


void Button::timerEvent(QTimerEvent *e){//定时器超时触发事件
    qDebug() <<"overtime";
    killTimer(m_timerId);//关闭定时器
    m_timerId = 0;//超时改变成员变量定时器的id
}


bool Button::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress){
        using namespace std::chrono;
        m_timerId = startTimer(milliseconds(300));//创建并启动定时器,返回定时器Id,随机Id
    }

    if(e->type() == QEvent::MouseButtonRelease){

        if(m_timerId != 0){//未超300ms
            killTimer(m_timerId);//关闭定时器
            mouseClick();
        }else{
            e->ignore();
        }
    }

    return QWidget::event(e);
}



void Button::mouseClick(){
    QApplication::quit();
}














