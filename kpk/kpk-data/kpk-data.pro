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
include("../../qdecimal.pri")

SOURCES += \
    Person.cpp \
    Name.cpp \
    Passport.cpp \
    Member.cpp \
    Loan.cpp \
    LoanOperValue.cpp \
    LoanOper.cpp \
    LoanType.cpp \
    IsDeleted.cpp

HEADERS += \
    data_global.h \
    Person.h \
    Name.h \
    Passport.h \
    Member.h \
    Loan.h \
    LoanOperValue.h \
    LoanOper.h \
    LoanType.h \
    IsDeleted.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    create.cmd \
    createfile.cmd \
    create \
    createfile





