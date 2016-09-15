/********************************************************************************
** Form generated from reading UI file 'dialog_search.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SEARCH_H
#define UI_DIALOG_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_search
{
public:
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QTableWidget *tableWidget;
    QProgressBar *progressBar;

    void setupUi(QDialog *Dialog_search)
    {
        if (Dialog_search->objectName().isEmpty())
            Dialog_search->setObjectName(QStringLiteral("Dialog_search"));
        Dialog_search->resize(400, 369);
        lineEdit = new QLineEdit(Dialog_search);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(29, 10, 331, 30));
        toolButton = new QToolButton(Dialog_search);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(330, 10, 31, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setAutoRaise(true);
        tableWidget = new QTableWidget(Dialog_search);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 50, 331, 211));
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setStyleSheet(QLatin1String("QHeaderView::section {\n"
"	\n"
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
"    background-color: grean;\n"
"}\n"
"\n"
""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setColumnCount(10);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        progressBar = new QProgressBar(Dialog_search);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 300, 331, 23));
        progressBar->setValue(24);

        retranslateUi(Dialog_search);

        QMetaObject::connectSlotsByName(Dialog_search);
    } // setupUi

    void retranslateUi(QDialog *Dialog_search)
    {
        Dialog_search->setWindowTitle(QApplication::translate("Dialog_search", "Dialog", 0));
        toolButton->setText(QApplication::translate("Dialog_search", "...", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog_search", "\346\255\214\346\233\262", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog_search", "\346\255\214\346\211\213", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_search: public Ui_Dialog_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SEARCH_H
