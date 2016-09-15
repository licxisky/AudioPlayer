#ifndef DIALOG_SEARCH_H
#define DIALOG_SEARCH_H

#include <QDialog>
#include "gethtml.h"
#include <QTableWidget>
#include <QToolButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QFile>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIODevice>
#include <QFileInfo>
#include <QProgressBar>
#include <QList>

namespace Ui {
class Dialog_search;
}

class Dialog_search : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_search(QWidget *parent = 0);
    ~Dialog_search();

private:
    Ui::Dialog_search *ui;
    QString keyboard;
    GetHtml *g_html;

    QFile *file;
    QFileInfo fileInfo;
    QNetworkAccessManager *accessManager;
    QNetworkRequest request;
    QNetworkReply *reply;
    bool httpRequestAbort; //请求停止的标志位,false表示允许请求

public slots:
    void getinfo();
    void setTableWidget();

protected slots:
    void httpDownload(int);
    void replyFinished(QNetworkReply*reply);
    void onDownloadProgress(qint64 bytesSent,qint64 bytesTotal);
    void onReadyRead();//
    void stop();//暂停，重新下载

    void onclicked_0();
    void onclicked_1();
    void onclicked_2();
    void onclicked_3();
    void onclicked_4();
    void onclicked_5();
    void onclicked_6();
    void onclicked_7();
    void onclicked_8();
    void onclicked_9();



};

#endif // DIALOG_SEARCH_H
