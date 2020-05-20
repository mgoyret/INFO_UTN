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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMenu_1;
    QAction *actionUn_submenu;
    QWidget *centralWidget;
    QLineEdit *txtaEnviar;
    QLabel *lblLeyenda1;
    QPushButton *btnEnviar;
    QPushButton *btnCargarImagen;
    QPushButton *btnMiImagen;
    QProgressBar *pbMiBarra;
    QCheckBox *chkModo;
    QPushButton *btnCambiarModo;
    QDateEdit *dtFecha;
    QLineEdit *lblFecha;
    QDial *dial;
    QPushButton *pushButton;
    QPushButton *btnVerValor;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuHola;
    QMenu *menuOtroMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(487, 483);
        actionMenu_1 = new QAction(MainWindow);
        actionMenu_1->setObjectName(QString::fromUtf8("actionMenu_1"));
        actionUn_submenu = new QAction(MainWindow);
        actionUn_submenu->setObjectName(QString::fromUtf8("actionUn_submenu"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/misRecursos/logo"), QSize(), QIcon::Normal, QIcon::Off);
        actionUn_submenu->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        txtaEnviar = new QLineEdit(centralWidget);
        txtaEnviar->setObjectName(QString::fromUtf8("txtaEnviar"));
        txtaEnviar->setGeometry(QRect(220, 30, 113, 20));
        txtaEnviar->setEchoMode(QLineEdit::NoEcho);
        lblLeyenda1 = new QLabel(centralWidget);
        lblLeyenda1->setObjectName(QString::fromUtf8("lblLeyenda1"));
        lblLeyenda1->setGeometry(QRect(10, 30, 201, 16));
        btnEnviar = new QPushButton(centralWidget);
        btnEnviar->setObjectName(QString::fromUtf8("btnEnviar"));
        btnEnviar->setGeometry(QRect(350, 30, 75, 23));
        btnCargarImagen = new QPushButton(centralWidget);
        btnCargarImagen->setObjectName(QString::fromUtf8("btnCargarImagen"));
        btnCargarImagen->setGeometry(QRect(90, 100, 111, 23));
        btnMiImagen = new QPushButton(centralWidget);
        btnMiImagen->setObjectName(QString::fromUtf8("btnMiImagen"));
        btnMiImagen->setGeometry(QRect(10, 100, 71, 51));
        pbMiBarra = new QProgressBar(centralWidget);
        pbMiBarra->setObjectName(QString::fromUtf8("pbMiBarra"));
        pbMiBarra->setGeometry(QRect(210, 190, 200, 30));
        pbMiBarra->setValue(24);
        chkModo = new QCheckBox(centralWidget);
        chkModo->setObjectName(QString::fromUtf8("chkModo"));
        chkModo->setGeometry(QRect(20, 190, 91, 17));
        btnCambiarModo = new QPushButton(centralWidget);
        btnCambiarModo->setObjectName(QString::fromUtf8("btnCambiarModo"));
        btnCambiarModo->setGeometry(QRect(120, 190, 75, 23));
        dtFecha = new QDateEdit(centralWidget);
        dtFecha->setObjectName(QString::fromUtf8("dtFecha"));
        dtFecha->setGeometry(QRect(20, 310, 110, 22));
        lblFecha = new QLineEdit(centralWidget);
        lblFecha->setObjectName(QString::fromUtf8("lblFecha"));
        lblFecha->setGeometry(QRect(20, 350, 113, 20));
        dial = new QDial(centralWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(360, 310, 50, 64));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 310, 75, 23));
        btnVerValor = new QPushButton(centralWidget);
        btnVerValor->setObjectName(QString::fromUtf8("btnVerValor"));
        btnVerValor->setGeometry(QRect(350, 370, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 487, 22));
        menuHola = new QMenu(menuBar);
        menuHola->setObjectName(QString::fromUtf8("menuHola"));
        menuOtroMenu = new QMenu(menuHola);
        menuOtroMenu->setObjectName(QString::fromUtf8("menuOtroMenu"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionUn_submenu);
        mainToolBar->addSeparator();
        menuBar->addAction(menuHola->menuAction());
        menuHola->addAction(actionMenu_1);
        menuHola->addAction(menuOtroMenu->menuAction());
        menuOtroMenu->addAction(actionUn_submenu);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionMenu_1->setText(QCoreApplication::translate("MainWindow", "Menu 1", nullptr));
        actionUn_submenu->setText(QCoreApplication::translate("MainWindow", "un submenu", nullptr));
        lblLeyenda1->setText(QCoreApplication::translate("MainWindow", "Enviar texto a nueva ventana:", nullptr));
        btnEnviar->setText(QCoreApplication::translate("MainWindow", "Enviar", nullptr));
        btnCargarImagen->setText(QCoreApplication::translate("MainWindow", "Cargar imagen", nullptr));
        btnMiImagen->setText(QString());
        chkModo->setText(QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        btnCambiarModo->setText(QCoreApplication::translate("MainWindow", "Cambiar", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Obtener", nullptr));
        btnVerValor->setText(QCoreApplication::translate("MainWindow", "Ver valor", nullptr));
        menuHola->setTitle(QCoreApplication::translate("MainWindow", "hola", nullptr));
        menuOtroMenu->setTitle(QCoreApplication::translate("MainWindow", "otroMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
