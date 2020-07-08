#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ingreso.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DeshabilitarMenuSesion();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionIniciar_sesi_n_triggered()
{
    // genero ingreso de usuarios

    Ingreso MiIngreso;

    if(MiIngreso.exec() == QDialog::Accepted)
    {
        QString usr = MiIngreso.ObtenerUsuario();
        QString clave = MiIngreso.ObtenerClave();
        //validacion
        //Validarusuario y clave
        //Validar(usr,clave);

        //si validacion ok
        HabilitarMenuSesion();


        setWindowTitle("Bienvenido " + usr);

    }
    else
    {
        QMessageBox msgBox;
        //msgBox.addButton(tr("OK"), QMessageBox::DestructiveRole);
        //QPushButton *si = msgBox.addButton(tr("Si"), QMessageBox::AcceptRole);


        msgBox.setText("No se pudo iniciar sesion");
        msgBox.setWindowTitle(tr("Inicio"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}


void MainWindow::HabilitarMenuSesion(void)
{
    ui->menuConfiguraci_n->setEnabled(true);
    ui->menuUsuarios->setEnabled(true);

}

void MainWindow::DeshabilitarMenuSesion(void)
{
    ui->menuConfiguraci_n->setEnabled(false);
    ui->menuUsuarios->setEnabled(false);

    setWindowTitle("Usuario sin ingresar");
}

void MainWindow::on_actionCerrar_sesi_n_triggered()
{
    DeshabilitarMenuSesion();
}
