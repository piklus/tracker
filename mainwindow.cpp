#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(backend, SIGNAL(projectsLoaded(QList<Project*>*)), this, SLOT(updateProjectsList(QList<Project*>*)));

    backend->loadProjects();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_projects_currentIndexChanged(int index)
{
    ui->startTracking->setEnabled( index > 0 );
}

void MainWindow::updateProjectsList(QList<Project *> *projects){
    for( int i = 0; i < projects->count(); ++i ){
        ui->projects->addItem(projects->at(i)->name, QVariant(projects->at(i)->id));
    }

    delete projects;
}
