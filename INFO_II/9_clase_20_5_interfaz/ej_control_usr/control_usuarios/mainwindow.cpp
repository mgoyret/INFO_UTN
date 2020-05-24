#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ingreso.h"
#include "qmessagebox.h"
#include "alta.h"
#include <QFile>
#include <QDebug>
#include <QString>

//#define ADD_LINE stream<<file[i].at(CAMPO::NOMBRE)<<","<<file[i].at(CAMPO::APELLIDO)<<","<<file[i].at(CAMPO::EMAIL)<<","<<file[i].at(CAMPO::USUARIO)<<","<<file[i].at(CAMPO::CLAVE)<<endl;
#define FILE_NAME "dataBase.csv"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(salir()));
    ui->actionCerrar_Sesion->setEnabled(false);
    ui->actionModificar_Usuario->setEnabled(false);
    ui->actionEliminar_Usuario->setEnabled(false);
    totalUsers = cntUsers();

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
    QMessageBox box;
    ingreso a;
    QString usuario, clave;
    QString line;
    QStringList list;
    QFile file(FILE_NAME);
    QTextStream stream(&file);

    if(a.exec() == QDialog::Accepted)
    {
        usuario = a.getUser();
        clave = a.getClave();

        if(file.exists())
        {
            if(file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                while(!stream.atEnd())
                {
                    list = stream.readLine().split(',');
                    if((list.at(3) == usuario) && (list.at(4) == clave))
                    {
                        box.setText("Bienvenido " + usuario);
                        box.exec();
                        setWindowTitle(usuario);
                        ui->actionCerrar_Sesion->setEnabled(true);
                        ui->actionModificar_Usuario->setEnabled(true);
                        ui->actionEliminar_Usuario->setEnabled(true);
                        usuarioIn = list;

                        break;
                    }
                }
                file.close();
            }
            else{/*problema al abrir archivo*/}
        }
    }
    else
    {
        box.setText("No se pudo iniciar sesion");
        box.exec();
    }
}

void MainWindow::on_actionAgregar_Usuario_triggered()
{
    alta a;
    QMessageBox box;

    if(a.exec() == QDialog::Accepted)
    {
        box.setText("Usuario agregado");
        box.exec();
        totalUsers++;
    }
    else
    {
        box.setText("No se pudo agregar usuario");
        box.exec();
    }
}

void MainWindow::on_actionCerrar_Sesion_triggered()
{
    closeUser();
}

void MainWindow::closeUser()
{
    setWindowTitle("MainWindow");
    ui->actionCerrar_Sesion->setEnabled(false);
    ui->actionModificar_Usuario->setEnabled(false);
    ui->actionEliminar_Usuario->setEnabled(false);
    usuarioIn.clear();
}

void MainWindow::on_actionEliminar_Usuario_triggered()
{
    int i=0, j=0;
    QString line, curUser = usuarioIn.join(',');
    QStringList list[totalUsers-1]; //se cargara una posicion menos a la cantidad actual de usuarios ya que se excluira a uno
    QMessageBox box;

    QFile file(FILE_NAME);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);

    for(i=0; i<totalUsers; i++)
    {

        line = stream.readLine();
        box.setText(line);
        box.exec();
        if( line != curUser )
        {
            list[j++] = line.split(',');
            box.setText("agregado");
            box.exec();
        }
        else
        {
            box.setText("Excluyendo de lista a: " + curUser);
            box.exec();
        }
    }
    box.setText("fin del for");
    box.exec();
    if(newFile(list, totalUsers-1))
    {
        box.setText("Usuario eliminado");
        box.exec();
        totalUsers--;
        closeUser();
    }
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
        {
            stream << list[i].at(CAMPO::NOMBRE) << ",";
            stream << list[i].at(CAMPO::APELLIDO) << ",";
            stream << list[i].at(CAMPO::EMAIL)<<",";
            stream << list[i].at(CAMPO::USUARIO)<<",";
            stream << list[i].at(CAMPO::CLAVE)<<"\n";
        }
        if(i==len)
        {
            exit = 1;
        }

        file.close();
    }
    // else -> problema al crear el archivo

    return exit;
}

void MainWindow::on_actionModificar_Usuario_triggered()
{
    int i, j=0;
    QStringList list[totalUsers];
    QMessageBox box;
    QString line, curUser = usuarioIn.join(',');
    alta a(this, usuarioIn.at(CAMPO::NOMBRE), usuarioIn.at(CAMPO::APELLIDO),
                        usuarioIn.at(CAMPO::EMAIL), usuarioIn.at(CAMPO::USUARIO), usuarioIn.at(CAMPO::CLAVE));

    QFile file(FILE_NAME);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);

    for(i=0; i<totalUsers; i++)
    {

        line = stream.readLine();
        list[i] = line.split(',');
        if( line == curUser )
        {
            box.setText("COINCIDENCIA |"+line+"|"+curUser+"|");
            box.exec();

            j=i;
        }
    }
    box.setText("SOS "+list[j].at(CAMPO::USUARIO));
    box.exec();
    if(a.exec()) // == accepted
    {
        list[j][CAMPO::NOMBRE] = a.getNombre();
        list[j][CAMPO::APELLIDO] = a.getApellido();
        list[j][CAMPO::EMAIL] = a.getEmail();
        list[j][CAMPO::USUARIO] = a.getUsuario();
        list[j][CAMPO::CLAVE] = a.getClave();

        box.setText("ahora sos "+list[j].at(CAMPO::USUARIO));
        box.exec();
        if(newFile(list, totalUsers))
        {
            box.setText("Usuario modificado");
            box.exec();
        }
        else
        {
            box.setText("No se pudo modificar usuario [on_actionModificar_Usuario_triggered() |2|]");
            box.exec();
        }
    }
    else
    {
        box.setText("No se pudo modificar usuario [on_actionModificar_Usuario_triggered() |1|]");
        box.exec();
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

    box.setText("Cantidad de usuarios: " + QString::number(exit));

    box.exec();

    return exit;
}

void MainWindow::on_actionGetCantidad_triggered()
{
    cntUsers();
}
