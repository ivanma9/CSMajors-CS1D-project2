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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
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
    QHBoxLayout *horizontalLayout_19;
    QLabel *WelcomePage;
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
    QLabel *InfoLogo;
    QWidget *PlanTripTab;
    QHBoxLayout *horizontalLayout_8;
    QStackedWidget *PlanTripStacked;
    QWidget *PlanTrip;
    QVBoxLayout *verticalLayout_9;
    QSplitter *splitter;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *label_8;
    QComboBox *TripSelectTeam;
    QFrame *line_7;
    QLabel *TeamLogo;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *PlanTripButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *PlanTripDijkstra;
    QSpacerItem *horizontalSpacer_8;
    QFrame *line_5;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_16;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QListWidget *CustomTripSelect;
    QLabel *label_6;
    QLabel *label_7;
    QListWidget *CustomTripSELECTED;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ResetTrip;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *PlanCustomTripButton;
    QWidget *Souvenirs;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QTableWidget *TripTable;
    QLabel *DistanceTravelled;
    QLabel *TotalCost;
    QPushButton *CompleteTrip;
    QVBoxLayout *verticalLayout_8;
    QTextEdit *StadiumTripInfo;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *PrevStadium;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *NextStadium;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_7;
    QLabel *BuyHeader;
    QTableWidget *Souvenir;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *ResetSouvenir;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *BuySouvenir;
    QWidget *AlgorithmTab;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *SELECTTEAM;
    QComboBox *CustomSelect;
    QSpacerItem *verticalSpacer_2;
    QPushButton *CustomDijkstra;
    QSpacerItem *verticalSpacer_4;
    QPushButton *CustomDFS;
    QSpacerItem *verticalSpacer_6;
    QPushButton *CustomBFS;
    QFrame *line;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_3;
    QPushButton *CustomMST;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_2;
    QLabel *CustomTotal;
    QTableWidget *CustomTable;
    QWidget *Admin;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *SelectTeam;
    QSpacerItem *verticalSpacer;
    QPushButton *AddSouv;
    QPushButton *DeleteSouv;
    QSpacerItem *verticalSpacer_7;
    QPushButton *LV_Button;
    QPushButton *reset;
    QTableWidget *ModifyTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1137, 710);
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
        horizontalLayout_19 = new QHBoxLayout(WelcomeTab);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        WelcomePage = new QLabel(WelcomeTab);
        WelcomePage->setObjectName(QString::fromUtf8("WelcomePage"));
        WelcomePage->setFrameShape(QFrame::NoFrame);
        WelcomePage->setFrameShadow(QFrame::Plain);
        WelcomePage->setPixmap(QPixmap(QString::fromUtf8(":/img/300 x 300px PNG/Welcome_Page_1200_x_600_PNG.png")));
        WelcomePage->setScaledContents(true);
        WelcomePage->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(WelcomePage);

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
        listWidget->setGeometry(QRect(9, 9, 251, 531));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        textEdit = new QTextEdit(TeamInfoTab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(430, 10, 651, 521));
        textEdit->setLayoutDirection(Qt::LeftToRight);
        pushButton_TeamInfo = new QPushButton(TeamInfoTab);
        pushButton_TeamInfo->setObjectName(QString::fromUtf8("pushButton_TeamInfo"));
        pushButton_TeamInfo->setGeometry(QRect(270, 220, 151, 87));
        sizePolicy.setHeightForWidth(pushButton_TeamInfo->sizePolicy().hasHeightForWidth());
        pushButton_TeamInfo->setSizePolicy(sizePolicy);
        pushButton_TeamInfo->setMaximumSize(QSize(300, 500));
        pushButton_TeamInfo->setStyleSheet(QString::fromUtf8("html.solid {border-style: solid;}\n"
""));
        pushButton_TeamInfo->setAutoDefault(false);
        InfoLogo = new QLabel(TeamInfoTab);
        InfoLogo->setObjectName(QString::fromUtf8("InfoLogo"));
        InfoLogo->setGeometry(QRect(270, 40, 151, 161));
        sizePolicy.setHeightForWidth(InfoLogo->sizePolicy().hasHeightForWidth());
        InfoLogo->setSizePolicy(sizePolicy);
        InfoLogo->setMaximumSize(QSize(300, 300));
        InfoLogo->setFrameShape(QFrame::NoFrame);
        InfoLogo->setFrameShadow(QFrame::Plain);
        InfoLogo->setPixmap(QPixmap(QString::fromUtf8(":/logos/300 x 300px PNG/arizona-diamondbacks-logo-transparent.png")));
        InfoLogo->setScaledContents(true);
        InfoLogo->setWordWrap(true);
        MainPageTabs->addTab(TeamInfoTab, QString());
        PlanTripTab = new QWidget();
        PlanTripTab->setObjectName(QString::fromUtf8("PlanTripTab"));
        horizontalLayout_8 = new QHBoxLayout(PlanTripTab);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        PlanTripStacked = new QStackedWidget(PlanTripTab);
        PlanTripStacked->setObjectName(QString::fromUtf8("PlanTripStacked"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PlanTripStacked->sizePolicy().hasHeightForWidth());
        PlanTripStacked->setSizePolicy(sizePolicy1);
        PlanTrip = new QWidget();
        PlanTrip->setObjectName(QString::fromUtf8("PlanTrip"));
        verticalLayout_9 = new QVBoxLayout(PlanTrip);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        splitter = new QSplitter(PlanTrip);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_18 = new QHBoxLayout(widget);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMaximumSize(QSize(16777215, 100));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Calibri"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Calibri"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_8->setFont(font5);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_8);

        TripSelectTeam = new QComboBox(widget);
        TripSelectTeam->setObjectName(QString::fromUtf8("TripSelectTeam"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TripSelectTeam->sizePolicy().hasHeightForWidth());
        TripSelectTeam->setSizePolicy(sizePolicy3);
        TripSelectTeam->setMaximumSize(QSize(16777215, 16777215));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Calibri"));
        font6.setPointSize(12);
        TripSelectTeam->setFont(font6);

        verticalLayout_5->addWidget(TripSelectTeam);

        line_7 = new QFrame(widget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_7);

        TeamLogo = new QLabel(widget);
        TeamLogo->setObjectName(QString::fromUtf8("TeamLogo"));
        sizePolicy.setHeightForWidth(TeamLogo->sizePolicy().hasHeightForWidth());
        TeamLogo->setSizePolicy(sizePolicy);
        TeamLogo->setMaximumSize(QSize(400, 500));
        TeamLogo->setWordWrap(true);

        verticalLayout_5->addWidget(TeamLogo);

        line_6 = new QFrame(widget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_6);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        PlanTripButton = new QPushButton(widget);
        PlanTripButton->setObjectName(QString::fromUtf8("PlanTripButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(PlanTripButton->sizePolicy().hasHeightForWidth());
        PlanTripButton->setSizePolicy(sizePolicy4);
        PlanTripButton->setMaximumSize(QSize(300, 50));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Calibri"));
        font7.setPointSize(16);
        PlanTripButton->setFont(font7);

        horizontalLayout_11->addWidget(PlanTripButton);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        PlanTripDijkstra = new QPushButton(widget);
        PlanTripDijkstra->setObjectName(QString::fromUtf8("PlanTripDijkstra"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(PlanTripDijkstra->sizePolicy().hasHeightForWidth());
        PlanTripDijkstra->setSizePolicy(sizePolicy5);
        PlanTripDijkstra->setMaximumSize(QSize(300, 50));
        PlanTripDijkstra->setFont(font7);

        horizontalLayout_11->addWidget(PlanTripDijkstra);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_11);


        horizontalLayout_18->addLayout(verticalLayout_5);

        line_5 = new QFrame(widget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_18->addWidget(line_5);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        horizontalLayout_16 = new QHBoxLayout(widget1);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        line_4 = new QFrame(widget1);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy6);
        label_5->setMaximumSize(QSize(250, 16777215));
        label_5->setFont(font4);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_10);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CustomTripSelect = new QListWidget(widget1);
        CustomTripSelect->setObjectName(QString::fromUtf8("CustomTripSelect"));
        CustomTripSelect->setFont(font6);

        gridLayout->addWidget(CustomTripSelect, 1, 0, 1, 1);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMaximumSize(QSize(16777215, 16777215));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Calibri"));
        font8.setPointSize(14);
        font8.setBold(true);
        font8.setWeight(75);
        label_6->setFont(font8);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setFont(font8);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        CustomTripSELECTED = new QListWidget(widget1);
        CustomTripSELECTED->setObjectName(QString::fromUtf8("CustomTripSELECTED"));
        CustomTripSELECTED->setFont(font6);

        gridLayout->addWidget(CustomTripSELECTED, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        ResetTrip = new QPushButton(widget1);
        ResetTrip->setObjectName(QString::fromUtf8("ResetTrip"));
        ResetTrip->setMaximumSize(QSize(250, 16777215));
        ResetTrip->setFont(font6);

        horizontalLayout_9->addWidget(ResetTrip);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_9);

        line_3 = new QFrame(widget1);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setSizeConstraint(QLayout::SetMaximumSize);
        PlanCustomTripButton = new QPushButton(widget1);
        PlanCustomTripButton->setObjectName(QString::fromUtf8("PlanCustomTripButton"));
        sizePolicy4.setHeightForWidth(PlanCustomTripButton->sizePolicy().hasHeightForWidth());
        PlanCustomTripButton->setSizePolicy(sizePolicy4);
        PlanCustomTripButton->setFont(font7);

        horizontalLayout_17->addWidget(PlanCustomTripButton);


        verticalLayout_4->addLayout(horizontalLayout_17);


        horizontalLayout_16->addLayout(verticalLayout_4);

        splitter->addWidget(widget1);

        verticalLayout_9->addWidget(splitter);

        PlanTripStacked->addWidget(PlanTrip);
        Souvenirs = new QWidget();
        Souvenirs->setObjectName(QString::fromUtf8("Souvenirs"));
        horizontalLayout_15 = new QHBoxLayout(Souvenirs);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_9 = new QLabel(Souvenirs);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy6.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy6);
        label_9->setMaximumSize(QSize(400, 16777215));
        label_9->setFont(font4);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_9);

        TripTable = new QTableWidget(Souvenirs);
        TripTable->setObjectName(QString::fromUtf8("TripTable"));
        sizePolicy.setHeightForWidth(TripTable->sizePolicy().hasHeightForWidth());
        TripTable->setSizePolicy(sizePolicy);
        TripTable->setMaximumSize(QSize(350, 16777215));
        TripTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TripTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TripTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout_6->addWidget(TripTable);

        DistanceTravelled = new QLabel(Souvenirs);
        DistanceTravelled->setObjectName(QString::fromUtf8("DistanceTravelled"));
        sizePolicy6.setHeightForWidth(DistanceTravelled->sizePolicy().hasHeightForWidth());
        DistanceTravelled->setSizePolicy(sizePolicy6);
        DistanceTravelled->setMaximumSize(QSize(400, 16777215));
        DistanceTravelled->setFont(font8);
        DistanceTravelled->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_6->addWidget(DistanceTravelled);

        TotalCost = new QLabel(Souvenirs);
        TotalCost->setObjectName(QString::fromUtf8("TotalCost"));
        sizePolicy6.setHeightForWidth(TotalCost->sizePolicy().hasHeightForWidth());
        TotalCost->setSizePolicy(sizePolicy6);
        TotalCost->setMaximumSize(QSize(400, 16777215));
        TotalCost->setFont(font8);
        TotalCost->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_6->addWidget(TotalCost);

        CompleteTrip = new QPushButton(Souvenirs);
        CompleteTrip->setObjectName(QString::fromUtf8("CompleteTrip"));
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(CompleteTrip->sizePolicy().hasHeightForWidth());
        CompleteTrip->setSizePolicy(sizePolicy7);
        CompleteTrip->setMaximumSize(QSize(350, 30));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Calibri"));
        font9.setPointSize(16);
        font9.setBold(true);
        font9.setItalic(true);
        font9.setWeight(75);
        CompleteTrip->setFont(font9);

        verticalLayout_6->addWidget(CompleteTrip);


        horizontalLayout_15->addLayout(verticalLayout_6);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        StadiumTripInfo = new QTextEdit(Souvenirs);
        StadiumTripInfo->setObjectName(QString::fromUtf8("StadiumTripInfo"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(StadiumTripInfo->sizePolicy().hasHeightForWidth());
        StadiumTripInfo->setSizePolicy(sizePolicy8);
        StadiumTripInfo->setFont(font6);

        verticalLayout_8->addWidget(StadiumTripInfo);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_10);

        PrevStadium = new QPushButton(Souvenirs);
        PrevStadium->setObjectName(QString::fromUtf8("PrevStadium"));
        sizePolicy5.setHeightForWidth(PrevStadium->sizePolicy().hasHeightForWidth());
        PrevStadium->setSizePolicy(sizePolicy5);
        PrevStadium->setMaximumSize(QSize(250, 30));
        PrevStadium->setFont(font6);

        horizontalLayout_12->addWidget(PrevStadium);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);

        NextStadium = new QPushButton(Souvenirs);
        NextStadium->setObjectName(QString::fromUtf8("NextStadium"));
        sizePolicy5.setHeightForWidth(NextStadium->sizePolicy().hasHeightForWidth());
        NextStadium->setSizePolicy(sizePolicy5);
        NextStadium->setMaximumSize(QSize(250, 30));
        NextStadium->setFont(font6);

        horizontalLayout_12->addWidget(NextStadium);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_11);


        verticalLayout_8->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_12 = new QLabel(Souvenirs);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setMaximumSize(QSize(200, 200));

        horizontalLayout_14->addWidget(label_12);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        BuyHeader = new QLabel(Souvenirs);
        BuyHeader->setObjectName(QString::fromUtf8("BuyHeader"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(BuyHeader->sizePolicy().hasHeightForWidth());
        BuyHeader->setSizePolicy(sizePolicy9);
        BuyHeader->setFont(font8);
        BuyHeader->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(BuyHeader);

        Souvenir = new QTableWidget(Souvenirs);
        Souvenir->setObjectName(QString::fromUtf8("Souvenir"));
        sizePolicy2.setHeightForWidth(Souvenir->sizePolicy().hasHeightForWidth());
        Souvenir->setSizePolicy(sizePolicy2);
        Souvenir->setMaximumSize(QSize(16777215, 300));
        Souvenir->setFont(font6);

        verticalLayout_7->addWidget(Souvenir);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        ResetSouvenir = new QPushButton(Souvenirs);
        ResetSouvenir->setObjectName(QString::fromUtf8("ResetSouvenir"));
        sizePolicy5.setHeightForWidth(ResetSouvenir->sizePolicy().hasHeightForWidth());
        ResetSouvenir->setSizePolicy(sizePolicy5);
        ResetSouvenir->setMaximumSize(QSize(250, 30));
        ResetSouvenir->setFont(font6);

        horizontalLayout_13->addWidget(ResetSouvenir);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_12);

        BuySouvenir = new QPushButton(Souvenirs);
        BuySouvenir->setObjectName(QString::fromUtf8("BuySouvenir"));
        sizePolicy5.setHeightForWidth(BuySouvenir->sizePolicy().hasHeightForWidth());
        BuySouvenir->setSizePolicy(sizePolicy5);
        BuySouvenir->setMaximumSize(QSize(250, 30));
        BuySouvenir->setFont(font6);

        horizontalLayout_13->addWidget(BuySouvenir);


        verticalLayout_7->addLayout(horizontalLayout_13);


        horizontalLayout_14->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_14);


        horizontalLayout_15->addLayout(verticalLayout_8);

        PlanTripStacked->addWidget(Souvenirs);

        horizontalLayout_8->addWidget(PlanTripStacked);

        MainPageTabs->addTab(PlanTripTab, QString());
        AlgorithmTab = new QWidget();
        AlgorithmTab->setObjectName(QString::fromUtf8("AlgorithmTab"));
        horizontalLayout_7 = new QHBoxLayout(AlgorithmTab);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        SELECTTEAM = new QLabel(AlgorithmTab);
        SELECTTEAM->setObjectName(QString::fromUtf8("SELECTTEAM"));
        sizePolicy6.setHeightForWidth(SELECTTEAM->sizePolicy().hasHeightForWidth());
        SELECTTEAM->setSizePolicy(sizePolicy6);
        SELECTTEAM->setMaximumSize(QSize(400, 16777208));
        SELECTTEAM->setFont(font4);
        SELECTTEAM->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(SELECTTEAM);

        CustomSelect = new QComboBox(AlgorithmTab);
        CustomSelect->setObjectName(QString::fromUtf8("CustomSelect"));
        QSizePolicy sizePolicy10(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(CustomSelect->sizePolicy().hasHeightForWidth());
        CustomSelect->setSizePolicy(sizePolicy10);
        CustomSelect->setMaximumSize(QSize(400, 16777208));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Calibri"));
        font10.setPointSize(14);
        CustomSelect->setFont(font10);
        CustomSelect->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        CustomSelect->setMinimumContentsLength(500);
        CustomSelect->setFrame(true);
        CustomSelect->setModelColumn(0);

        verticalLayout_3->addWidget(CustomSelect);

        verticalSpacer_2 = new QSpacerItem(0, 13, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer_2);

        CustomDijkstra = new QPushButton(AlgorithmTab);
        CustomDijkstra->setObjectName(QString::fromUtf8("CustomDijkstra"));
        sizePolicy10.setHeightForWidth(CustomDijkstra->sizePolicy().hasHeightForWidth());
        CustomDijkstra->setSizePolicy(sizePolicy10);
        CustomDijkstra->setMaximumSize(QSize(400, 16777208));
        CustomDijkstra->setFont(font10);

        verticalLayout_3->addWidget(CustomDijkstra);

        verticalSpacer_4 = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer_4);

        CustomDFS = new QPushButton(AlgorithmTab);
        CustomDFS->setObjectName(QString::fromUtf8("CustomDFS"));
        sizePolicy10.setHeightForWidth(CustomDFS->sizePolicy().hasHeightForWidth());
        CustomDFS->setSizePolicy(sizePolicy10);
        CustomDFS->setMaximumSize(QSize(400, 16777208));
        CustomDFS->setFont(font10);

        verticalLayout_3->addWidget(CustomDFS);

        verticalSpacer_6 = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer_6);

        CustomBFS = new QPushButton(AlgorithmTab);
        CustomBFS->setObjectName(QString::fromUtf8("CustomBFS"));
        sizePolicy10.setHeightForWidth(CustomBFS->sizePolicy().hasHeightForWidth());
        CustomBFS->setSizePolicy(sizePolicy10);
        CustomBFS->setMaximumSize(QSize(400, 16777208));
        CustomBFS->setFont(font10);

        verticalLayout_3->addWidget(CustomBFS);

        line = new QFrame(AlgorithmTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        label_3 = new QLabel(AlgorithmTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font8);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        CustomMST = new QPushButton(AlgorithmTab);
        CustomMST->setObjectName(QString::fromUtf8("CustomMST"));
        sizePolicy10.setHeightForWidth(CustomMST->sizePolicy().hasHeightForWidth());
        CustomMST->setSizePolicy(sizePolicy10);
        CustomMST->setMaximumSize(QSize(400, 16777208));
        CustomMST->setFont(font10);

        verticalLayout_3->addWidget(CustomMST);

        verticalSpacer_3 = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        line_2 = new QFrame(AlgorithmTab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        CustomTotal = new QLabel(AlgorithmTab);
        CustomTotal->setObjectName(QString::fromUtf8("CustomTotal"));
        sizePolicy6.setHeightForWidth(CustomTotal->sizePolicy().hasHeightForWidth());
        CustomTotal->setSizePolicy(sizePolicy6);
        CustomTotal->setMaximumSize(QSize(400, 16777208));
        CustomTotal->setFont(font8);

        verticalLayout_3->addWidget(CustomTotal);


        horizontalLayout_6->addLayout(verticalLayout_3);

        CustomTable = new QTableWidget(AlgorithmTab);
        CustomTable->setObjectName(QString::fromUtf8("CustomTable"));
        CustomTable->setFont(font6);

        horizontalLayout_6->addWidget(CustomTable);


        horizontalLayout_7->addLayout(horizontalLayout_6);

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
        sizePolicy6.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy6);
        label_2->setMaximumSize(QSize(300, 16777215));
        label_2->setFont(font8);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        SelectTeam = new QComboBox(Admin);
        SelectTeam->setObjectName(QString::fromUtf8("SelectTeam"));
        sizePolicy10.setHeightForWidth(SelectTeam->sizePolicy().hasHeightForWidth());
        SelectTeam->setSizePolicy(sizePolicy10);
        SelectTeam->setMaximumSize(QSize(300, 16777215));
        SelectTeam->setFont(font6);

        verticalLayout_2->addWidget(SelectTeam);

        verticalSpacer = new QSpacerItem(300, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        AddSouv = new QPushButton(Admin);
        AddSouv->setObjectName(QString::fromUtf8("AddSouv"));
        AddSouv->setFont(font6);

        verticalLayout_2->addWidget(AddSouv);

        DeleteSouv = new QPushButton(Admin);
        DeleteSouv->setObjectName(QString::fromUtf8("DeleteSouv"));
        DeleteSouv->setFont(font6);

        verticalLayout_2->addWidget(DeleteSouv);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        LV_Button = new QPushButton(Admin);
        LV_Button->setObjectName(QString::fromUtf8("LV_Button"));
        QSizePolicy sizePolicy11(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(LV_Button->sizePolicy().hasHeightForWidth());
        LV_Button->setSizePolicy(sizePolicy11);
        LV_Button->setMaximumSize(QSize(16777215, 28));

        verticalLayout_2->addWidget(LV_Button);

        reset = new QPushButton(Admin);
        reset->setObjectName(QString::fromUtf8("reset"));

        verticalLayout_2->addWidget(reset);


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
        menubar->setGeometry(QRect(0, 0, 1137, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        UsersTabs->setCurrentIndex(0);
        MainPageTabs->setCurrentIndex(2);
        PlanTripStacked->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "Admin Login", nullptr));
        WelcomePage->setText(QString());
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
        InfoLogo->setText(QString());
        MainPageTabs->setTabText(MainPageTabs->indexOf(TeamInfoTab), QCoreApplication::translate("MainWindow", "Team Information", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Trip Planner", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Select a Team to start at", nullptr));
        TeamLogo->setText(QCoreApplication::translate("MainWindow", "[PICTURE OF EACH TEAM LOGO??]", nullptr));
        PlanTripButton->setText(QCoreApplication::translate("MainWindow", "Plan Trip", nullptr));
        PlanTripDijkstra->setText(QCoreApplication::translate("MainWindow", "Plan Trip using Dijkstra", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Custom Trip Planner", nullptr));
#if QT_CONFIG(tooltip)
        CustomTripSelect->setToolTip(QCoreApplication::translate("MainWindow", "Double Click the team you want to add to your trip!", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("MainWindow", "Teams in order to visit", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Select the Teams/Stadiums", nullptr));
#if QT_CONFIG(tooltip)
        CustomTripSELECTED->setToolTip(QCoreApplication::translate("MainWindow", "Double Click the team you want to add to your trip!", nullptr));
#endif // QT_CONFIG(tooltip)
        ResetTrip->setText(QCoreApplication::translate("MainWindow", "Reset Custom Trip", nullptr));
        PlanCustomTripButton->setText(QCoreApplication::translate("MainWindow", "Plan Custom  Trip", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Stadiums in order.", nullptr));
        DistanceTravelled->setText(QCoreApplication::translate("MainWindow", "Total Distance Travelled: ", nullptr));
        TotalCost->setText(QCoreApplication::translate("MainWindow", "Total Cost: ", nullptr));
        CompleteTrip->setText(QCoreApplication::translate("MainWindow", "Complete Trip", nullptr));
        PrevStadium->setText(QCoreApplication::translate("MainWindow", "Previous Stadium", nullptr));
        NextStadium->setText(QCoreApplication::translate("MainWindow", "Next Stadium", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "[PICTURE?]", nullptr));
        BuyHeader->setText(QCoreApplication::translate("MainWindow", "Stadium's Souvenirs", nullptr));
        ResetSouvenir->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        BuySouvenir->setText(QCoreApplication::translate("MainWindow", "Buy", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(PlanTripTab), QCoreApplication::translate("MainWindow", "Plan Trip", nullptr));
        SELECTTEAM->setText(QCoreApplication::translate("MainWindow", "Select a Team/Stadium", nullptr));
        CustomDijkstra->setText(QCoreApplication::translate("MainWindow", "Run Dijkstra", nullptr));
        CustomDFS->setText(QCoreApplication::translate("MainWindow", "Run DFS", nullptr));
        CustomBFS->setText(QCoreApplication::translate("MainWindow", "Run BFS", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Run MST on Graph", nullptr));
        CustomMST->setText(QCoreApplication::translate("MainWindow", "Run Prim MST", nullptr));
        CustomTotal->setText(QCoreApplication::translate("MainWindow", "Total Mileage: ", nullptr));
        MainPageTabs->setTabText(MainPageTabs->indexOf(AlgorithmTab), QCoreApplication::translate("MainWindow", "Algorithm Test", nullptr));
        UsersTabs->setTabText(UsersTabs->indexOf(MainPage), QCoreApplication::translate("MainWindow", "Main Page", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select a Team to modify", nullptr));
        AddSouv->setText(QCoreApplication::translate("MainWindow", "Add Souvenir", nullptr));
        DeleteSouv->setText(QCoreApplication::translate("MainWindow", "Delete Selected Souvenir", nullptr));
        LV_Button->setText(QCoreApplication::translate("MainWindow", "Add Las Vegas Expansion", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        UsersTabs->setTabText(UsersTabs->indexOf(Admin), QCoreApplication::translate("MainWindow", "Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
