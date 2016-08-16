#-------------------------------------------------
#
# Project created by QtCreator 2016-08-15T14:28:00
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_KpkCoreTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include("../../odb.pri")
# include("../kpk-data.pri")

SOURCES += tst_KpkCoreTest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kpk-data/release/ -lkpk-data
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kpk-data/debug/ -lkpk-data
else:unix: LIBS += -L$$OUT_PWD/../kpk-data/ -lkpk-data

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kpk-core/release/ -lkpk-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kpk-core/debug/ -lkpk-core
else:unix: LIBS += -L$$OUT_PWD/../kpk-core/ -lkpk-core

