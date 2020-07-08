/********************************************************************************
** Form generated from reading UI file 'commodule.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMODULE_H
#define UI_COMMODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComModule
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *enviarBox;
    QTextEdit *enviarText;
    QPushButton *enviarButton;
    QGroupBox *rcvBox;
    QTextBrowser *rcvText;

    void setupUi(QDialog *ComModule)
    {
        if (ComModule->objectName().isEmpty())
            ComModule->setObjectName(QString::fromUtf8("ComModule"));
        ComModule->resize(559, 607);
        verticalLayoutWidget = new QWidget(ComModule);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 541, 591));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        enviarBox = new QGroupBox(verticalLayoutWidget);
        enviarBox->setObjectName(QString::fromUtf8("enviarBox"));
        enviarText = new QTextEdit(enviarBox);
        enviarText->setObjectName(QString::fromUtf8("enviarText"));
        enviarText->setGeometry(QRect(10, 30, 511, 221));
        enviarButton = new QPushButton(enviarBox);
        enviarButton->setObjectName(QString::fromUtf8("enviarButton"));
        enviarButton->setGeometry(QRect(10, 260, 91, 25));

        verticalLayout_2->addWidget(enviarBox);

        rcvBox = new QGroupBox(verticalLayoutWidget);
        rcvBox->setObjectName(QString::fromUtf8("rcvBox"));
        rcvText = new QTextBrowser(rcvBox);
        rcvText->setObjectName(QString::fromUtf8("rcvText"));
        rcvText->setGeometry(QRect(10, 30, 521, 251));

        verticalLayout_2->addWidget(rcvBox);


        retranslateUi(ComModule);

        QMetaObject::connectSlotsByName(ComModule);
    } // setupUi

    void retranslateUi(QDialog *ComModule)
    {
        ComModule->setWindowTitle(QCoreApplication::translate("ComModule", "Dialog", nullptr));
        enviarBox->setTitle(QCoreApplication::translate("ComModule", "Texto a enviar:", nullptr));
        enviarButton->setText(QCoreApplication::translate("ComModule", "Enviar", nullptr));
        rcvBox->setTitle(QCoreApplication::translate("ComModule", "Texto recivido:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComModule: public Ui_ComModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMODULE_H
