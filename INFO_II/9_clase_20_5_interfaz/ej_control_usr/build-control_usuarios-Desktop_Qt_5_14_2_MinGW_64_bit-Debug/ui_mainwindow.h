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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionIniciar_Sesion;
    QAction *actionCerrar_Sesion;
    QAction *actionAlmacenamiento;
    QAction *actionComunicacion;
    QAction *actionSalir;
    QAction *actionAgregar_Usuario;
    QAction *actionModificar_Usuario;
    QAction *actionEliminar_Usuario;
    QAction *actionGetCantidad;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuConfiguracion;
    QMenu *menuAcceso;
    QMenu *menuAdministracion;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionIniciar_Sesion = new QAction(MainWindow);
        actionIniciar_Sesion->setObjectName(QString::fromUtf8("actionIniciar_Sesion"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIniciar_Sesion->setIcon(icon);
        actionCerrar_Sesion = new QAction(MainWindow);
        actionCerrar_Sesion->setObjectName(QString::fromUtf8("actionCerrar_Sesion"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCerrar_Sesion->setIcon(icon1);
        actionAlmacenamiento = new QAction(MainWindow);
        actionAlmacenamiento->setObjectName(QString::fromUtf8("actionAlmacenamiento"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/almacenamiento.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAlmacenamiento->setIcon(icon2);
        actionComunicacion = new QAction(MainWindow);
        actionComunicacion->setObjectName(QString::fromUtf8("actionComunicacion"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/comunicacion.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionComunicacion->setIcon(icon3);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalir->setIcon(icon4);
        actionAgregar_Usuario = new QAction(MainWindow);
        actionAgregar_Usuario->setObjectName(QString::fromUtf8("actionAgregar_Usuario"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAgregar_Usuario->setIcon(icon5);
        actionModificar_Usuario = new QAction(MainWindow);
        actionModificar_Usuario->setObjectName(QString::fromUtf8("actionModificar_Usuario"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionModificar_Usuario->setIcon(icon6);
        actionEliminar_Usuario = new QAction(MainWindow);
        actionEliminar_Usuario->setObjectName(QString::fromUtf8("actionEliminar_Usuario"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEliminar_Usuario->setIcon(icon7);
        actionGetCantidad = new QAction(MainWindow);
        actionGetCantidad->setObjectName(QString::fromUtf8("actionGetCantidad"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuConfiguracion = new QMenu(menubar);
        menuConfiguracion->setObjectName(QString::fromUtf8("menuConfiguracion"));
        menuAcceso = new QMenu(menubar);
        menuAcceso->setObjectName(QString::fromUtf8("menuAcceso"));
        menuAdministracion = new QMenu(menubar);
        menuAdministracion->setObjectName(QString::fromUtf8("menuAdministracion"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAcceso->menuAction());
        menubar->addAction(menuAdministracion->menuAction());
        menubar->addAction(menuConfiguracion->menuAction());
        menuConfiguracion->addAction(actionAlmacenamiento);
        menuConfiguracion->addAction(actionComunicacion);
        menuConfiguracion->addAction(actionGetCantidad);
        menuAcceso->addAction(actionIniciar_Sesion);
        menuAcceso->addAction(actionCerrar_Sesion);
        menuAcceso->addSeparator();
        menuAcceso->addAction(actionSalir);
        menuAdministracion->addAction(actionAgregar_Usuario);
        menuAdministracion->addAction(actionModificar_Usuario);
        menuAdministracion->addAction(actionEliminar_Usuario);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionIniciar_Sesion->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesion", nullptr));
#if QT_CONFIG(shortcut)
        actionIniciar_Sesion->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCerrar_Sesion->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesion", nullptr));
        actionAlmacenamiento->setText(QCoreApplication::translate("MainWindow", "Almacenamiento", nullptr));
        actionComunicacion->setText(QCoreApplication::translate("MainWindow", "Comunicacion", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
#if QT_CONFIG(shortcut)
        actionSalir->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAgregar_Usuario->setText(QCoreApplication::translate("MainWindow", "Agregar Usuario", nullptr));
#if QT_CONFIG(shortcut)
        actionAgregar_Usuario->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionModificar_Usuario->setText(QCoreApplication::translate("MainWindow", "Modificar Usuario", nullptr));
#if QT_CONFIG(shortcut)
        actionModificar_Usuario->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEliminar_Usuario->setText(QCoreApplication::translate("MainWindow", "Eliminar Usuario", nullptr));
#if QT_CONFIG(shortcut)
        actionEliminar_Usuario->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGetCantidad->setText(QCoreApplication::translate("MainWindow", "GetCantidad", nullptr));
#if QT_CONFIG(shortcut)
        actionGetCantidad->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        menuConfiguracion->setTitle(QCoreApplication::translate("MainWindow", "Configuracion", nullptr));
        menuAcceso->setTitle(QCoreApplication::translate("MainWindow", "Acceso", nullptr));
        menuAdministracion->setTitle(QCoreApplication::translate("MainWindow", "Administracion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
