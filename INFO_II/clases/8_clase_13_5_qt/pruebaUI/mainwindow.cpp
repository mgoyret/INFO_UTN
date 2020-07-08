#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    contador = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbsaludo_clicked()
{
    //static int contador = 1;
    QString palabra;
    palabra = "Clicks: " + QString::number(contador); // const char*
    ui->pbsaludo->setText(palabra);
    contador++;

    QString aux = ui->pbsaludo->text();
    ui->lbresultado->setText(aux);
}
