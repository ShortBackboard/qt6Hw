#ifndef MESSAGE_H
#define MESSAGE_H
#include <QDateTime>
#include <QQmlEngine>

class Message : public QObject{
    Q_OBJECT

    //a group of setter getter and signal
    Q_PROPERTY(QString author READ author WRITE setAuthor
                   NOTIFY authorChanged)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate
                   NOTIFY creationDateChanged)

    QML_ELEMENT //使用这些宏需要 #include <QQmlEngine>
    // QML_NAMED_ELEMENT(Msg)

public:
    explicit Message(QObject *parent = 0);

    QDateTime creationDate() const;
    void setCreationDate(const QDateTime dt);

    QString author() const;
    void setAuthor(const QString &a);
signals:
    void authorChanged();
    void creationDateChanged();
private:
    QString m_author;
    QDateTime m_creationDate;
};

#endif // MESSAGE_H
