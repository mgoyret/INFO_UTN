/********************************************************************************
** Form generated from reading UI file 'datos.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATOS_H
#define UI_DATOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Datos
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *userLabel_2;
    QLineEdit *userLine_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *claveLabel;
    QLineEdit *claveLine;

    void setupUi(QWidget *Datos)
    {
        if (Datos->objectName().isEmpty())
            Datos->setObjectName(QString::fromUtf8("Datos"));
        Datos->resize(400, 300);
        verticalLayoutWidget = new QWidget(Datos);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 90, 271, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        userLabel_2 = new QLabel(verticalLayoutWidget);
        userLabel_2->setObjectName(QString::fromUtf8("userLabel_2"));

        horizontalLayout_4->addWidget(userLabel_2);

        userLine_2 = new QLineEdit(verticalLayoutWidget);
        userLine_2->setObjectName(QString::fromUtf8("userLine_2"));

        horizontalLayout_4->addWidget(userLine_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        claveLabel = new QLabel(verticalLayoutWidget);
        claveLabel->setObjectName(QString::fromUtf8("claveLabel"));

        horizontalLayout_3->addWidget(claveLabel);

        claveLine = new QLineEdit(verticalLayoutWidget);
        claveLine->setObjectName(QString::fromUtf8("claveLine"));

        horizontalLayout_3->addWidget(claveLine);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(Datos);

        QMetaObject::connectSlotsByName(Datos);
    } // setupUi

    void retranslateUi(QWidget *Datos)
    {
        Datos->setWindowTitle(QCoreApplication::translate("Datos", "Form", nullptr));
        userLabel_2->setText(QCoreApplication::translate("Datos", "Usuario    ", nullptr));
        claveLabel->setText(QCoreApplication::translate("Datos", "Clave       ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Datos: public Ui_Datos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATOS_H
