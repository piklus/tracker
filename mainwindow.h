#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QVariant>
#include <QTimer>

#include "backend.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateProjectsList(QList<Project*>*);
    void on_projects_currentIndexChanged(int index);
    void synchronize();

private:
    Ui::MainWindow *ui;
    Backend *backend = new Backend();
    QTimer *timer = new QTimer(this);
};

#endif // MAINWINDOW_H
