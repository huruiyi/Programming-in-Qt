#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T09:42:05
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Coin
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    mypushbutton.cpp \
    levelscence.cpp \
    playerscence.cpp \
    mycoin.cpp \
    dataconfig.cpp

HEADERS  += mainwindow.h \
    mypushbutton.h \
    levelscence.h \
    playerscence.h \
    mycoin.h \
    dataconfig.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
