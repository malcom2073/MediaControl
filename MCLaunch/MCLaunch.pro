QT += core network
QT -= gui

CONFIG += c++11

TARGET = MCLaunch
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mclaunch.cpp \
    mcipc.cpp

HEADERS += \
    mclaunch.h \
    mcipc.h

DISTFILES += \
    MCLaunch.pri
