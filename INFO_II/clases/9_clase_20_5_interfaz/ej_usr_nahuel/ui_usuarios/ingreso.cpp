#include "ingreso.h"
#include "ui_ingreso.h"

Ingreso::Ingreso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingreso)
{
    ui->setupUi(this);
}

Ingreso::~Ingreso()
{
    delete ui;
}

void Ingreso::on_buttonBox_accepted()
{
    usuario = ui->editUsuario->text();
    clave = ui->editClave->text();

    accept();
}


QString Ingreso::ObtenerUsuario()
{
    return usuario;

}

QString Ingreso::ObtenerClave()
{
    return clave;

}
