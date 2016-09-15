#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "Dialog_search.h"

#define _G QString::fromLocal8Bit


namespace Ui {
class MainWindow;
}

class QAction;
class QMenu;
class QMediaPlayer;
class QMediaPlaylist;
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:

    void createSystemTrayIcon();


    QPoint dragPos;
    int volume;

    Dialog_search * d_s;

    QAction *action_restore;
    QAction *action_last;
    QAction *action_next;
    QAction *action_play;
    QAction *action_stop;
    QAction *action_pause;
    QAction *action_quit;

    QMenu *trayContextMenu;

    QMediaPlayer *player;
    QMediaPlaylist *playList;
    QSystemTrayIcon *trayIcon;

private slots:
    void Play();
    void Stop();
    void Pause();
    void Next();
    void Last();



    void Play_Pause();
    void playTo(int, int);
    void setPosition(int);
    void setTableWidget();

    void importSongs();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

public slots:
    void SH();

protected:
    void closeEvent(QCloseEvent *);

};

#endif // MAINWINDOW_H
