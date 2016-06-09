#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T11:32:45
#
#-------------------------------------------------

QT       -= gui

TARGET = common
TEMPLATE = lib

DEFINES += COMMON_LIBRARY

SOURCES +=

HEADERS +=\
        common_global.h \
    ToString.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
