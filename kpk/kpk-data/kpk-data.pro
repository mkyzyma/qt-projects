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
    LoanType.cpp \
    IsDeleted.cpp \
    User.cpp \
    DbObject.cpp \
    LoanGarantor.cpp \
    DecTest.cpp \
    Payment.cpp \
    Bank.cpp \
    LoanPaymentValue.cpp \
    LoanPayment.cpp \
    MemberInfo.cpp

HEADERS += \
    data_global.h \
    Person.h \
    Name.h \
    Passport.h \
    Member.h \
    Loan.h \
    LoanType.h \
    IsDeleted.h \
    User.h \
    DbObject.h \
    LoanGarantor.h \
    DecTest.h \
    traits-pgsql.h \
    type.h \
    Payment.h \
    Bank.h \
    LoanPaymentValue.h \
    LoanPayment.h \
    MemberInfo.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    create.cmd \
    createfile.cmd \
    create \
    createfile





