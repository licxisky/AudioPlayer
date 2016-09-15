/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QSlider *horizontalSlider;
    QToolButton *toolButton_last;
    QToolButton *toolButton_play_pause;
    QToolButton *toolButton_stop;
    QToolButton *toolButton_next;
    QTableWidget *tableWidget;
    QToolButton *toolButton_close;
    QToolButton *toolButton_min;
    QToolButton *toolButton_add;
    QToolButton *toolButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 400, 400));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/images/bg3.png);"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(0, 395, 400, 5));
        horizontalSlider->setOrientation(Qt::Horizontal);
        toolButton_last = new QToolButton(centralWidget);
        toolButton_last->setObjectName(QStringLiteral("toolButton_last"));
        toolButton_last->setGeometry(QRect(120, 350, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_last->setIcon(icon);
        toolButton_last->setAutoRaise(true);
        toolButton_play_pause = new QToolButton(centralWidget);
        toolButton_play_pause->setObjectName(QStringLiteral("toolButton_play_pause"));
        toolButton_play_pause->setGeometry(QRect(160, 350, 40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/3.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_play_pause->setIcon(icon1);
        toolButton_play_pause->setAutoRaise(true);
        toolButton_stop = new QToolButton(centralWidget);
        toolButton_stop->setObjectName(QStringLiteral("toolButton_stop"));
        toolButton_stop->setGeometry(QRect(200, 350, 40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_stop->setIcon(icon2);
        toolButton_stop->setAutoRaise(true);
        toolButton_next = new QToolButton(centralWidget);
        toolButton_next->setObjectName(QStringLiteral("toolButton_next"));
        toolButton_next->setGeometry(QRect(240, 350, 40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_next->setIcon(icon3);
        toolButton_next->setAutoRaise(true);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(400, 30, 200, 371));
        tableWidget->setAutoFillBackground(true);
        tableWidget->setStyleSheet(QLatin1String("QHeaderView::section {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                      stop:0 #616161, stop: 0.5 #505050,\n"
"                                      stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
"QHeaderView::section:checked\n"
"{\n"
"    background-color: blue;\n"
"}\n"
"\n"
"\n"
""));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setColumnCount(3);
        toolButton_close = new QToolButton(centralWidget);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setGeometry(QRect(570, 0, 30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/action_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_close->setIcon(icon4);
        toolButton_close->setAutoRaise(true);
        toolButton_min = new QToolButton(centralWidget);
        toolButton_min->setObjectName(QStringLiteral("toolButton_min"));
        toolButton_min->setGeometry(QRect(540, 0, 30, 30));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/action_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_min->setIcon(icon5);
        toolButton_min->setAutoRaise(true);
        toolButton_add = new QToolButton(centralWidget);
        toolButton_add->setObjectName(QStringLiteral("toolButton_add"));
        toolButton_add->setGeometry(QRect(510, 0, 30, 30));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/action_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_add->setIcon(icon6);
        toolButton_add->setAutoRaise(true);
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(480, 0, 30, 30));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon7);
        toolButton->setAutoRaise(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        toolButton_last->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_play_pause->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_stop->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_next->setText(QApplication::translate("MainWindow", "...", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\255\214\346\233\262", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\347\261\273\345\236\213", 0));
        toolButton_close->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_min->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_add->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
