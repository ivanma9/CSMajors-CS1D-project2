/********************************************************************************
** Form generated from reading UI file 'ManagerWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWINDOW_H
#define UI_MANAGERWINDOW_H

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

class Ui_ManagerWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *PushButton_BackTMain;
    QSpacerItem *horizontalSpacer;
    QLabel *label_welcomeManager;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *PushButton_displaySalesReport;
    QPushButton *PushButton_displayPurchases;
    QPushButton *PushButton_inventory;
    QPushButton *PushButton_itemSearch;
    QPushButton *PushButton_displayMembers;

    void setupUi(QDialog *ManagerWindow)
    {
        if (ManagerWindow->objectName().isEmpty())
            ManagerWindow->setObjectName(QString::fromUtf8("ManagerWindow"));
        ManagerWindow->resize(619, 506);
        layoutWidget = new QWidget(ManagerWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 10, 361, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        PushButton_BackTMain = new QPushButton(layoutWidget);
        PushButton_BackTMain->setObjectName(QString::fromUtf8("PushButton_BackTMain"));

        horizontalLayout->addWidget(PushButton_BackTMain);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_welcomeManager = new QLabel(layoutWidget);
        label_welcomeManager->setObjectName(QString::fromUtf8("label_welcomeManager"));

        horizontalLayout->addWidget(label_welcomeManager);

        layoutWidget_2 = new QWidget(ManagerWindow);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 110, 581, 371));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        PushButton_displaySalesReport = new QPushButton(layoutWidget_2);
        PushButton_displaySalesReport->setObjectName(QString::fromUtf8("PushButton_displaySalesReport"));
        PushButton_displaySalesReport->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(PushButton_displaySalesReport);

        PushButton_displayPurchases = new QPushButton(layoutWidget_2);
        PushButton_displayPurchases->setObjectName(QString::fromUtf8("PushButton_displayPurchases"));

        verticalLayout->addWidget(PushButton_displayPurchases);

        PushButton_inventory = new QPushButton(layoutWidget_2);
        PushButton_inventory->setObjectName(QString::fromUtf8("PushButton_inventory"));

        verticalLayout->addWidget(PushButton_inventory);

        PushButton_itemSearch = new QPushButton(layoutWidget_2);
        PushButton_itemSearch->setObjectName(QString::fromUtf8("PushButton_itemSearch"));

        verticalLayout->addWidget(PushButton_itemSearch);


        horizontalLayout_2->addLayout(verticalLayout);

        PushButton_displayMembers = new QPushButton(layoutWidget_2);
        PushButton_displayMembers->setObjectName(QString::fromUtf8("PushButton_displayMembers"));

        horizontalLayout_2->addWidget(PushButton_displayMembers);


        retranslateUi(ManagerWindow);

        QMetaObject::connectSlotsByName(ManagerWindow);
    } // setupUi

    void retranslateUi(QDialog *ManagerWindow)
    {
        ManagerWindow->setWindowTitle(QCoreApplication::translate("ManagerWindow", "Dialog", nullptr));
        PushButton_BackTMain->setText(QCoreApplication::translate("ManagerWindow", "Logout", nullptr));
        label_welcomeManager->setText(QCoreApplication::translate("ManagerWindow", "Welcome Manager", nullptr));
        PushButton_displaySalesReport->setText(QCoreApplication::translate("ManagerWindow", "Display Sales Report", nullptr));
        PushButton_displayPurchases->setText(QCoreApplication::translate("ManagerWindow", "Display Purchases", nullptr));
        PushButton_inventory->setText(QCoreApplication::translate("ManagerWindow", "Inventory", nullptr));
        PushButton_itemSearch->setText(QCoreApplication::translate("ManagerWindow", "Item Search", nullptr));
        PushButton_displayMembers->setText(QCoreApplication::translate("ManagerWindow", "Display Members", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerWindow: public Ui_ManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
