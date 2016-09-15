#-------------------------------------------------
#
# Project created by QtCreator 2016-09-15T11:55:40
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KuGe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog_search.cpp \
    gethtml.cpp

HEADERS  += mainwindow.h \
    dialog_search.h \
    gethtml.h

FORMS    += mainwindow.ui \
    dialog_search.ui

RESOURCES += \
    kuge.qrc

QT       += network

DISTFILES += \
    icon.ico
