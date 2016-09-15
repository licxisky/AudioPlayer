#include "dialog_search.h"
#include "ui_dialog_search.h"

Dialog_search::Dialog_search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_search)
{
    ui->setupUi(this);

    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(getinfo()));
    setTableWidget();
    ui->progressBar->setValue(0);


}

Dialog_search::~Dialog_search()
{
    delete ui;
}

void Dialog_search::getinfo()
{
    g_html = new GetHtml();
    keyboard = ui->lineEdit->text();

    if(keyboard != "")
    {
        g_html->gethash(g_html->geturl(g_html->makeurl(keyboard)));
        for(int i = 0; i < g_html->music_info.size(); i++)
        {
            ui->tableWidget->setRowCount(i+1);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(g_html->music_info[i].songname));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(g_html->music_info[i].songer));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(g_html->music_info[i].hash));

            QToolButton *toolbutton_1 = new QToolButton();
            QToolButton *toolbutton_2 = new QToolButton();

            toolbutton_1->setIcon(QIcon(":/images/download.png"));
            toolbutton_2->setIcon(QIcon(":/images/folder_open.png"));

            toolbutton_1->setAutoRaise(true);
            toolbutton_2->setAutoRaise(true);

            ui->tableWidget->setCellWidget(i,2,toolbutton_1);
            ui->tableWidget->setCellWidget(i,3,toolbutton_2);

            switch(i)
            {
                case 0:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_0()));break;
                case 1:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_1()));break;
                case 2:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_2()));break;
                case 3:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_3()));break;
                case 4:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_4()));break;
                case 5:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_5()));break;
                case 6:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_6()));break;
                case 7:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_7()));break;
                case 8:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_8()));break;
                case 9:connect(toolbutton_1, SIGNAL(clicked()), this, SLOT(onclicked_9()));break;
            }

        }
    }
}

void Dialog_search::setTableWidget()
{
    ui->tableWidget->horizontalHeader()->resizeSection(0,135);
    ui->tableWidget->horizontalHeader()->resizeSection(1,136);
    ui->tableWidget->horizontalHeader()->resizeSection(2,30);
    ui->tableWidget->horizontalHeader()->resizeSection(3,30);
    ui->tableWidget->setColumnHidden(4,true);
}

void Dialog_search::httpDownload(int row)
{

    if(httpRequestAbort == true) return;
    httpRequestAbort = true;
    QString mp3json = g_html->geturl("http://m.kugou.com/app/i/getSongInfo.php?hash="+ui->tableWidget->item(row, 4)->text()+"&cmd=playInfo");
    int pos = mp3json.indexOf("\"url\":\"");
    QString mp3url = mp3json.mid(pos+7,mp3json.indexOf("\"",pos+7)-7-pos);
    mp3url = mp3url.replace("\\/","/");
    QUrl url(mp3url);
    fileInfo= url.path();
    file=new QFile(/*fileInfo.fileName()*/QString::fromLocal8Bit("H:\\音乐\\")+ui->tableWidget->item(row, 1)->text()+" - "+ui->tableWidget->item(row, 0)->text()+".mp3");
    file->open(QIODevice::WriteOnly);//只读方式打开文件
    accessManager=new QNetworkAccessManager(this);
    request.setUrl(url);
    reply=accessManager->get(request);//通过发送数据，返回值保存在reply指针里.
    connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));//finish为manager自带的信号，replyFinished是自定义的
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT( onDownloadProgress(qint64 ,qint64 )));//download文件时进度
    connect((QObject *)reply, SIGNAL(readyRead()),this, SLOT(onReadyRead()));
    ui->progressBar->setValue(0);
}

void Dialog_search::replyFinished(QNetworkReply *reply)
{
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    QByteArray bytes = reply->readAll();  //获取字节
    QString result(bytes);  //转化为字符串
    qDebug()<<result;

    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
      //download_Btn->setText("success");
      QByteArray bytes = reply->readAll();  //获取字节
      QString result(bytes);  //转化为字符串

      qDebug()<<result;
    }
    else
    {
      //处理错误
       //download_Btn->setText("failed");
    }

    reply->deleteLater();//要删除reply，但是不能在repyfinished里直接delete，要调用deletelater;
    httpRequestAbort = false;
}

void Dialog_search::onDownloadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    ui->progressBar->setMaximum(bytesTotal);
    ui->progressBar->setValue(bytesSent);
}

void Dialog_search::onReadyRead()
{
    file->write(reply->readAll());
}

void Dialog_search::stop()
{
    if(!httpRequestAbort)
    {
        reply->abort();//响应终止
        httpRequestAbort=true;
    }
    else
    {
        //httpDownload();
        httpRequestAbort=false;
    }
}

void Dialog_search::onclicked_0()
{
    httpDownload(0);
}
void Dialog_search::onclicked_1()
{
    httpDownload(1);
}
void Dialog_search::onclicked_2()
{
    httpDownload(2);
}
void Dialog_search::onclicked_3()
{
    httpDownload(3);
}
void Dialog_search::onclicked_4()
{
    httpDownload(4);
}
void Dialog_search::onclicked_5()
{
    httpDownload(5);
}
void Dialog_search::onclicked_6()
{
    httpDownload(6);
}
void Dialog_search::onclicked_7()
{
    httpDownload(7);
}
void Dialog_search::onclicked_8()
{
    httpDownload(8);
}
void Dialog_search::onclicked_9()
{
    httpDownload(9);
}









