#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionIniciar_sesi_n_triggered();

    void on_actionCerrar_sesi_n_triggered();

private:
    Ui::MainWindow *ui;
    void HabilitarMenuSesion(void);
    void DeshabilitarMenuSesion(void);
};
#endif // MAINWINDOW_H
