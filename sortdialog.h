#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>
#include "ui_sortdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class sortdialog; }
QT_END_NAMESPACE

class sortdialog : public QDialog
{
    Q_OBJECT

public:
    sortdialog(QWidget *parent = nullptr);
    ~sortdialog();

public slots:
    void setColumnRange(QChar first, QChar last);

private:
    Ui::SortDialog *ui;
};
#endif // SORTDIALOG_H
