#include "alta.h"
#include "ui_alta.h"
#include "qmessagebox.h"
#include "mainwindow.h"
#include <iostream>
#include <QFile>
#include <QDebug>
#include <QString>

using namespace std;

#define ADD_LINE stream<<nombre<<","<<apellido<<","<<email<<","<<usuario<<","<<clave<<"\n";
#define FILE_NAME "dataBase.csv"
#define ADD     1
#define EDIT    2

alta::alta(QWidget *parent):
    QDialog(parent),
    ui(new Ui::alta)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("../../img/add.png"));
    mod = ADD;
}

//constructor sobrecargado para mostrar la ventana con textos por defecto en los lineEdit
alta::alta(QWidget *parent, QString nom, QString ape, QString ema, QString usu, QString clv): QDialog(parent), ui(new Ui::alta)
{
    ui->setupUi(this);
    ui->nombreLine->setText(nom);
    ui->apellidoLine->setText(ape);
    ui->emailLine->setText(ema);
    ui->usuarioLine->setText(usu);
    ui->claveLine->setText(clv);
    auxUsuario = usu;
    mod = EDIT;
}

alta::~alta()
{
    delete ui;
}

void alta::on_cancelButton_clicked()
{
    reject();
}

void alta::on_okButton_clicked()
{
    QMessageBox box;

    nombre = ui->nombreLine->text();
    apellido = ui->apellidoLine->text();
    email = ui->emailLine->text();
    usuario = ui->usuarioLine->text();
    clave = ui->claveLine->text();

    if((nombre.size() > 0) && (apellido.size() > 0) && (email.size() > 0) && (usuario.size() > 0) && (clave.size() > 0))
    {
        //si estoy editando usuario, el nombre de usuario existira, y capaz no lo quiera cambiar
        //si lo cambia, verifico luego que el nuevo nombre de usuario no este usado
        if( ((mod == ADD) && existe(usuario)) || ((mod==EDIT) && existe(usuario) && (usuario != auxUsuario)) )
        {
            QMessageBox::critical(this, "ATENCION", "Nombre de usuario existente");
        }else
        {
            //if((mod == EDIT) && )
            QFile file(FILE_NAME);
            //if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text))
            if(file.open(QIODevice::Append | QIODevice::Text))
            {
                QTextStream stream(&file);
                ADD_LINE

                file.close();
                accept();
            }//else problema al crear archivo
        }
    }else
    {
        QMessageBox::critical(this, "ATENCION", "Complete todos los campos");
    }
}

int alta::existe(QString auxUser)
{
    int exit = 0;
    QString line;
    QStringList list;
    QFile file(FILE_NAME);
    QTextStream stream(&file);
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while(!stream.atEnd())
            {
                list = stream.readLine().split(',');
                if(list.at(3) == auxUser)
                {
                    exit = 1;
                    break;
                }
            }
            file.close();
        }//else problema al abrir archivo
    }
    return exit;
}
