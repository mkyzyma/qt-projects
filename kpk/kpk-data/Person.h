#ifndef PERSON_H
#define PERSON_H

#include <QtCore/QString>
#include <QtCore/QSharedPointer>

#include <odb/core.hxx>

#include "data_global.h"

#include "Name.h"
#include "Passport.h"


namespace kpk{
namespace data{

class Member;
#pragma db object
class  DATASHARED_EXPORT Person
{    
public:    
    Person();

    ulong id() const;

    Name &name();
    Passport &passport();

    QString inn() const;
    void inn(const QString &inn);

    QString snils() const;
    void snils(const QString &snils);

    bool isNew();

    QSharedPointer<Member> member() const;
    void member(const QSharedPointer<Member> &member);

    bool isMember();
private:
    friend class odb::access;

#pragma db id auto
    ulong _id;

    Name _name;

    #pragma db column("pass")
    Passport _passport;

    #pragma db type("char(12)")
    QString _inn;

    #pragma db type("char(14)")
    QString _snils;

    #pragma db null
    #pragma db column("idMember")
    QSharedPointer<Member> _member;
};

}
}
#endif // PERSON_H

#include "Member.h"
