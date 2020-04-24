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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
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
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QTableView *displayInfo;
    QLabel *calc_label;
    QLabel *calc_label_2;
    QLabel *calc_label_3;
    QLabel *label;
    QWidget *TeamInfoTab;
    QListWidget *listWidget;
    QTextEdit *textEdit;
    QPushButton *pushButton_TeamInfo;
    QWidget *PlanTripTab;
    QPushButton *DFS;
    QPushButton *BFS;
    QTextBrowser *TraversalDisplay;
    QComboBox *comboBox_3;
    QWidget *AlgorithmTab;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QWidget *Admin;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *SelectTeam;
    QSpacerItem *verticalSpacer;
    QTableWidget *ModifyTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1166, 743);
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
        pushButton_2 = new QPushButton(DisplayListsTab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(224, 122, 131, 31));
        QFont font;
        font.setPointSize(14);
        pushButton_2->setFont(font);
        comboBox = new QComboBox(DisplayListsTab);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 70, 331, 31));
        QFont font1;
        font1.setPointSize(10);
        comboBox->setFont(font1);
        displayInfo = new QTableView(DisplayListsTab);
        displayInfo->setObjectName(QString::fromUtf8("displayInfo"));
        displayInfo->setGeometry(QRect(370, 50, 801, 591));
        calc_label = new QLabel(DisplayListsTab);
        calc_label->setObjectName(QString::fromUtf8("calc_label"));
        calc_label->setGeometry(QRect(410, 649, 411, 21));
        QFont font2;
        font2.setPointSize(18);
        calc_label->setFont(font2);
        calc_label->setLayoutDirection(Qt::LeftToRight);
        calc_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        calc_label_2 = new QLabel(DisplayListsTab);
        calc_label_2->setObjectName(QString::fromUtf8("calc_label_2"));
        calc_label_2->setGeometry(QRect(860, 650, 101, 21));
        calc_label_2->setFont(font2);
        calc_label_3 = new QLabel(DisplayListsTab);
        calc_label_3->setObjectName(QString::fromUtf8("calc_label_3"));
        calc_label_3->setGeometry(QRect(970, 650, 161, 20));
        calc_label_3->setFont(font2);
        label = new QLabel(DisplayListsTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 91, 31));
        QFont font3;
        font3.setPointSize(12);
        label->setFont(font3);
        MainPageTabs->addTab(DisplayListsTab, QString());
        TeamInfoTab = new QWidget();
        TeamInfoTab->setObjectName(QString::fromUtf8("TeamInfoTab"));
        listWidget = new QListWidget(TeamInfoTab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(50, 40, 211, 481));
        textEdit = new QTextEdit(TeamInfoTab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(440, 40, 621, 481));
        pushButton_TeamInfo = new QPushButton(TeamInfoTab);
        pushButton_TeamInfo->setObjectName(QString::fromUtf8("pushButton_TeamInfo"));
        pushButton_TeamInfo->setGeometry(QRect(290, 230, 121, 71));
        pushButton_TeamInfo->setStyleSheet(QString::fromUtf8("html.solid {border-style: solid;}\n"
""));
        pushButton_TeamInfo->setAutoDefault(false);
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
        TraversalDisplay->setGeometry(QRect(240, 10, 951, 621));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Trebuchet MS"));
        font4.setPointSize(14);
        TraversalDisplay->setFont(font4);
        comboBox_3 = new QComboBox(PlanTripTab);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(30, 80, 72, 22));
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
        horizontalLayout_5 = new QHBoxLayout(Admin);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(Admin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(300, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Calibri"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        label_2->setFont(font5);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        SelectTeam = new QComboBox(Admin);
        SelectTeam->setObjectName(QString::fromUtf8("SelectTeam"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SelectTeam->sizePolicy().hasHeightForWidth());
        SelectTeam->setSizePolicy(sizePolicy1);
        SelectTeam->setMaximumSize(QSize(300, 16777215));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Calibri"));
        font6.setPointSize(12);
        SelectTeam->setFont(font6);

        verticalLayout_2->addWidget(SelectTeam);

        verticalSpacer = new QSpacerItem(300, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_2);

        ModifyTable = new QTableWidget(Admin);
        ModifyTable->setObjectName(QString::fromUtf8("ModifyTable"));
        ModifyTable->setFont(font6);

        horizontalLayout_4->addWidget(ModifyTable);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        UsersTabs->addTab(Admin, QString());

        verticalLayout->addWidget(UsersTabs);


        horizontalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1166, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        UsersTabs->setCurrentIndex(1);
        MainPageTabs->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "Admin Login", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(WelcomeTab), QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        calc_label->setText(QString());
        calc_label_2->setText(QString());
        calc_label_3->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Sort by:", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(DisplayListsTab), QCoreApplication::translate("MainWindow", "Display Lists", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_TeamInfo->setToolTip(QCoreApplication::translate("MainWindow", "<html class = \"solid\">\n"
"<head>\n"
"<style>\n"
"html.solid {border-style: solid;}\n"
"</style>\n"
"</head>\n"
"</html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_TeamInfo->setText(QString());
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
        label_2->setText(QCoreApplication::translate("MainWindow", "Select a Team to modify", nullptr));
        UsersTabs->setTabText(UsersTabs->indexOf(Admin), QCoreApplication::translate("MainWindow", "Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
