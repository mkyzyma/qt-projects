#-------------------------------------------------
#
# Project created by QtCreator 2016-05-29T18:12:52
#
#-------------------------------------------------

QT       -= gui

TARGET = fias-core
TEMPLATE = lib

DEFINES += FIASCORE_LIBRARY

SOURCES += fias.cpp

HEADERS += fias.h\
        fias-core_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
