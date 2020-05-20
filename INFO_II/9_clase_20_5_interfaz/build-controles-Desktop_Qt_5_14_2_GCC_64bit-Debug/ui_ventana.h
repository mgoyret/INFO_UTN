/********************************************************************************
** Form generated from reading UI file 'ventana.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_H
#define UI_VENTANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Ventana
{
public:
    QLabel *lblMiTexto;
    QPushButton *btnVolver;

    void setupUi(QDialog *Ventana)
    {
        if (Ventana->objectName().isEmpty())
            Ventana->setObjectName(QString::fromUtf8("Ventana"));
        Ventana->resize(400, 300);
        lblMiTexto = new QLabel(Ventana);
        lblMiTexto->setObjectName(QString::fromUtf8("lblMiTexto"));
        lblMiTexto->setGeometry(QRect(50, 70, 46, 13));
        btnVolver = new QPushButton(Ventana);
        btnVolver->setObjectName(QString::fromUtf8("btnVolver"));
        btnVolver->setGeometry(QRect(230, 70, 75, 23));

        retranslateUi(Ventana);

        QMetaObject::connectSlotsByName(Ventana);
    } // setupUi

    void retranslateUi(QDialog *Ventana)
    {
        Ventana->setWindowTitle(QCoreApplication::translate("Ventana", "Dialog", nullptr));
        lblMiTexto->setText(QCoreApplication::translate("Ventana", "TextLabel", nullptr));
        btnVolver->setText(QCoreApplication::translate("Ventana", "Volver", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ventana: public Ui_Ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
