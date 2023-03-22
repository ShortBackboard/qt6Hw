#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QDialog>
#include <QtWidgets>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;


class FindDialog : public QDialog
{
    Q_OBJECT

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);


public:
    FindDialog(QWidget *parent = 0);

private:
    QPushButton *_find;
    QPushButton *_close;
    QLabel *_label;
    QLineEdit *_lineEdit;
    QCheckBox *_caseCheck;
    QCheckBox *_searchCheck;



};
#endif // FINDDIALOG_H



