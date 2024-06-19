#-------------------------------------------------
#
# Project created by QtCreator 2024-06-17T16:04:36
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sender
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    send.cpp

HEADERS  += widget.h \
    send.h \
    connection.h

FORMS    += widget.ui \
    send.ui
