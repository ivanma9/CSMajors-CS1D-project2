/********************************************************************************
** Form generated from reading UI file 'AdminWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *PushButton_BackTMain;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *PushButton_AddEmployee;
    QPushButton *PushButton_DeleteEmployee;
    QPushButton *PushButton_EditEmployee;
    QVBoxLayout *verticalLayout_2;
    QPushButton *PushButton_AddMember;
    QPushButton *PushButton_DeleteMember;
    QPushButton *PushButton_EditMember;
    QPushButton *PushButton_NewPurchase;
    QVBoxLayout *verticalLayout_3;
    QPushButton *PushButton_AddItem;
    QPushButton *PushButton_DelteItem;
    QPushButton *PushButton_EditItem;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(613, 504);
        layoutWidget = new QWidget(AdminWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 20, 401, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        PushButton_BackTMain = new QPushButton(layoutWidget);
        PushButton_BackTMain->setObjectName(QString::fromUtf8("PushButton_BackTMain"));

        horizontalLayout->addWidget(PushButton_BackTMain);

        horizontalSpacer = new QSpacerItem(148, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        layoutWidget_2 = new QWidget(AdminWindow);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 160, 581, 331));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        PushButton_AddEmployee = new QPushButton(layoutWidget_2);
        PushButton_AddEmployee->setObjectName(QString::fromUtf8("PushButton_AddEmployee"));

        verticalLayout->addWidget(PushButton_AddEmployee);

        PushButton_DeleteEmployee = new QPushButton(layoutWidget_2);
        PushButton_DeleteEmployee->setObjectName(QString::fromUtf8("PushButton_DeleteEmployee"));

        verticalLayout->addWidget(PushButton_DeleteEmployee);

        PushButton_EditEmployee = new QPushButton(layoutWidget_2);
        PushButton_EditEmployee->setObjectName(QString::fromUtf8("PushButton_EditEmployee"));

        verticalLayout->addWidget(PushButton_EditEmployee);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        PushButton_AddMember = new QPushButton(layoutWidget_2);
        PushButton_AddMember->setObjectName(QString::fromUtf8("PushButton_AddMember"));

        verticalLayout_2->addWidget(PushButton_AddMember);

        PushButton_DeleteMember = new QPushButton(layoutWidget_2);
        PushButton_DeleteMember->setObjectName(QString::fromUtf8("PushButton_DeleteMember"));

        verticalLayout_2->addWidget(PushButton_DeleteMember);

        PushButton_EditMember = new QPushButton(layoutWidget_2);
        PushButton_EditMember->setObjectName(QString::fromUtf8("PushButton_EditMember"));

        verticalLayout_2->addWidget(PushButton_EditMember);

        PushButton_NewPurchase = new QPushButton(layoutWidget_2);
        PushButton_NewPurchase->setObjectName(QString::fromUtf8("PushButton_NewPurchase"));

        verticalLayout_2->addWidget(PushButton_NewPurchase);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        PushButton_AddItem = new QPushButton(layoutWidget_2);
        PushButton_AddItem->setObjectName(QString::fromUtf8("PushButton_AddItem"));

        verticalLayout_3->addWidget(PushButton_AddItem);

        PushButton_DelteItem = new QPushButton(layoutWidget_2);
        PushButton_DelteItem->setObjectName(QString::fromUtf8("PushButton_DelteItem"));

        verticalLayout_3->addWidget(PushButton_DelteItem);

        PushButton_EditItem = new QPushButton(layoutWidget_2);
        PushButton_EditItem->setObjectName(QString::fromUtf8("PushButton_EditItem"));

        verticalLayout_3->addWidget(PushButton_EditItem);


        horizontalLayout_2->addLayout(verticalLayout_3);


        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "Dialog", nullptr));
        PushButton_BackTMain->setText(QCoreApplication::translate("AdminWindow", "Logout", nullptr));
        label->setText(QCoreApplication::translate("AdminWindow", "Welcome Administrator", nullptr));
        PushButton_AddEmployee->setText(QCoreApplication::translate("AdminWindow", "Add Employee", nullptr));
        PushButton_DeleteEmployee->setText(QCoreApplication::translate("AdminWindow", "Delete Employee", nullptr));
        PushButton_EditEmployee->setText(QCoreApplication::translate("AdminWindow", "Edit Employee Information", nullptr));
        PushButton_AddMember->setText(QCoreApplication::translate("AdminWindow", "Add Member", nullptr));
        PushButton_DeleteMember->setText(QCoreApplication::translate("AdminWindow", "Delete Member", nullptr));
        PushButton_EditMember->setText(QCoreApplication::translate("AdminWindow", "Edit Member", nullptr));
        PushButton_NewPurchase->setText(QCoreApplication::translate("AdminWindow", "New Purchase", nullptr));
        PushButton_AddItem->setText(QCoreApplication::translate("AdminWindow", "Add Item", nullptr));
        PushButton_DelteItem->setText(QCoreApplication::translate("AdminWindow", "Delete Item", nullptr));
        PushButton_EditItem->setText(QCoreApplication::translate("AdminWindow", "Edit Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
