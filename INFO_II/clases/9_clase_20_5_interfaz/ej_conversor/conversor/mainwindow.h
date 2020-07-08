#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    void on_botoConvertir_clicked();

    void on_TextoEntrada_returnPressed();

private:
    Ui::MainWindow *ui;
    void realizar_conversion();
};
#endif // MAINWINDOW_H
