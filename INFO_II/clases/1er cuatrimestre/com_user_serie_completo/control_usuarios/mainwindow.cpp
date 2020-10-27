#include "mainwindow.h"
#include "alta.h"
#include "ingreso.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QString>
#include "comclass.h"

#define ADD_LINE stream << list[i].at(CAMPO::NOMBRE) << "," << list[i].at(CAMPO::APELLIDO) << "," << list[i].at(CAMPO::EMAIL)<<","<< list[i].at(CAMPO::USUARIO)<<"," << list[i].at(CAMPO::CLAVE)<<"\n";
#define FILE_NAME "dataBase.csv"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("INFO II - UTN");
    setWindowIcon(QIcon("../../img/utn.png"));

    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(salir()));
    enableOut();
    totalUsers = cntUsers();
    //////////////////////////////////////////////////////////////////////
    ui->actionComunicacion->setEnabled(true); // lo tengo asi para usarlo sin tener que iniciar
    ComClass a;
    a.exec();
    /////////////////////////////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*  lo hice en el constructor para mostrar la similitud haciendolo manual
void MainWindow::on_actionSalir_triggered()
{
    close();
}
*/

void MainWindow::salir()
{
    close();
}

int MainWindow::ingresoDatos()
{
    ingreso a;
    QString usuario, clave;
    int exit = 0;

    if(a.exec() == QDialog::Accepted)
    {
        usuario = a.getUser();
        clave = a.getClave();
        exit = 1;
    }
    return exit;
}

void MainWindow::on_actionIniciar_Sesion_triggered()
{
    int i = 1;
    ingreso a;
    QString usuario, clave;
    QStringList current;
    QFile file(FILE_NAME);
    QTextStream stream(&file);

    a.setWindowTitle("Inicio de sesion");
    while(i)
    {
        if(a.exec() == QDialog::Accepted)
        {
            usuario = a.getUser();
            clave = a.getClave();

            if(userCheck(usuario, clave, current))
            {
                QMessageBox::information(this ,"", "Bienvenido "+usuario);
                setWindowTitle(usuario);
                enableIn();
                usuarioIn = current;
                i=0;

            }
            if(i)
            {
                QMessageBox::critical(this, "ERROR", "Usuario y/o clave incorrectos");
            }
            file.close();
        }else
            i=0;
    }
}

void MainWindow::on_actionAgregar_Usuario_triggered()
{
    alta a;

    if(a.exec() == QDialog::Accepted)
    {
        QMessageBox::information(this, "", "Usuario agregado");
        totalUsers++;
    }
    else
    {
        QMessageBox::warning(this, "","Usuario no agregado");
    }
}

void MainWindow::on_actionCerrar_Sesion_triggered()
{
    closeUser();
}

void MainWindow::closeUser()
{
    setWindowTitle("MainWindow");
    enableOut();
    usuarioIn.clear();
    setWindowTitle("INFO II - UTN");
}

void MainWindow::on_actionEliminar_Usuario_triggered()
{
    int i=0, j=0;
    QString line, curUser = usuarioIn.join(',');
    QStringList list[totalUsers-1]; //se cargara una posicion menos a la cantidad actual de usuarios ya que se excluira a uno

    QFile file(FILE_NAME);
    //pido clave
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        for(i=0; i<totalUsers; i++)
        {
            line = stream.readLine();
            if( line != curUser )
                list[j++] = line.split(',');
        }
        if(newFile(list, totalUsers-1))
        {
            QMessageBox::information(this, "", "Usuario eliminado");
            totalUsers--;
            closeUser();
        }
        file.close();
    }//else problema al abrir archivo

}
/**
  newFile recibe un array de qstringlist llamado "list", y reescribe el archivo "FILE_NAME" con la informacion contenida en list
*/
int MainWindow::newFile(QStringList *list, int len)
{
    int i, exit = 0;
    QFile::remove(FILE_NAME); //borro archivo viejo
    QFile file(FILE_NAME);  //lo creo nuevamente
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        for(i=0; i<len; i++)
            ADD_LINE

        if(i==len)
            exit = 1;

        file.close();
    }// else problema al crear el archivo
    return exit;
}

void MainWindow::on_actionModificar_Usuario_triggered()
{
    int i=1, j=0, k=1;
    QStringList list[totalUsers];
    QMessageBox box;
    QString line, curUser = usuarioIn.join(',');
    alta a(this, usuarioIn.at(CAMPO::NOMBRE), usuarioIn.at(CAMPO::APELLIDO),
                        usuarioIn.at(CAMPO::EMAIL), usuarioIn.at(CAMPO::USUARIO), usuarioIn.at(CAMPO::CLAVE));
    ingreso b(this, usuarioIn.at(CAMPO::USUARIO));
    QStringList dump; //para poder usar userCheck

    while(k)
    {
        if(b.exec())
        {
            if(userCheck(b.getUser(), b.getClave(), dump))
            {
                k=0;
                QFile file(FILE_NAME);
                if(file.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    QTextStream stream(&file);

                    for(i=0; i<totalUsers; i++)
                    {
                        line = stream.readLine();
                        list[i] = line.split(',');
                        if( line == curUser )
                            j=i;
                    }
                    file.close();
                }

                if(a.exec()) // == accepted
                {
                    list[j][CAMPO::NOMBRE] = a.getNombre();
                    list[j][CAMPO::APELLIDO] = a.getApellido();
                    list[j][CAMPO::EMAIL] = a.getEmail();
                    list[j][CAMPO::USUARIO] = a.getUsuario();
                    list[j][CAMPO::CLAVE] = a.getClave();

                    if(newFile(list, totalUsers))
                    {
                        box.setText("Usuario modificado");
                        box.exec();
                    }else
                    {
                        QMessageBox::critical(this, "ERROR", "No se pudo modificar usuario [on_actionModificar_Usuario_triggered() |2|]");
                    }
                }else
                {
                    QMessageBox::critical(this, "ERROR", "No se pudo modificar usuario [on_actionModificar_Usuario_triggered() |1|]");

                }
            }
            else
            {
                QMessageBox::critical(this, "ERROR", "usuario/clave incorrectos");
            }
        }else{k=0;}
    }
}

int MainWindow::cntUsers()
{
    int exit = 0;
    QFile file(FILE_NAME);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    QMessageBox box;

    while (!stream.atEnd())
    {
        stream.readLine();
        exit++;
    }
    return exit;
}

void MainWindow::on_actionGetCantidad_triggered()
{
    QMessageBox box;
    box.setText("Cantidad de usuarios: " + QString::number(cntUsers()));
    box.exec();
}

int MainWindow::userCheck(QString usuario, QString clave, QStringList &current)
{
    int exit = 0;
    QFile file(FILE_NAME);
    QTextStream stream(&file);

    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while(!stream.atEnd())
            {
                current = stream.readLine().split(',');
                if((current.at(3) == usuario) && (current.at(4) == clave))
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

void MainWindow::on_actionComunicacion_triggered()
{
    ComClass a;
    a.exec();
}

void MainWindow::enableIn()
{
    ui->actionCerrar_Sesion->setEnabled(true);
    ui->actionModificar_Usuario->setEnabled(true);
    ui->actionEliminar_Usuario->setEnabled(true);
    ui->actionComunicacion->setEnabled(true);
    ui->actionIniciar_Sesion->setEnabled(false);
}

void MainWindow::enableOut()
{
    ui->actionCerrar_Sesion->setEnabled(false);
    ui->actionModificar_Usuario->setEnabled(false);
    ui->actionEliminar_Usuario->setEnabled(false);
    //ui->actionComunicacion->setEnabled(false); // lo tengo asi para usarlo sin tener que iniciar
    ui->actionIniciar_Sesion->setEnabled(true);
}
