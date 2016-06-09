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

INCLUDEPATH += $$PWD/../../common
DEPENDPATH += $$PWD/../../common

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



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../common/debug/ -lcommon
else:unix: LIBS += -L$$OUT_PWD/../../common/ -lcommon


