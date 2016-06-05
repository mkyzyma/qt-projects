#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T16:13:55
#
#-------------------------------------------------

QT       -= gui

TARGET = kpk-data
TEMPLATE = lib

DEFINES += KPKDATA_LIBRARY

include("../../odb.pri")

SOURCES += \
    Person.cpp \
    Name.cpp \
    Passport.cpp \
    Member.cpp

HEADERS += \
    data_global.h \
    Person.h \
    Name.h \
    Passport.h \
    Member.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    create.cmd \
    createfile.cmd \
    create \
    createfile

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../kpk-lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kpk-lib/release/ -lkpk-lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kpk-lib/debug/ -lkpk-lib
else:unix: LIBS += -L$$OUT_PWD/../kpk-lib/ -lkpk-lib

