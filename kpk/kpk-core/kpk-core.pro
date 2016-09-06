#-------------------------------------------------
#
# Project created by QtCreator 2016-08-13T13:35:33
#
#-------------------------------------------------

QT       -= gui

TARGET = kpk-core
TEMPLATE = lib

include("../../odb.pri")
include("../kpk-data.pri")
include("../../qdecimal.pri")

DEFINES += KPKCORE_LIBRARY

SOURCES += \
    DbService.cpp \
    PersonService.cpp \
    Core.cpp \
    DateService.cpp \
    AuthService.cpp \
    LoanService.cpp

HEADERS += \
    core_global.h \    
    DbService.h \
    PersonService.h \
    Core.h \
    Exceptions.h \
    DateService.h \
    AuthService.h \
    LoanService.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kpk-data/release/ -lkpk-data
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kpk-data/debug/ -lkpk-data
else:unix: LIBS += -L$$OUT_PWD/../kpk-data/ -lkpk-data

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
