#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class bridge; }//前置声明,不包含对应头文件,加快预处理速度
QT_END_NAMESPACE

class Finddialog : public QDialog//继承时需要包含头文件完整定义
{
    Q_OBJECT

public:
    explicit Finddialog(QWidget *parent = nullptr);
    virtual ~Finddialog();
    //virtual void reject() override;
    //virtual void accept() override;//按下ok按钮时调用,需要connect

private slots:
    void on__close_clicked();

private:
    Ui::bridge *_ui;//组合关系
};


#endif // FINDDIALOG_H
