#ifndef INGRESO_H
#define INGRESO_H

#include <QDialog>

namespace Ui {
class ingreso;
}
/*
typedef struct CLIENTE
{
    QString nombre;
    QString apellido;
    QString email;
    QString usuario;
    QString clave;

}CLIENTE;
*/
class ingreso : public QDialog
{
    Q_OBJECT

public:
    explicit ingreso(QWidget *parent = nullptr);
    ingreso(QWidget*, QString);
    ~ingreso();

    QString getUser(){return usuario;}
    QString getClave(){return clave;}

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ingreso *ui;
    QString usuario;
    QString clave;
};

#endif // INGRESO_H
