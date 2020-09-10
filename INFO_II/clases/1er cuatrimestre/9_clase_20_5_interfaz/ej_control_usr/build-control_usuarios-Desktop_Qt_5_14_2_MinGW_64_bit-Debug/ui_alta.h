/********************************************************************************
** Form generated from reading UI file 'alta.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTA_H
#define UI_ALTA_H

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

class Ui_alta
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *nombreLabel;
    QLineEdit *nombreLine;
    QHBoxLayout *horizontalLayout;
    QLabel *apellidoLabel;
    QLineEdit *apellidoLine;
    QHBoxLayout *horizontalLayout_4;
    QLabel *emailLabel;
    QLineEdit *emailLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *usuarioLabel;
    QLineEdit *usuarioLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *claveLabel;
    QLineEdit *claveLine;
    QLabel *subtitulo;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *alta)
    {
        if (alta->objectName().isEmpty())
            alta->setObjectName(QString::fromUtf8("alta"));
        alta->resize(466, 329);
        verticalLayoutWidget = new QWidget(alta);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 60, 251, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        nombreLabel = new QLabel(verticalLayoutWidget);
        nombreLabel->setObjectName(QString::fromUtf8("nombreLabel"));

        horizontalLayout_5->addWidget(nombreLabel);

        nombreLine = new QLineEdit(verticalLayoutWidget);
        nombreLine->setObjectName(QString::fromUtf8("nombreLine"));

        horizontalLayout_5->addWidget(nombreLine);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        apellidoLabel = new QLabel(verticalLayoutWidget);
        apellidoLabel->setObjectName(QString::fromUtf8("apellidoLabel"));

        horizontalLayout->addWidget(apellidoLabel);

        apellidoLine = new QLineEdit(verticalLayoutWidget);
        apellidoLine->setObjectName(QString::fromUtf8("apellidoLine"));

        horizontalLayout->addWidget(apellidoLine);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        emailLabel = new QLabel(verticalLayoutWidget);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));

        horizontalLayout_4->addWidget(emailLabel);

        emailLine = new QLineEdit(verticalLayoutWidget);
        emailLine->setObjectName(QString::fromUtf8("emailLine"));

        horizontalLayout_4->addWidget(emailLine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        usuarioLabel = new QLabel(verticalLayoutWidget);
        usuarioLabel->setObjectName(QString::fromUtf8("usuarioLabel"));

        horizontalLayout_3->addWidget(usuarioLabel);

        usuarioLine = new QLineEdit(verticalLayoutWidget);
        usuarioLine->setObjectName(QString::fromUtf8("usuarioLine"));
        usuarioLine->setEchoMode(QLineEdit::Normal);

        horizontalLayout_3->addWidget(usuarioLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        claveLabel = new QLabel(verticalLayoutWidget);
        claveLabel->setObjectName(QString::fromUtf8("claveLabel"));

        horizontalLayout_2->addWidget(claveLabel);

        claveLine = new QLineEdit(verticalLayoutWidget);
        claveLine->setObjectName(QString::fromUtf8("claveLine"));
        claveLine->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_2->addWidget(claveLine);


        verticalLayout->addLayout(horizontalLayout_2);

        subtitulo = new QLabel(alta);
        subtitulo->setObjectName(QString::fromUtf8("subtitulo"));
        subtitulo->setGeometry(QRect(140, 20, 181, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        subtitulo->setFont(font);
        subtitulo->setTextFormat(Qt::AutoText);
        horizontalLayoutWidget_6 = new QWidget(alta);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(180, 270, 169, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(horizontalLayoutWidget_6);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_6->addWidget(okButton);

        cancelButton = new QPushButton(horizontalLayoutWidget_6);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_6->addWidget(cancelButton);


        retranslateUi(alta);

        QMetaObject::connectSlotsByName(alta);
    } // setupUi

    void retranslateUi(QDialog *alta)
    {
        alta->setWindowTitle(QCoreApplication::translate("alta", "Dialog", nullptr));
        nombreLabel->setText(QCoreApplication::translate("alta", "Nombre", nullptr));
        apellidoLabel->setText(QCoreApplication::translate("alta", "Apellido", nullptr));
        emailLabel->setText(QCoreApplication::translate("alta", "Email    ", nullptr));
        usuarioLabel->setText(QCoreApplication::translate("alta", "Usuario ", nullptr));
        claveLabel->setText(QCoreApplication::translate("alta", "Clave    ", nullptr));
        subtitulo->setText(QCoreApplication::translate("alta", "Complete todos los campos", nullptr));
        okButton->setText(QCoreApplication::translate("alta", "Continuar", nullptr));
        cancelButton->setText(QCoreApplication::translate("alta", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alta: public Ui_alta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTA_H
