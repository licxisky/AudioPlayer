#include "gethtml.h"
#include <QtCore>

GetHtml::GetHtml()
{

}

QString GetHtml::geturl(QString url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));
    QString responseData;
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    k = responseData = QString::fromUtf8(reply->readAll());
    return responseData;
}

QString GetHtml::makeurl(QString keyboard, int page, int pagesize)
{
    QByteArray encoded = keyboard.toUtf8().toPercentEncoding();
    return "http://mobilecdn.kugou.com/api/v3/search/song?format=jsonp&keyword="+encoded
            +"&page="+QString::number(page)
            +"&pagesize="+QString::number(pagesize)
            +"&showtype=1";

}

void GetHtml::gethash(QString &html)
{
    html = html.mid(html.indexOf("\"info\":")+9);
    html.remove(html.size()-2, 2);
    QStringList listall = html.split("},{");
    for(int i = 0;i<listall.size();i++)
    {
        QString QStemp = listall[i];
        int pos = QStemp.indexOf("\"songname\":\"");
        QString songname = QStemp.mid(pos+12, QStemp.indexOf("\"",pos+12)-pos-12);
        pos = QStemp.indexOf("\"singername\":\"");
        QString singername = QStemp.mid(pos+14, QStemp.indexOf("\"",pos+14)-pos-14);
        pos = QStemp.indexOf("\"hash\":\"");
        QString hash = QStemp.mid(pos+8, QStemp.indexOf("\"",pos+8)-pos-8);
        MusicInfo temp;
        temp.songname = songname;
        temp.songer = singername;
        temp.hash = hash;
        music_info<<temp;
    }
}

void GetHtml::getmp3(QString hash, QString songname)
{
    QString mp3json = geturl("http://m.kugou.com/app/i/getSongInfo.php?hash="+hash+"&cmd=playInfo");
    int pos = mp3json.indexOf("\"url\":\"");
    QString mp3url = mp3json.mid(pos+7,mp3json.indexOf("\"",pos+7)-7-pos);
    mp3url = mp3url.replace("\\/","/");
//    QString mp3 = geturl(mp3url);
//    filewrite(QString::fromLocal8Bit("H:\\迅雷下载\\")+songname+".mp3", mp3);
    QUrl url(mp3url);
    fileInfo= url.path();
    file=new QFile(fileInfo.fileName());
    file->open(QIODevice::WriteOnly);
    accessManager=new QNetworkAccessManager();
    request.setUrl(url);
    reply=accessManager->get(request);
    connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT( onDownloadProgress(qint64 ,qint64 )));
    connect((QObject*)reply, SIGNAL(readyRead()),this, SLOT(onReadyRead()));
    progressBar->setValue(0);
}

bool GetHtml::filewrite(QString filename, QString &filecontent)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_7);
    out << filecontent << endl;
    file.close();
    return true;
}


