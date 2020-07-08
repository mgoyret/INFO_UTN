#ifndef ALTA_H
#define ALTA_H

#include <QDialog>

namespace Ui {
class alta;
}

class alta : public QDialog
{
    Q_OBJECT

public:
    explicit alta(QWidget *parent = nullptr);
    alta(QWidget*, QString, QString, QString, QString, QString);
    ~alta();

    QString getNombre(){return nombre;}
    QString getApellido(){return apellido;}
    QString getEmail(){return email;}
    QString getUsuario(){return usuario;}
    QString getClave(){return clave;}

    int existe(QString);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::alta *ui;
    QString nombre;
    QString apellido;
    QString email;
    QString usuario, auxUsuario;
    QString clave;
    int mod;
};

#endif // ALTA_H
