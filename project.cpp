#include "project.h"

Project::Project(QObject *parent) :
    QObject(parent)
{
}

void Project::assign(QJsonObject json){
    this->name = json["name"].toString();
    this->id = json["id"].toInt();
}
