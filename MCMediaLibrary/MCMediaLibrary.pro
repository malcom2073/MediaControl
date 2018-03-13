QT += core multimedia
QT -= gui

CONFIG += c++11

TARGET = MediaControl
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
INCLUDEPATH += "C:/Program Files/taglib/include"
LIBS += -L"C:/Program Files/taglib/lib" -ltag
#DEFINES += TAGLIB_STATIC
#DEFINES= QZEROCONF_STATIC
SOURCES += main.cpp \
    mccore.cpp \
    #webprovider.cpp \
    mcmedialibrary.cpp

HEADERS += \
    mccore.h \
    #webprovider.h \
    mediameta.h \
    mcmedialibrary.h

#include(../QtWebApp/logging/logging.pri)
#include(QtWebApp/httpserver/httpserver.pri)
include(../MCLaunch/MCLaunch.pri)
#include(qtzeroconf/qtzeroconf.pri)
#include(../QtWebApp/templateengine/templateengine.pri)
