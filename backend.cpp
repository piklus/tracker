#include "backend.h"

Backend::Backend(QObject *parent) :
    QObject(parent)
{
}

void Backend::loadProjects() {
    if (loadingProjects) return;

    QUrl url = QUrl(serverURL);
    url.setPath("/api/projects.json");
    reply = qnam.get(QNetworkRequest( url ));
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
}

void Backend::httpFinished(){
    QString json = reply->readAll();
    auto jsonDoc = QJsonDocument::fromJson(json.toUtf8());
    QJsonArray array = jsonDoc.array();
    QList<Project*> *list = new QList<Project*>();
    for( int i = 0; i < array.count(); ++i ){
        Project *project = new Project();
        project->assign(array.at(i).toObject());
        list->append(project);
        qDebug() << array.at(i);
    }
    emit projectsLoaded(list);
}
