//author:stardust
//date: 2023-03-19
//采用指针的方式来实现GoToCellDialog类和Ui::bridge类的组合关系
//Ui::bridge类存放在ui_gotocell.h中，该头文件是通过编译gotocell.ui文件自动生成的。
#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class gotocell_bridge; }
QT_END_NAMESPACE


class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent = nullptr);
    ~GoToCellDialog();
    virtual void reject() override;  //override the QDialog::reject();
    virtual void accept() override;
    QString getCellLocation();
private slots:
    void on_lineEdit_textChanged();

private:
    Ui::gotocell_bridge *_ui; // GoToCellDialog对象与其资源对象_ui之间通过指针的方式实现了组合关系
                     // 由于Qt对象不允许复制，所以只需要对_ui资源对象在析构函数中析构即可
};
#endif // GOTOCELLDIALOG_H
