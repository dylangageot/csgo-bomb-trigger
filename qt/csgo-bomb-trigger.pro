#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T23:54:24
#
#-------------------------------------------------

LIBS += -LC:/boost/boost_1_64_0/stage/lib/ -lboost_system-mgw53-mt-1_64 -lboost_thread-mgw53-mt-1_64 -lws2_32 -lwsock32

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CSGO_bomb
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:/boost/boost_1_64_0

SOURCES += main.cpp\
    window.cpp \
    json_handler.cpp

HEADERS  += \
    crow_all.h \
    window.h \
    json_handler.h \
    configuration.h

FORMS    += \
    window.ui
