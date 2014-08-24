#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>
#include <QJsonObject>

class Project : public QObject
{
    Q_OBJECT
public:
    explicit Project(QObject *parent = 0);
    void assign(QJsonObject);

    QString name;
    qulonglong id;

signals:

public slots:

};

#endif // PROJECT_H
