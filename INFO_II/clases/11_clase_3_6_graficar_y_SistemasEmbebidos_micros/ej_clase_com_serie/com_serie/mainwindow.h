#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ActualizarButton_clicked();

    void on_conectarButton_clicked();

    void on_enviarButton_clicked();

    void on_datosRecibidos();

private:
    void enumerarPuertos();

    QSerialPort puerto; //lo abro, cierro, leo y escribo
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
