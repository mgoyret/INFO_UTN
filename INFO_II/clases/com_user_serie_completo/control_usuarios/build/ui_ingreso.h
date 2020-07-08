/********************************************************************************
** Form generated from reading UI file 'ingreso.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INGRESO_H
#define UI_INGRESO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ingreso
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QLineEdit *userLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *claveLabel;
    QLineEdit *claveLine;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ingreso)
    {
        if (ingreso->objectName().isEmpty())
            ingreso->setObjectName(QString::fromUtf8("ingreso"));
        ingreso->resize(400, 282);
        verticalLayoutWidget = new QWidget(ingreso);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 80, 251, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        userLabel = new QLabel(verticalLayoutWidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        horizontalLayout->addWidget(userLabel);

        userLine = new QLineEdit(verticalLayoutWidget);
        userLine->setObjectName(QString::fromUtf8("userLine"));

        horizontalLayout->addWidget(userLine);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        claveLabel = new QLabel(verticalLayoutWidget);
        claveLabel->setObjectName(QString::fromUtf8("claveLabel"));

        horizontalLayout_2->addWidget(claveLabel);

        claveLine = new QLineEdit(verticalLayoutWidget);
        claveLine->setObjectName(QString::fromUtf8("claveLine"));
        claveLine->setEnabled(true);
        claveLine->setTabletTracking(false);
        claveLine->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        claveLine->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(claveLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayoutWidget = new QWidget(ingreso);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(130, 170, 169, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(horizontalLayoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(horizontalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        QWidget::setTabOrder(userLine, claveLine);
        QWidget::setTabOrder(claveLine, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(ingreso);

        QMetaObject::connectSlotsByName(ingreso);
    } // setupUi

    void retranslateUi(QDialog *ingreso)
    {
        ingreso->setWindowTitle(QCoreApplication::translate("ingreso", "Dialog", nullptr));
        userLabel->setText(QCoreApplication::translate("ingreso", "Usuario    ", nullptr));
        claveLabel->setText(QCoreApplication::translate("ingreso", "Clave       ", nullptr));
        okButton->setText(QCoreApplication::translate("ingreso", "Continuar", nullptr));
        cancelButton->setText(QCoreApplication::translate("ingreso", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ingreso: public Ui_ingreso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INGRESO_H
