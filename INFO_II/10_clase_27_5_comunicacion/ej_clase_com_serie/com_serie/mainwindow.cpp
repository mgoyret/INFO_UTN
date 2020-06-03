#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    enumerarPuertos();
    ui->enviarButton->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enumerarPuertos()
{
    int i;
    QList<QSerialPortInfo> puertos;

    puertos = QSerialPortInfo::availablePorts();
    ui->puertosComboBox->clear();
    for(i=0; i<puertos.count(); i++)
    {
        ui->puertosComboBox->addItem(puertos.at(i).portName());
    }
}

void MainWindow::on_ActualizarButton_clicked()
{
    enumerarPuertos();
}

void MainWindow::on_conectarButton_clicked()
{
    if(!puerto.isOpen())
    {
        QString portName = ui->puertosComboBox->currentText();
        puerto.setPortName(portName);
        // COPIADO DE OTRO CODIGO, LO VEREMOS DESPUES
        //////////////////////////////////////////////////
        puerto.setBaudRate(QSerialPort::Baud9600);
        puerto.setDataBits(QSerialPort::Data8);
        puerto.setParity(QSerialPort::NoParity);
        puerto.setStopBits(QSerialPort::OneStop);
        puerto.setFlowControl(QSerialPort::NoFlowControl);
        //////////////////////////////////////////////////

        if(puerto.open(QIODevice::ReadWrite) == true)
        {
            ui->conectarButton->setText("Desconectar");
            ui->statusbar->showMessage(portName+" conectado", 4000);
            //quedo conectado
            ui->enviarButton->setEnabled(true);

            connect(&puerto, SIGNAL(readyRead()), this, SLOT(on_datosRecibidos()));
        }else
        {
            QMessageBox::critical(this, "ERROR",
                                  "No pudo abrirse el puerto: "+portName);
        }
    } else
    {
        puerto.close();
        ui->rcvText->clear();
        ui->conectarButton->setText("Conectar");
        ui->statusbar->showMessage(puerto.portName()+" desconectado", 4000);
        //quedo desconectado
        ui->enviarButton->setDisabled(true);
    }
}

void MainWindow::on_enviarButton_clicked()
{
    QByteArray datos; //array de bytes, pueden ser caracteres char o caract.
                      // no imprimibles, lo q sea, arrays de informacion.
                      //creo q termina el array con '\0'

    datos.append(ui->enviarText->toPlainText()); //cambiar esto por datos escritos en la ui
    puerto.write(datos.data(), datos.size());
}


void MainWindow::on_datosRecibidos()
{
    QByteArray datos;
    int cant = (int)puerto.bytesAvailable();

    datos.resize(cant);
    puerto.read(datos.data(), cant);

    //ahora trabajo sobre datos recibidos
    ui->rcvText->append(QString(datos));
}
