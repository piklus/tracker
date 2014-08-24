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
qDebug() << "TEST";
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
}

void Backend::httpFinished(){
    QJsonArray array = QJsonDocument::fromBinaryData(reply->readAll()).array();
    QList<Project*> *list = new QList<Project*>();
    qDebug() << "TEST";
    for( int i = 0; i < array.count(); ++i ){
        Project *project = new Project();
        project->assign(array.at(i).toObject());
        list->append(project);
        qDebug() << array.at(i);
    }
    emit projectsLoaded(list);
}
