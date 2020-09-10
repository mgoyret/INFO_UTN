#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum CAMPO{
    NOMBRE = 0,
    APELLIDO,
    EMAIL,
    USUARIO,
    CLAVE
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int ingresoDatos();
    int newFile(QStringList*, int);
    int cntUsers();
    void closeUser();
    int userCheck(QString, QString, QStringList&);
    void enableIn();
    void enableOut();

private slots:
    //void on_actionSalir_triggered();
    //la hago manualmente
    void salir();

    void on_actionIniciar_Sesion_triggered();

    void on_actionEliminar_Usuario_triggered();

    void on_actionModificar_Usuario_triggered();

    void on_actionAgregar_Usuario_triggered();

    void on_actionCerrar_Sesion_triggered();

    void on_actionGetCantidad_triggered();

    void on_actionComunicacion_triggered();

private:
    Ui::MainWindow *ui;
    int totalUsers;
    QStringList usuarioIn;
};
#endif // MAINWINDOW_H
