#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(salir()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
void MainWindow::on_actionSalir_triggered()
{
    close();
}
*/

void MainWindow::salir()
{
    close();
}
