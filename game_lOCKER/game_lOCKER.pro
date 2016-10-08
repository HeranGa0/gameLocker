#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T03:20:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_lOCKER
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settime.cpp \
    makesure.cpp

HEADERS  += mainwindow.h \
    settime.h \
    makesure.h

FORMS    += mainwindow.ui \
    settime.ui \
    makesure.ui

RESOURCES += \
    picture.qrc
