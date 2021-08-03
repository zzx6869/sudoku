/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *new_2;
    QAction *recall;
    QAction *quit;
    QAction *help;
    QAction *rule;
    QAction *easy;
    QAction *simple;
    QAction *hard;
    QWidget *sukodu;
    QLabel *label;
    QTableWidget *table;
    QPushButton *newgame;
    QPushButton *recall_2;
    QPushButton *user_defined;
    QPushButton *exit;
    QPushButton *answer;
    QPushButton *save;
    QPushButton *confirm;
    QPushButton *tip;
    QPushButton *clear;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *difficulty;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8("kleesweet.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/prefix1/kleesweet.jpg"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        new_2 = new QAction(MainWindow);
        new_2->setObjectName(QString::fromUtf8("new_2"));
        recall = new QAction(MainWindow);
        recall->setObjectName(QString::fromUtf8("recall"));
        quit = new QAction(MainWindow);
        quit->setObjectName(QString::fromUtf8("quit"));
        help = new QAction(MainWindow);
        help->setObjectName(QString::fromUtf8("help"));
        rule = new QAction(MainWindow);
        rule->setObjectName(QString::fromUtf8("rule"));
        easy = new QAction(MainWindow);
        easy->setObjectName(QString::fromUtf8("easy"));
        simple = new QAction(MainWindow);
        simple->setObjectName(QString::fromUtf8("simple"));
        hard = new QAction(MainWindow);
        hard->setObjectName(QString::fromUtf8("hard"));
        sukodu = new QWidget(MainWindow);
        sukodu->setObjectName(QString::fromUtf8("sukodu"));
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        sukodu->setFont(font);
        sukodu->setStyleSheet(QString::fromUtf8("#sukodu{border-image: url(:/new/prefix1/-254474a4c1f0d915.jpg);}"));
        label = new QLabel(sukodu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 791, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AcadEref"));
        font1.setPointSize(20);
        font1.setUnderline(false);
        label->setFont(font1);
        table = new QTableWidget(sukodu);
        if (table->columnCount() < 9)
            table->setColumnCount(9);
        if (table->rowCount() < 9)
            table->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, 8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 7, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        table->setItem(1, 8, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 6, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 7, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        table->setItem(2, 8, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 4, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 5, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 6, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 7, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignCenter);
        table->setItem(3, 8, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 4, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 5, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 6, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 7, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setTextAlignment(Qt::AlignCenter);
        table->setItem(4, 8, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 1, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 2, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 3, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 4, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 5, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 6, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 7, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setTextAlignment(Qt::AlignCenter);
        table->setItem(5, 8, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 2, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 3, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 4, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 5, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 6, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 7, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setTextAlignment(Qt::AlignCenter);
        table->setItem(6, 8, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 0, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 1, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 2, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 3, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 4, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        __qtablewidgetitem68->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 5, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        __qtablewidgetitem69->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 6, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        __qtablewidgetitem70->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 7, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        __qtablewidgetitem71->setTextAlignment(Qt::AlignCenter);
        table->setItem(7, 8, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        __qtablewidgetitem74->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        __qtablewidgetitem75->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 3, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        __qtablewidgetitem76->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 4, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 5, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 6, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        __qtablewidgetitem79->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 7, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setTextAlignment(Qt::AlignCenter);
        table->setItem(8, 8, __qtablewidgetitem80);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(80, 200, 361, 361));
        table->setMouseTracking(true);
        table->setContextMenuPolicy(Qt::DefaultContextMenu);
        table->setLayoutDirection(Qt::LeftToRight);
        table->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.8);\n"
"border:none;"));
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table->setAutoScroll(true);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setTabKeyNavigation(true);
        table->setProperty("showDropIndicator", QVariant(true));
        table->setDragDropOverwriteMode(true);
        table->setAlternatingRowColors(false);
        table->setTextElideMode(Qt::ElideRight);
        table->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setShowGrid(true);
        table->setCornerButtonEnabled(true);
        table->setRowCount(9);
        table->setColumnCount(9);
        table->horizontalHeader()->setVisible(false);
        table->horizontalHeader()->setMinimumSectionSize(40);
        table->horizontalHeader()->setDefaultSectionSize(40);
        table->horizontalHeader()->setHighlightSections(true);
        table->verticalHeader()->setVisible(false);
        table->verticalHeader()->setMinimumSectionSize(40);
        table->verticalHeader()->setDefaultSectionSize(40);
        newgame = new QPushButton(sukodu);
        newgame->setObjectName(QString::fromUtf8("newgame"));
        newgame->setGeometry(QRect(730, 160, 200, 80));
        newgame->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        newgame->setAutoDefault(false);
        newgame->setFlat(false);
        recall_2 = new QPushButton(sukodu);
        recall_2->setObjectName(QString::fromUtf8("recall_2"));
        recall_2->setGeometry(QRect(730, 270, 200, 80));
        recall_2->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        recall_2->setFlat(false);
        user_defined = new QPushButton(sukodu);
        user_defined->setObjectName(QString::fromUtf8("user_defined"));
        user_defined->setGeometry(QRect(730, 380, 200, 80));
        user_defined->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        exit = new QPushButton(sukodu);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(730, 490, 200, 80));
        exit->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        answer = new QPushButton(sukodu);
        answer->setObjectName(QString::fromUtf8("answer"));
        answer->setGeometry(QRect(520, 370, 103, 30));
        answer->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        save = new QPushButton(sukodu);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(520, 440, 103, 30));
        save->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        confirm = new QPushButton(sukodu);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(520, 510, 103, 30));
        confirm->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        tip = new QPushButton(sukodu);
        tip->setObjectName(QString::fromUtf8("tip"));
        tip->setGeometry(QRect(520, 300, 103, 30));
        tip->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        clear = new QPushButton(sukodu);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(520, 230, 103, 30));
        clear->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5);\n"
"border:none;"));
        MainWindow->setCentralWidget(sukodu);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        difficulty = new QMenu(menu);
        difficulty->setObjectName(QString::fromUtf8("difficulty"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(rule);
        menu->addAction(difficulty->menuAction());
        difficulty->addSeparator();
        difficulty->addAction(easy);
        difficulty->addAction(simple);
        difficulty->addAction(hard);

        retranslateUi(MainWindow);

        newgame->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        new_2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\347\232\204\345\274\200\345\247\213", nullptr));
        recall->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\255\230\346\241\243", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        help->setText(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        rule->setText(QCoreApplication::translate("MainWindow", "\350\247\204\345\210\231", nullptr));
        easy->setText(QCoreApplication::translate("MainWindow", "\347\256\200\345\215\225", nullptr));
        simple->setText(QCoreApplication::translate("MainWindow", "\346\231\256\351\200\232", nullptr));
        hard->setText(QCoreApplication::translate("MainWindow", "\345\233\260\351\232\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "                \346\254\242\350\277\216\346\235\245\345\210\260\345\260\217\351\273\257\346\210\230\344\270\277\347\232\204\346\225\260\347\213\254", nullptr));

        const bool __sortingEnabled = table->isSortingEnabled();
        table->setSortingEnabled(false);
        table->setSortingEnabled(__sortingEnabled);

        newgame->setText(QCoreApplication::translate("MainWindow", "\346\226\260\347\232\204\345\274\200\345\247\213", nullptr));
        recall_2->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\255\230\346\241\243", nullptr));
        user_defined->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\225\260\347\213\254", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        answer->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\255\224\346\241\210", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        confirm->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        tip->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        difficulty->setTitle(QCoreApplication::translate("MainWindow", "\351\232\276\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
