/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Nov 15 09:45:14 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionA;
    QAction *actionIDA_2;
    QAction *actionNone;
    QAction *actionManhattan_Distance_2;
    QWidget *centralWidget;
    QLineEdit *input;
    QTextBrowser *output;
    QPushButton *solve;
    QComboBox *algotype;
    QComboBox *htype;
    QPushButton *refresh;
    QLabel *algolabel;
    QLabel *hlabel;
    QLabel *pic_label;
    QLabel *movestext;
    QLabel *no_moves;
    QLabel *time_text;
    QLabel *time;
    QLabel *blank;
    QLabel *a6;
    QLabel *a8;
    QLabel *a1;
    QLabel *a2;
    QLabel *a5;
    QLabel *a4;
    QLabel *a7;
    QLabel *a3;
    QPushButton *next;
    QLabel *label;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QFrame *frame;
    QLabel *label_3;
    QMdiArea *mdiArea;
    QPushButton *shuffle;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuAlgorithm;
    QMenu *menuHueristic_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(482, 522);
        MainWindow->setAnimated(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionA = new QAction(MainWindow);
        actionA->setObjectName(QString::fromUtf8("actionA"));
        actionIDA_2 = new QAction(MainWindow);
        actionIDA_2->setObjectName(QString::fromUtf8("actionIDA_2"));
        actionNone = new QAction(MainWindow);
        actionNone->setObjectName(QString::fromUtf8("actionNone"));
        actionManhattan_Distance_2 = new QAction(MainWindow);
        actionManhattan_Distance_2->setObjectName(QString::fromUtf8("actionManhattan_Distance_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        input = new QLineEdit(centralWidget);
        input->setObjectName(QString::fromUtf8("input"));
        input->setGeometry(QRect(20, 10, 181, 21));
        input->setAutoFillBackground(true);
        input->setMaxLength(19);
        output = new QTextBrowser(centralWidget);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(219, 150, 211, 161));
        solve = new QPushButton(centralWidget);
        solve->setObjectName(QString::fromUtf8("solve"));
        solve->setGeometry(QRect(210, 10, 61, 21));
        QFont font;
        font.setStrikeOut(false);
        solve->setFont(font);
        solve->setCheckable(false);
        solve->setAutoDefault(true);
        solve->setDefault(false);
        solve->setFlat(false);
        algotype = new QComboBox(centralWidget);
        algotype->setObjectName(QString::fromUtf8("algotype"));
        algotype->setGeometry(QRect(210, 48, 211, 27));
        htype = new QComboBox(centralWidget);
        htype->setObjectName(QString::fromUtf8("htype"));
        htype->setGeometry(QRect(210, 78, 211, 27));
        refresh = new QPushButton(centralWidget);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setGeometry(QRect(280, 10, 71, 21));
        refresh->setFont(font);
        refresh->setCheckable(false);
        refresh->setAutoDefault(true);
        refresh->setDefault(false);
        refresh->setFlat(false);
        algolabel = new QLabel(centralWidget);
        algolabel->setObjectName(QString::fromUtf8("algolabel"));
        algolabel->setGeometry(QRect(135, 50, 81, 21));
        hlabel = new QLabel(centralWidget);
        hlabel->setObjectName(QString::fromUtf8("hlabel"));
        hlabel->setGeometry(QRect(135, 80, 81, 21));
        pic_label = new QLabel(centralWidget);
        pic_label->setObjectName(QString::fromUtf8("pic_label"));
        pic_label->setGeometry(QRect(20, 40, 75, 75));
        pic_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/p.png")));
        movestext = new QLabel(centralWidget);
        movestext->setObjectName(QString::fromUtf8("movestext"));
        movestext->setGeometry(QRect(230, 345, 141, 21));
        QFont font1;
        font1.setPointSize(12);
        movestext->setFont(font1);
        no_moves = new QLabel(centralWidget);
        no_moves->setObjectName(QString::fromUtf8("no_moves"));
        no_moves->setGeometry(QRect(350, 340, 71, 31));
        no_moves->setFont(font1);
        time_text = new QLabel(centralWidget);
        time_text->setObjectName(QString::fromUtf8("time_text"));
        time_text->setGeometry(QRect(230, 365, 151, 21));
        time_text->setFont(font1);
        time = new QLabel(centralWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(350, 360, 71, 31));
        time->setFont(font1);
        blank = new QLabel(centralWidget);
        blank->setObjectName(QString::fromUtf8("blank"));
        blank->setGeometry(QRect(140, 250, 60, 60));
        blank->setMaximumSize(QSize(60, 60));
        blank->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/9.png")));
        a6 = new QLabel(centralWidget);
        a6->setObjectName(QString::fromUtf8("a6"));
        a6->setGeometry(QRect(140, 190, 60, 60));
        a6->setMaximumSize(QSize(60, 60));
        a6->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/6.png")));
        a8 = new QLabel(centralWidget);
        a8->setObjectName(QString::fromUtf8("a8"));
        a8->setGeometry(QRect(80, 250, 60, 60));
        a8->setMaximumSize(QSize(60, 60));
        a8->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/8.png")));
        a1 = new QLabel(centralWidget);
        a1->setObjectName(QString::fromUtf8("a1"));
        a1->setGeometry(QRect(20, 130, 60, 60));
        a1->setMaximumSize(QSize(60, 60));
        a1->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/1.png")));
        a2 = new QLabel(centralWidget);
        a2->setObjectName(QString::fromUtf8("a2"));
        a2->setGeometry(QRect(80, 130, 60, 60));
        a2->setMaximumSize(QSize(60, 60));
        a2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/2.png")));
        a5 = new QLabel(centralWidget);
        a5->setObjectName(QString::fromUtf8("a5"));
        a5->setGeometry(QRect(80, 190, 60, 60));
        a5->setMaximumSize(QSize(60, 60));
        a5->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/5.png")));
        a4 = new QLabel(centralWidget);
        a4->setObjectName(QString::fromUtf8("a4"));
        a4->setGeometry(QRect(20, 190, 60, 60));
        a4->setMaximumSize(QSize(60, 60));
        a4->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/4.png")));
        a7 = new QLabel(centralWidget);
        a7->setObjectName(QString::fromUtf8("a7"));
        a7->setGeometry(QRect(20, 250, 60, 60));
        a7->setMaximumSize(QSize(60, 60));
        a7->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/7.png")));
        a3 = new QLabel(centralWidget);
        a3->setObjectName(QString::fromUtf8("a3"));
        a3->setGeometry(QRect(140, 130, 60, 60));
        a3->setMaximumSize(QSize(60, 60));
        a3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Images/3.png")));
        next = new QPushButton(centralWidget);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(50, 320, 114, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 130, 180, 180));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Black Background.png")));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(220, 320, 211, 71));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(120, 40, 311, 75));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(34, 369, 161, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier"));
        font2.setPointSize(11);
        label_2->setFont(font2);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 366, 181, 21));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 132, 111, 16));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(219, 130, 211, 21));
        shuffle = new QPushButton(centralWidget);
        shuffle->setObjectName(QString::fromUtf8("shuffle"));
        shuffle->setGeometry(QRect(360, 10, 71, 21));
        shuffle->setFont(font);
        shuffle->setCheckable(false);
        shuffle->setAutoDefault(true);
        shuffle->setDefault(false);
        shuffle->setFlat(false);
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        groupBox_2->raise();
        output->raise();
        mdiArea->raise();
        label_2->raise();
        groupBox->raise();
        label->raise();
        input->raise();
        solve->raise();
        algotype->raise();
        htype->raise();
        refresh->raise();
        algolabel->raise();
        hlabel->raise();
        pic_label->raise();
        movestext->raise();
        no_moves->raise();
        time_text->raise();
        time->raise();
        blank->raise();
        a6->raise();
        a8->raise();
        a1->raise();
        a2->raise();
        a5->raise();
        a4->raise();
        a7->raise();
        a3->raise();
        next->raise();
        label_3->raise();
        shuffle->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 482, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuAlgorithm = new QMenu(menuOptions);
        menuAlgorithm->setObjectName(QString::fromUtf8("menuAlgorithm"));
        menuHueristic_2 = new QMenu(menuOptions);
        menuHueristic_2->setObjectName(QString::fromUtf8("menuHueristic_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionExit);
        menuOptions->addAction(menuAlgorithm->menuAction());
        menuOptions->addAction(menuHueristic_2->menuAction());
        menuAlgorithm->addAction(actionA);
        menuAlgorithm->addAction(actionIDA_2);
        menuHueristic_2->addAction(actionNone);
        menuHueristic_2->addAction(actionManhattan_Distance_2);

        retranslateUi(MainWindow);
        QObject::connect(a8, SIGNAL(customContextMenuRequested(QPoint)), blank, SLOT(showFullScreen()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q, Esc", 0, QApplication::UnicodeUTF8));
        actionA->setText(QApplication::translate("MainWindow", "A*", 0, QApplication::UnicodeUTF8));
        actionIDA_2->setText(QApplication::translate("MainWindow", "IDA*", 0, QApplication::UnicodeUTF8));
        actionNone->setText(QApplication::translate("MainWindow", "None", 0, QApplication::UnicodeUTF8));
        actionManhattan_Distance_2->setText(QApplication::translate("MainWindow", "Manhattan Distance", 0, QApplication::UnicodeUTF8));
        solve->setText(QApplication::translate("MainWindow", "Solve", 0, QApplication::UnicodeUTF8));
        algotype->clear();
        algotype->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "IDA*", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "A*", 0, QApplication::UnicodeUTF8)
        );
        htype->clear();
        htype->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Manhattan Distance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Number of Misplaced Tiles", 0, QApplication::UnicodeUTF8)
        );
        refresh->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        algolabel->setText(QApplication::translate("MainWindow", "Algorithm", 0, QApplication::UnicodeUTF8));
        hlabel->setText(QApplication::translate("MainWindow", "Heuristic", 0, QApplication::UnicodeUTF8));
        pic_label->setText(QString());
        movestext->setText(QApplication::translate("MainWindow", "Number of moves :", 0, QApplication::UnicodeUTF8));
        no_moves->setText(QString());
        time_text->setText(QApplication::translate("MainWindow", "Time Taken (ms) :", 0, QApplication::UnicodeUTF8));
        time->setText(QString());
        blank->setText(QString());
        a6->setText(QString());
        a8->setText(QString());
        a1->setText(QString());
        a2->setText(QString());
        a5->setText(QString());
        a4->setText(QString());
        a7->setText(QString());
        a3->setText(QString());
        next->setText(QApplication::translate("MainWindow", "Next Move", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Output Characteristics", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "By Devendra and Priyank", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Solution Steps", 0, QApplication::UnicodeUTF8));
        shuffle->setText(QApplication::translate("MainWindow", "Shuffle", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        menuAlgorithm->setTitle(QApplication::translate("MainWindow", "Algorithm", 0, QApplication::UnicodeUTF8));
        menuHueristic_2->setTitle(QApplication::translate("MainWindow", "Hueristic", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
