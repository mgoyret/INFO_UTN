#include "comclass.h"
#include "ui_comclass.h"
#include <QSerialPort>
#include <QSerialPortInfo>
//#include <QStatusBar>
#include <QMessageBox>

ComClass::ComClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComClass)
{
    ui->setupUi(this);
    enumerarPuertos();
    setWindowIcon(QIcon("../../img/comunicacion.png"));

    //agrego la status bar, ya que es un widget y no la tiene por defecto
    //statusBar = new QStatusBar(this);
    //ui->statusLayout->addWidget(statusBar);
    dissableAll();
}

ComClass::~ComClass()
{
    delete ui;
}

void ComClass::enumerarPuertos()
{
    int i;
    QList<QSerialPortInfo> puertos;

    ui->puertosComboBox->clear();
    puertos = QSerialPortInfo::availablePorts();
    for(i=0; i<puertos.count(); i++)
    {
        ui->puertosComboBox->addItem(puertos.at(i).portName());
    }
}

void ComClass::on_ActualizarButton_clicked()
{
    enumerarPuertos();
}

void ComClass::on_conectarButton_clicked()
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
            //ui->statusBar->showMessage(portName+" conectado", 4000);
            //statusBar->setStatusTip(portName+" conectado");
            //quedo conectado
            enableAll();

            connect(&puerto, SIGNAL(readyRead()), this, SLOT(on_datosRecibidos()));
        }else
        {
            QMessageBox::critical(this, "ERROR", "No pudo abrirse el puerto: "+portName);
        }
    } else
    {
        puerto.close();
        ui->rcvText->clear();
        ui->conectarButton->setText("Conectar");
        //ui->statusbar->showMessage(puerto.portName()+" desconectado", 4000);
        //statusBar->setStatusTip(puerto.portName()+" desconectado");

        //quedo desconectado
        //ui->enviarButton->setDisabled(true);
        dissableAll();
    }
}

void ComClass::on_enviarButton_clicked()
{
    QByteArray datos; //array de bytes, pueden ser caracteres char o caract.
                      // no imprimibles, lo q sea, arrays de informacion.
                      //creo q termina el array con '\0'

    datos.append(ui->enviarText->toPlainText()); //cambiar esto por datos escritos en la ui
    puerto.write(datos.data(), datos.size());
    ui->enviarText->clear();
}


void ComClass::on_datosRecibidos()
{
    QByteArray datos;
    int cant = (int)puerto.bytesAvailable();

    datos.resize(cant);
    puerto.read(datos.data(), cant);

    //ahora trabajo sobre datos recibidos
    ui->rcvText->append(QString(datos));
}

void ComClass::enableAll()
{
    ui->enviarBox->setEnabled(true);
    ui->rcvBox->setEnabled(true);
}

void ComClass::dissableAll()
{
    ui->enviarBox->setEnabled(false);
    ui->rcvBox->setEnabled(false);
}
