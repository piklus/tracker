#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(backend, SIGNAL(projectsLoaded(QList<Project*>*)), this, SLOT(updateProjectsList(QList<Project*>*)));
    connect(timer, SIGNAL(timeout()), this, SLOT(synchronize()));

    timer->setInterval(5000);
    timer->start();
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
    ui->projects->clear();
    ui->projects->addItem(tr("Select project..."));

    for( int i = 0; i < projects->count(); ++i ){
        ui->projects->addItem(projects->at(i)->name, QVariant(projects->at(i)->id));
    }

    delete projects;
}

void MainWindow::synchronize(){
    backend->loadProjects();
}
