#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QBasicTimer>

class Button : public QPushButton{
    Q_OBJECT
public:
    Button(QWidget *parent = nullptr);
    virtual void mouseClickEvent(QMouseEvent *e);

protected:
    virtual bool event(QEvent *e) override;
    virtual void timerEvent(QTimerEvent *e) override;


private:
    QBasicTimer singleShotTimer;//定时器

};

#endif // BUTTON_H
