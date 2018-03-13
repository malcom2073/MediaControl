INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += network

# Enable very detailed debug messages when compiling the debug version
CONFIG(debug, debug|release) {
    #DEFINES += SUPERVERBOSE
}

HEADERS += $$PWD/mclaunch.h \
	   $$PWD/mcipc.h

SOURCES += $$PWD/mclaunch.cpp \
	   $$PWD/mcipc.cpp
