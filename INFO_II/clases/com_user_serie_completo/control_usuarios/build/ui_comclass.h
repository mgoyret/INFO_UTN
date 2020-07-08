/********************************************************************************
** Form generated from reading UI file 'comclass.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMCLASS_H
#define UI_COMCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComClass
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *allBoxLayout;
    QGroupBox *enviarBox;
    QTextEdit *enviarText;
    QPushButton *enviarButton;
    QGroupBox *rcvBox;
    QTextBrowser *rcvText;
    QGroupBox *conexionGroupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *puertoLabel;
    QComboBox *puertosComboBox;
    QPushButton *ActualizarButton;
    QPushButton *conectarButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *statusLayout;

    void setupUi(QDialog *ComClass)
    {
        if (ComClass->objectName().isEmpty())
            ComClass->setObjectName(QString::fromUtf8("ComClass"));
        ComClass->resize(963, 619);
        verticalLayoutWidget_2 = new QWidget(ComClass);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(290, 10, 541, 601));
        allBoxLayout = new QVBoxLayout(verticalLayoutWidget_2);
        allBoxLayout->setObjectName(QString::fromUtf8("allBoxLayout"));
        allBoxLayout->setContentsMargins(0, 0, 0, 0);
        enviarBox = new QGroupBox(verticalLayoutWidget_2);
        enviarBox->setObjectName(QString::fromUtf8("enviarBox"));
        enviarBox->setEnabled(true);
        enviarText = new QTextEdit(enviarBox);
        enviarText->setObjectName(QString::fromUtf8("enviarText"));
        enviarText->setGeometry(QRect(10, 30, 511, 221));
        enviarButton = new QPushButton(enviarBox);
        enviarButton->setObjectName(QString::fromUtf8("enviarButton"));
        enviarButton->setEnabled(true);
        enviarButton->setGeometry(QRect(10, 260, 91, 25));

        allBoxLayout->addWidget(enviarBox);

        rcvBox = new QGroupBox(verticalLayoutWidget_2);
        rcvBox->setObjectName(QString::fromUtf8("rcvBox"));
        rcvBox->setEnabled(true);
        rcvText = new QTextBrowser(rcvBox);
        rcvText->setObjectName(QString::fromUtf8("rcvText"));
        rcvText->setGeometry(QRect(10, 30, 521, 251));

        allBoxLayout->addWidget(rcvBox);

        conexionGroupBox = new QGroupBox(ComClass);
        conexionGroupBox->setObjectName(QString::fromUtf8("conexionGroupBox"));
        conexionGroupBox->setGeometry(QRect(10, 10, 271, 151));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(conexionGroupBox->sizePolicy().hasHeightForWidth());
        conexionGroupBox->setSizePolicy(sizePolicy);
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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(puertoLabel->sizePolicy().hasHeightForWidth());
        puertoLabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(puertoLabel);

        puertosComboBox = new QComboBox(verticalLayoutWidget);
        puertosComboBox->setObjectName(QString::fromUtf8("puertosComboBox"));

        horizontalLayout->addWidget(puertosComboBox);

        ActualizarButton = new QPushButton(verticalLayoutWidget);
        ActualizarButton->setObjectName(QString::fromUtf8("ActualizarButton"));
        sizePolicy.setHeightForWidth(ActualizarButton->sizePolicy().hasHeightForWidth());
        ActualizarButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ActualizarButton);


        verticalLayout->addLayout(horizontalLayout);

        conectarButton = new QPushButton(verticalLayoutWidget);
        conectarButton->setObjectName(QString::fromUtf8("conectarButton"));

        verticalLayout->addWidget(conectarButton);

        horizontalLayoutWidget = new QWidget(ComClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 589, 251, 31));
        statusLayout = new QHBoxLayout(horizontalLayoutWidget);
        statusLayout->setObjectName(QString::fromUtf8("statusLayout"));
        statusLayout->setContentsMargins(0, 0, 0, 0);
        QWidget::setTabOrder(puertosComboBox, ActualizarButton);
        QWidget::setTabOrder(ActualizarButton, conectarButton);
        QWidget::setTabOrder(conectarButton, enviarText);
        QWidget::setTabOrder(enviarText, enviarButton);
        QWidget::setTabOrder(enviarButton, rcvText);

        retranslateUi(ComClass);

        QMetaObject::connectSlotsByName(ComClass);
    } // setupUi

    void retranslateUi(QDialog *ComClass)
    {
        ComClass->setWindowTitle(QCoreApplication::translate("ComClass", "Dialog", nullptr));
        enviarBox->setTitle(QCoreApplication::translate("ComClass", "Texto a enviar:", nullptr));
        enviarButton->setText(QCoreApplication::translate("ComClass", "Enviar", nullptr));
        rcvBox->setTitle(QCoreApplication::translate("ComClass", "Texto recivido:", nullptr));
        conexionGroupBox->setTitle(QCoreApplication::translate("ComClass", "Conexion", nullptr));
        puertoLabel->setText(QCoreApplication::translate("ComClass", "puerto", nullptr));
        ActualizarButton->setText(QCoreApplication::translate("ComClass", "actualizar", nullptr));
        conectarButton->setText(QCoreApplication::translate("ComClass", "conectar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComClass: public Ui_ComClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMCLASS_H
