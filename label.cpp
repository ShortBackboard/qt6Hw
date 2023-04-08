#include "label.h"
#include <QDebug>
#include "labelChild.h"

Label::Label(QWidget *parent):QLabel(parent)
{
    _labelChild = new LabelChild{this};
    setGeometry(200,200,150,150);
    setText("Label");
    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);

}


bool Label::event(QEvent *e)
{
    if(e->type() == QEvent::MouseMove){
        qDebug() << "move in" << "Label::event.";
        e->accept();
        //return true;//则事件不会继续传递
    }

    return QWidget::event(e);
}
