/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *TextoEntrada;
    QLabel *etiquetaCelcius;
    QLineEdit *textoFarenheit;
    QLabel *etiquetaFarenheit;
    QPushButton *botoConvertir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(499, 240);
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TextoEntrada = new QLineEdit(centralwidget);
        TextoEntrada->setObjectName(QString::fromUtf8("TextoEntrada"));
        TextoEntrada->setGeometry(QRect(200, 40, 241, 25));
        etiquetaCelcius = new QLabel(centralwidget);
        etiquetaCelcius->setObjectName(QString::fromUtf8("etiquetaCelcius"));
        etiquetaCelcius->setGeometry(QRect(30, 40, 141, 17));
        textoFarenheit = new QLineEdit(centralwidget);
        textoFarenheit->setObjectName(QString::fromUtf8("textoFarenheit"));
        textoFarenheit->setEnabled(true);
        textoFarenheit->setGeometry(QRect(200, 90, 241, 25));
        textoFarenheit->setReadOnly(false);
        etiquetaFarenheit = new QLabel(centralwidget);
        etiquetaFarenheit->setObjectName(QString::fromUtf8("etiquetaFarenheit"));
        etiquetaFarenheit->setGeometry(QRect(30, 90, 161, 17));
        botoConvertir = new QPushButton(centralwidget);
        botoConvertir->setObjectName(QString::fromUtf8("botoConvertir"));
        botoConvertir->setGeometry(QRect(200, 140, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 499, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TextoEntrada->setText(QString());
        etiquetaCelcius->setText(QCoreApplication::translate("MainWindow", "Temperatura Celsius", nullptr));
        textoFarenheit->setText(QString());
        etiquetaFarenheit->setText(QCoreApplication::translate("MainWindow", "Temperatura Farenheit", nullptr));
        botoConvertir->setText(QCoreApplication::translate("MainWindow", "convertir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
