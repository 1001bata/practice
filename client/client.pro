#-------------------------------------------------
#
# Project created by QtCreator 2024-06-17T16:30:16
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    client.cpp

HEADERS  += login.h \
    client.h \
    connection.h

FORMS    += login.ui \
    client.ui
