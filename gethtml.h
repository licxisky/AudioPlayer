#ifndef GETHTML_H
#define GETHTML_H

#include <QtNetwork/QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QProgressBar>

typedef struct C_info
{
    QString songname;
    QString songer;
    QString hash;
    QString mp3url;
}MusicInfo;

#include <QObject>

class GetHtml: public QObject
{
public:
    QList<MusicInfo> music_info;
    QString k;
    QFile *file;
        QFileInfo fileInfo;
        QNetworkAccessManager *accessManager;
        QNetworkRequest request;
        QNetworkReply *reply;
        QProgressBar *progressBar;

    GetHtml();
    QString geturl(QString);
    QString makeurl(QString, int = 1, int = 10);
    void gethash(QString&);
    void getmp3(QString hash, QString songname);
    bool filewrite(QString, QString&);
public slots:
    void replyFinished(QNetworkReply *reply);
    void onReadyRead();
    void onDownloadProgress(qint64 bytesSent,qint64 bytesTotal);
};

#endif // GETHTML_H
