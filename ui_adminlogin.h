/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_adminLogin
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *errorText;
    QLineEdit *pwEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OK;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *adminLogin)
    {
        if (adminLogin->objectName().isEmpty())
            adminLogin->setObjectName(QString::fromUtf8("adminLogin"));
        adminLogin->resize(259, 195);
        horizontalLayout_2 = new QHBoxLayout(adminLogin);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(adminLogin);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        errorText = new QLabel(adminLogin);
        errorText->setObjectName(QString::fromUtf8("errorText"));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        errorText->setFont(font);
        errorText->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(errorText);

        pwEdit = new QLineEdit(adminLogin);
        pwEdit->setObjectName(QString::fromUtf8("pwEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pwEdit->sizePolicy().hasHeightForWidth());
        pwEdit->setSizePolicy(sizePolicy);
        pwEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(pwEdit);

        verticalSpacer = new QSpacerItem(13, 30, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OK = new QPushButton(adminLogin);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout->addWidget(OK);

        cancel = new QPushButton(adminLogin);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(adminLogin);

        QMetaObject::connectSlotsByName(adminLogin);
    } // setupUi

    void retranslateUi(QDialog *adminLogin)
    {
        adminLogin->setWindowTitle(QCoreApplication::translate("adminLogin", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("adminLogin", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline;\">Admin Login</span></p><p align=\"center\"><span style=\" font-size:14pt;\">Enter Password</span></p></body></html>", nullptr));
        errorText->setText(QCoreApplication::translate("adminLogin", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Password</span></p></body></html>", nullptr));
        OK->setText(QCoreApplication::translate("adminLogin", "Ok", nullptr));
        cancel->setText(QCoreApplication::translate("adminLogin", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminLogin: public Ui_adminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
