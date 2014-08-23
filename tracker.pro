#-------------------------------------------------
#
# Project created by QtCreator 2014-08-22T00:25:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tracker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    backend.cpp

HEADERS  += mainwindow.h \
    backend.h

FORMS    += mainwindow.ui
