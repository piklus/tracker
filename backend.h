#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QList>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonArray>

#include <QDebug>

#include "project.h"

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = 0);
    void loadProjects();

private:
    bool loadingProjects = false;
    QString serverURL = "http://localhost:3000";
    QNetworkAccessManager qnam;
    QNetworkReply *reply;

signals:
    void projectsLoaded(QList<Project*>*);

public slots:
    void httpFinished();


};

#endif // BACKEND_H
