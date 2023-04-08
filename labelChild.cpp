#include "labelChild.h"
#include <QDebug>


LabelChild::LabelChild(QWidget *parent):QLabel(parent)
{
    setGeometry(0,0,100,50);
    setText("LabelChild");
    setBackgroundRole(QPalette::Light);
    setAutoFillBackground(true);

}

bool LabelChild::event(QEvent *e)
{
    if(e->type() == QEvent::MouseMove){
        qDebug() << "move in" << "LabelChild::event.";
        e->accept();
        //return true;//则事件不会继续传递
    }

    return QWidget::event(e);
}
