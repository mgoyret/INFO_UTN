#ifndef COMCLASS_H
#define COMCLASS_H

#include <QDialog>
#include <QSerialPort>
//#include <QStatusBar>

namespace Ui {
class ComClass;
}

class ComClass : public QDialog
{
    Q_OBJECT

public:
    explicit ComClass(QWidget *parent = nullptr);
    ~ComClass();

    void enableAll();
    void dissableAll();

private slots:
    void on_ActualizarButton_clicked();

    void on_conectarButton_clicked();

    void on_enviarButton_clicked();

    void on_datosRecibidos();


private:
    void enumerarPuertos();

    QSerialPort puerto; //lo abro, cierro, leo y escribo
    //QStatusBar *statusBar;
    Ui::ComClass *ui;
};

#endif // COMCLASS_H
