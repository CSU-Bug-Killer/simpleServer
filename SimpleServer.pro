#-------------------------------------------------
#
# Project created by QtCreator 2017-07-04T17:11:20
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = SimpleServer
TEMPLATE = app


SOURCES += main.cpp\
        testnet.cpp

HEADERS  += testnet.h

FORMS    += testnet.ui
