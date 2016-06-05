#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T10:32:00
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

CONFIG += c++14


TARGET = tst_kpkDataTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include("../../odb.pri")
include("../kpk-data.pri")

SOURCES += tst_kpkDataTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kpk-data/release/ -lkpk-data
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kpk-data/debug/ -lkpk-data
else:unix: LIBS += -L$$OUT_PWD/../kpk-data/ -lkpk-data

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
