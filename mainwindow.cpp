#include <QtWidgets>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建windows窗口，去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置窗口头透明
    this->setAttribute(Qt::WA_TranslucentBackground);
    //创建托盘区图标
    createSystemTrayIcon();

    setTableWidget();

    ui->horizontalSlider->setRange(0,0);
    volume = 80;

    playList=new QMediaPlaylist;
    playList->setPlaybackMode(QMediaPlaylist::Loop);//循环

    player=new QMediaPlayer;
    player->setPlaylist(playList);

    player->setVolume(volume);

    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(SH()));
    connect(ui->toolButton_add, SIGNAL(clicked()), this, SLOT(importSongs()));
    connect(ui->toolButton_min, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->toolButton_close, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(setPosition(int)));
    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(playTo(int, int)));
    connect(ui->toolButton_last, SIGNAL(clicked()), this, SLOT(Last()));
    connect(ui->toolButton_next, SIGNAL(clicked()), this, SLOT(Next()));
    connect(ui->toolButton_play_pause, SIGNAL(clicked()), this, SLOT(Play_Pause()));
    connect(ui->toolButton_stop, SIGNAL(clicked()), this, SLOT(Stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//导入歌曲
void MainWindow::importSongs()
{
    QString initialName=QDir::homePath();
    QStringList pathList=QFileDialog::getOpenFileNames(this, _G("选择文件"), initialName, _G("MP3文件(*.mp3)"));
    for(int i=0; i<pathList.size(); ++i) {
        QString path=QDir::toNativeSeparators(pathList.at(i));
        if(!path.isEmpty()) {
            playList->addMedia(QUrl::fromLocalFile(path));
            QString fileName=path.split("\\").last();
            int rownum=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rownum);
            ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName.split(".").front()));
            ui->tableWidget->setItem(rownum, 1, new QTableWidgetItem(fileName.split(".").last()));
            ui->tableWidget->setItem(rownum, 2, new QTableWidgetItem(path));
        }
    }
}

//创建托盘区图标
void MainWindow::createSystemTrayIcon()
{
    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(_G(":/images/icon.ico")));
    trayIcon->setToolTip(_G("酷歌音乐播放器"));

    action_restore=new QAction(_G("打开主面板"), this);
    action_play=new QAction(_G("播放"), this);
    action_stop=new QAction(_G("停止"), this);
    action_last=new QAction(_G("上一首"), this);
    action_next=new QAction(_G("下一首"), this);
    action_pause=new QAction(_G("暂停"), this);
    action_quit=new QAction(_G("退出"), this);


    connect(action_restore, SIGNAL(triggered()), this, SLOT(show()));
    connect(action_play, SIGNAL(triggered()), this, SLOT(Player()));
    connect(action_pause, SIGNAL(triggered()), this, SLOT(Pause()));
    connect(action_last, SIGNAL(triggered()), this, SLOT(Last()));
    connect(action_next, SIGNAL(triggered()), this, SLOT(Next()));
    connect(action_stop, SIGNAL(triggered()), this, SLOT(Stop()));
    connect(action_quit, SIGNAL(triggered()), qApp, SLOT(quit()));

    trayContextMenu=new QMenu(this);
    trayContextMenu->addAction(action_restore);
    trayContextMenu->addSeparator();
    trayContextMenu->addAction(action_play);
    trayContextMenu->addAction(action_pause);
    trayContextMenu->addAction(action_last);
    trayContextMenu->addAction(action_next);
    trayContextMenu->addAction(action_stop);
    trayContextMenu->addSeparator();
    trayContextMenu->addAction(action_quit);

    trayIcon->setContextMenu(trayContextMenu);
    trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), \
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

//托盘区图标双击打开
void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::DoubleClick:
            this->show();
            this->activateWindow();
        break;
    default:
        break;
    }
}

//弹出提示
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(trayIcon->isVisible()) {
        hide();
        trayIcon->showMessage(_G("提示"), _G("酷歌将在后台运行"));
        event->ignore();
    } else {
        event->accept();
    }
}

//播放/暂停
void MainWindow::Play_Pause()
{
    if(ui->toolButton_play_pause->text()==_G("播放"))
    {
        player->play();
        ui->toolButton_play_pause->setText(_G("暂停"));
    }
    else
    {
        player->pause();
        ui->toolButton_play_pause->setText(_G("播放"));
    }
}

//播放音乐
void MainWindow::Play()
{
    if(ui->toolButton_play_pause->text()==_G("播放"))
    {
        ui->toolButton_play_pause->setText(_G("暂停"));
    }
    player->play();
}

//暂停播放
void MainWindow::Pause()
{
    player->pause();
}

//停止播放
void MainWindow::Stop()
{
    if(ui->toolButton_play_pause->text()!=_G("播放"))
    {
        ui->toolButton_play_pause->setText(_G("播放"));
    }
    player->stop();
}

//播放上一首
void MainWindow::Last()
{
    int currentIndex = playList->currentIndex();
    if(--currentIndex == -1)
        currentIndex=playList->mediaCount();
    playList->setCurrentIndex(currentIndex);
    Play();
}

void MainWindow::SH()
{
    d_s=new Dialog_search(this);
    d_s->setFixedSize(400, 370);
    d_s->show();
}

//播放下一首
void MainWindow::Next()
{
    int currentIndex = playList->currentIndex();
    if(++currentIndex == playList->mediaCount())
        currentIndex=0;
    playList->setCurrentIndex(currentIndex);
    Play();
}

//调整进度
void MainWindow::setPosition(int position)
{
    player->setPosition(position);
}

void MainWindow::playTo(int i, int /* j */)
{
    playList->setCurrentIndex(i);
    Play();
}

void MainWindow::setTableWidget()
{
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->hideColumn(2);
    QStringList headers;
    headers<<_G("歌曲")<<_G("类型")<<_G("地址");
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}



