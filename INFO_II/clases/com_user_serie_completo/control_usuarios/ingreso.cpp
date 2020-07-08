#include "ingreso.h"
#include "ui_ingreso.h"
#include <QMessageBox>

ingreso::ingreso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ingreso)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("../../img/login.png"));
}

ingreso::ingreso(QWidget *parent, QString user) :
    QDialog(parent),
    ui(new Ui::ingreso)
{
    ui->setupUi(this);
    ui->userLine->setText(user);
    setWindowIcon(QIcon("../../img/login.png"));
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
        QMessageBox::critical(this, "ATENCION", "Complete todos los campos");
    }
}

void ingreso::on_cancelButton_clicked()
{
    reject();
}

