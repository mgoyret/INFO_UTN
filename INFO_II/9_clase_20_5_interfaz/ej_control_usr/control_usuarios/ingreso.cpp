#include "ingreso.h"
#include "ui_ingreso.h"
#include <QMessageBox>

ingreso::ingreso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ingreso)
{
    ui->setupUi(this);
}

ingreso::~ingreso()
{
    delete ui;
}


void ingreso::on_okButton_clicked()
{
    QMessageBox box;

    usuario = ui->userLine->text();
    clave = ui->claveLine->text();
    if((usuario.size()>0) && (clave.size()>0))
        accept();
    else
    {
        box.setText("Complete todos los campos");
        box.exec();
    }
}

void ingreso::on_cancelButton_clicked()
{
    reject();
}
