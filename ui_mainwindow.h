/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *login;
    QTabWidget *UsersTabs;
    QWidget *MainPage;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *MainPageTabs;
    QWidget *WelcomeTab;
    QWidget *DisplayListsTab;
    QTreeWidget *treeWidget;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QTextEdit *tempDisplayINFO;
    QPushButton *pushButton;
    QTableView *displayInfo;
    QWidget *TeamInfoTab;
    QTreeWidget *treeWidget_2;
    QWidget *PlanTripTab;
    QPushButton *DFS;
    QPushButton *BFS;
    QTextBrowser *TraversalDisplay;
    QWidget *AlgorithmTab;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QWidget *Admin;
    QTabWidget *tabWidget_2;
    QWidget *TeamAdmin;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QWidget *souvenirAdmin;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QComboBox *comboBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1245, 834);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        login = new QPushButton(centralwidget);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout->addWidget(login);


        verticalLayout->addLayout(horizontalLayout);

        UsersTabs = new QTabWidget(centralwidget);
        UsersTabs->setObjectName(QString::fromUtf8("UsersTabs"));
        UsersTabs->setTabBarAutoHide(true);
        MainPage = new QWidget();
        MainPage->setObjectName(QString::fromUtf8("MainPage"));
        horizontalLayout_2 = new QHBoxLayout(MainPage);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        MainPageTabs = new QTabWidget(MainPage);
        MainPageTabs->setObjectName(QString::fromUtf8("MainPageTabs"));
        WelcomeTab = new QWidget();
        WelcomeTab->setObjectName(QString::fromUtf8("WelcomeTab"));
        MainPageTabs->addTab(WelcomeTab, QString());
        DisplayListsTab = new QWidget();
        DisplayListsTab->setObjectName(QString::fromUtf8("DisplayListsTab"));
        treeWidget = new QTreeWidget(DisplayListsTab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(10, 60, 256, 192));
        pushButton_2 = new QPushButton(DisplayListsTab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 20, 75, 23));
        comboBox = new QComboBox(DisplayListsTab);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 20, 161, 21));
        tempDisplayINFO = new QTextEdit(DisplayListsTab);
        tempDisplayINFO->setObjectName(QString::fromUtf8("tempDisplayINFO"));
        tempDisplayINFO->setGeometry(QRect(10, 480, 311, 181));
        pushButton = new QPushButton(DisplayListsTab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 450, 80, 21));
        displayInfo = new QTableView(DisplayListsTab);
        displayInfo->setObjectName(QString::fromUtf8("displayInfo"));
        displayInfo->setGeometry(QRect(370, 50, 801, 591));
        MainPageTabs->addTab(DisplayListsTab, QString());
        TeamInfoTab = new QWidget();
        TeamInfoTab->setObjectName(QString::fromUtf8("TeamInfoTab"));
        treeWidget_2 = new QTreeWidget(TeamInfoTab);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem1);
        treeWidget_2->setObjectName(QString::fromUtf8("treeWidget_2"));
        treeWidget_2->setGeometry(QRect(360, 80, 256, 192));
        MainPageTabs->addTab(TeamInfoTab, QString());
        PlanTripTab = new QWidget();
        PlanTripTab->setObjectName(QString::fromUtf8("PlanTripTab"));
        DFS = new QPushButton(PlanTripTab);
        DFS->setObjectName(QString::fromUtf8("DFS"));
        DFS->setGeometry(QRect(10, 270, 80, 21));
        BFS = new QPushButton(PlanTripTab);
        BFS->setObjectName(QString::fromUtf8("BFS"));
        BFS->setGeometry(QRect(10, 340, 80, 21));
        TraversalDisplay = new QTextBrowser(PlanTripTab);
        TraversalDisplay->setObjectName(QString::fromUtf8("TraversalDisplay"));
        TraversalDisplay->setGeometry(QRect(120, 10, 1071, 621));
        QFont font;
        font.setFamily(QString::fromUtf8("Trebuchet MS"));
        font.setPointSize(14);
        TraversalDisplay->setFont(font);
        MainPageTabs->addTab(PlanTripTab, QString());
        AlgorithmTab = new QWidget();
        AlgorithmTab->setObjectName(QString::fromUtf8("AlgorithmTab"));
        pushButton_7 = new QPushButton(AlgorithmTab);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(200, 190, 181, 23));
        pushButton_8 = new QPushButton(AlgorithmTab);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(200, 220, 181, 23));
        pushButton_9 = new QPushButton(AlgorithmTab);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(200, 250, 181, 23));
        pushButton_10 = new QPushButton(AlgorithmTab);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(200, 280, 181, 23));
        MainPageTabs->addTab(AlgorithmTab, QString());

        horizontalLayout_2->addWidget(MainPageTabs);

        UsersTabs->addTab(MainPage, QString());
        Admin = new QWidget();
        Admin->setObjectName(QString::fromUtf8("Admin"));
        tabWidget_2 = new QTabWidget(Admin);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(30, 120, 651, 441));
        TeamAdmin = new QWidget();
        TeamAdmin->setObjectName(QString::fromUtf8("TeamAdmin"));
        pushButton_3 = new QPushButton(TeamAdmin);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 180, 141, 23));
        lineEdit = new QLineEdit(TeamAdmin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(290, 180, 113, 20));
        tabWidget_2->addTab(TeamAdmin, QString());
        souvenirAdmin = new QWidget();
        souvenirAdmin->setObjectName(QString::fromUtf8("souvenirAdmin"));
        doubleSpinBox = new QDoubleSpinBox(souvenirAdmin);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(450, 220, 62, 22));
        pushButton_4 = new QPushButton(souvenirAdmin);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 190, 101, 23));
        pushButton_5 = new QPushButton(souvenirAdmin);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(320, 220, 101, 23));
        pushButton_6 = new QPushButton(souvenirAdmin);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(320, 250, 101, 23));
        comboBox_2 = new QComboBox(souvenirAdmin);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(520, 60, 69, 22));
        tabWidget_2->addTab(souvenirAdmin, QString());
        UsersTabs->addTab(Admin, QString());

        verticalLayout->addWidget(UsersTabs);


        horizontalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1245, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        UsersTabs->setCurrentIndex(0);
        MainPageTabs->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "Admin Login", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(WelcomeTab), QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Display(temp)", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(DisplayListsTab), QCoreApplication::translate("MainWindow", "Display Lists", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(TeamInfoTab), QCoreApplication::translate("MainWindow", "Team Information", nullptr));
        DFS->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        BFS->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        TraversalDisplay->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Trebuchet MS'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(PlanTripTab), QCoreApplication::translate("MainWindow", "Plan Trip", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Dijkstra\342\200\231s or the A* algorithm", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Prim\342\200\231s or Kruskal\342\200\231s algorithm", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(AlgorithmTab), QCoreApplication::translate("MainWindow", "Algorithm Test", nullptr));
        UsersTabs->setTabText(UsersTabs->indexOf(MainPage), QCoreApplication::translate("MainWindow", "Main Page", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Change Team Info", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(TeamAdmin), QCoreApplication::translate("MainWindow", "Team", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Add souvenir", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Change souvenir", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Delete souvenir", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(souvenirAdmin), QCoreApplication::translate("MainWindow", "Souvenirs", nullptr));
        UsersTabs->setTabText(UsersTabs->indexOf(Admin), QCoreApplication::translate("MainWindow", "Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
