QT += core
QT -= gui

CONFIG += c++14

TARGET = kpk-test-console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

include("../../odb.pri")
include("../../qdecimal.pri")
include("../kpk-data.pri")

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kpk-data/release/ -lkpk-data
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kpk-data/debug/ -lkpk-data
else:unix: LIBS += -L$$OUT_PWD/../kpk-data/ -lkpk-data

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../






win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kpk-core/release/ -lkpk-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kpk-core/debug/ -lkpk-core
else:unix: LIBS += -L$$OUT_PWD/../kpk-core/ -lkpk-core

