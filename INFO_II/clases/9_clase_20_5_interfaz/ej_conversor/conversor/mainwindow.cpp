#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textoFarenheit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::realizar_conversion()
{
    float Cel, Far;
    bool conversion_exitosa;
    QString texto = ui->TextoEntrada->text();

    Cel = texto.toFloat(&conversion_exitosa);
    if(conversion_exitosa == true)
    {
        //number es una funcion de la clase QString. Es estatica por lo
        //tanto puedo usarla sin un objeto particular
        Far = (Cel * (9.0/5.0)) + 32.0;
        ui->textoFarenheit->setText(QString::number(Far));
    }
    else
    {
        QMessageBox msgBox;

        //limpio valor farenheit anterior
        ui->textoFarenheit->clear();

        msgBox.setWindowTitle("ADVERTENCIA!!");
        msgBox.setText("El valor Celsius ingresado es invalido");
        msgBox.exec();
        //ui->TextoEntrada->setText("ERROR");
    }
}

void MainWindow::on_botoConvertir_clicked()
{
    realizar_conversion();
    // podria ser this->realizar_conversion();
}

void MainWindow::on_TextoEntrada_returnPressed()
{
    realizar_conversion();
}
