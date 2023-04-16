#include "button.h"
#include <QDebug>




Button::Button(QWidget *parent):QPushButton(parent)
{
    setText("Exit");
    setGeometry(10,50,80,30);
}


bool Button::event(QEvent *e)
{

    int flag = 0;

    if(e->type() == QEvent::MouseButtonPress){        
        pressTime = QDateTime::currentDateTime();//获得当前时间
        qDebug() << "mousePress : " << pressTime;
    }

    if(e->type() == QEvent::MouseButtonRelease){
        releaseTime = QDateTime::currentDateTime();
        qDebug() << "mouseRelease : " << releaseTime;
        flag = 1;
    }


    //如果点击与释放鼠标间隙小于300ms,发出信号
    if(flag){
    qint64 offsetTime = pressTime.msecsTo(releaseTime);
        qDebug() << "offsetTime : " << offsetTime;

        if(offsetTime<=300){
            emit mouseClick();
        }
    }

    return QWidget::event(e);
}




