#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T15:19:08
#
#-------------------------------------------------

QT       -= gui

TARGET = kpk-lib
TEMPLATE = lib

DEFINES += KPKLIB_LIBRARY

SOURCES += \
    Lib.cpp

HEADERS += ToString.h \
    lib_global.h \
    Lib.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
