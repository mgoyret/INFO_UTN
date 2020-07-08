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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *conexionGroupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *puertoLabel;
    QComboBox *puertosComboBox;
    QPushButton *ActualizarButton;
    QPushButton *conectarButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *enviarBox;
    QTextEdit *enviarText;
    QPushButton *enviarButton;
    QGroupBox *rcvBox;
    QTextBrowser *rcvText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(840, 669);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        conexionGroupBox = new QGroupBox(centralwidget);
        conexionGroupBox->setObjectName(QString::fromUtf8("conexionGroupBox"));
        conexionGroupBox->setGeometry(QRect(10, 10, 271, 151));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(conexionGroupBox->sizePolicy().hasHeightForWidth());
        conexionGroupBox->setSizePolicy(sizePolicy1);
        verticalLayoutWidget = new QWidget(conexionGroupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 40, 251, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        puertoLabel = new QLabel(verticalLayoutWidget);
        puertoLabel->setObjectName(QString::fromUtf8("puertoLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(puertoLabel->sizePolicy().hasHeightForWidth());
        puertoLabel->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(puertoLabel);

        puertosComboBox = new QComboBox(verticalLayoutWidget);
        puertosComboBox->setObjectName(QString::fromUtf8("puertosComboBox"));

        horizontalLayout->addWidget(puertosComboBox);

        ActualizarButton = new QPushButton(verticalLayoutWidget);
        ActualizarButton->setObjectName(QString::fromUtf8("ActualizarButton"));
        sizePolicy1.setHeightForWidth(ActualizarButton->sizePolicy().hasHeightForWidth());
        ActualizarButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(ActualizarButton);


        verticalLayout->addLayout(horizontalLayout);

        conectarButton = new QPushButton(verticalLayoutWidget);
        conectarButton->setObjectName(QString::fromUtf8("conectarButton"));

        verticalLayout->addWidget(conectarButton);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(290, 10, 541, 601));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        enviarBox = new QGroupBox(verticalLayoutWidget_2);
        enviarBox->setObjectName(QString::fromUtf8("enviarBox"));
        enviarText = new QTextEdit(enviarBox);
        enviarText->setObjectName(QString::fromUtf8("enviarText"));
        enviarText->setGeometry(QRect(10, 30, 511, 221));
        enviarButton = new QPushButton(enviarBox);
        enviarButton->setObjectName(QString::fromUtf8("enviarButton"));
        enviarButton->setGeometry(QRect(10, 260, 91, 25));

        verticalLayout_2->addWidget(enviarBox);

        rcvBox = new QGroupBox(verticalLayoutWidget_2);
        rcvBox->setObjectName(QString::fromUtf8("rcvBox"));
        rcvText = new QTextBrowser(rcvBox);
        rcvText->setObjectName(QString::fromUtf8("rcvText"));
        rcvText->setGeometry(QRect(10, 30, 521, 251));

        verticalLayout_2->addWidget(rcvBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 840, 25));
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
        conexionGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Conexion", nullptr));
        puertoLabel->setText(QCoreApplication::translate("MainWindow", "puerto", nullptr));
        ActualizarButton->setText(QCoreApplication::translate("MainWindow", "actualizar", nullptr));
        conectarButton->setText(QCoreApplication::translate("MainWindow", "conectar", nullptr));
        enviarBox->setTitle(QCoreApplication::translate("MainWindow", "Texto a enviar:", nullptr));
        enviarButton->setText(QCoreApplication::translate("MainWindow", "Enviar", nullptr));
        rcvBox->setTitle(QCoreApplication::translate("MainWindow", "Texto recivido:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
