#ifndef INGRESO_H
#define INGRESO_H

#include <QDialog>

namespace Ui {
class Ingreso;
}

class Ingreso : public QDialog
{
    Q_OBJECT

public:
    explicit Ingreso(QWidget *parent = nullptr);
    ~Ingreso();
    QString ObtenerUsuario();
    QString ObtenerClave();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Ingreso *ui;
    QString usuario;
    QString clave;
};

#endif // INGRESO_H
