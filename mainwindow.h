#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QVariant>

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
    void on_comboBox_currentIndexChanged(int index);
    void updateProjectsList(QList<Project*>*);

private:
    Ui::MainWindow *ui;
    Backend *backend = new Backend();
};

#endif // MAINWINDOW_H
