#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

#include "ui_gotocelldialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gotocelldialog; }
QT_END_NAMESPACE

class gotocelldialog : public QDialog
{
    Q_OBJECT



public:
    gotocelldialog(QWidget *parent = nullptr);
    ~gotocelldialog();

private slots:
    void on_lineEdit_textChanged();

private:
    Ui::GoToCellDialog *ui;
};
#endif // GOTOCELLDIALOG_H
