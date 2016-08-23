#include "PersonService.h"
#include "Core.h"

#include <odb/session.hxx>
#include <odb/query.hxx>

#include "kpk-data/Person-odb.hxx"
#include "kpk-data/Member-odb.hxx"


#include "Exceptions.h"

namespace kpk{
namespace core{

using namespace data;

typedef odb::query<Member> MemberQuery;

PersonService::PersonService()
{}

void PersonService::add(PersonPtr person)
{
    Core()->db()->persist(person);
}

void PersonService::update(PersonPtr person)
{
    Core()->db()->update(person);
}

void PersonService::remove(ulong id)
{
    Core()->db()->erase<Person>(id);
}

PersonPtr PersonService::get(ulong id)
{    
    auto p(Core()->db()->load<Person>(id));
    return p;
}

void PersonService::enter(PersonPtr person, QDate date)
{    
    if(person->isNew())
        add(person);
    else
        if(person->isMember())
            throw exception::AlreadyMemberException();

    auto member(std::make_shared<Member>(Member(person, date)));

    Core()->db()->persist(member);

    person->member(member);
    update(person);
}

void PersonService::exit(PersonPtr person, QDate date, ExitReason reason)
{
   if(!person->isMember())
        throw exception::NotAMemberException();

   auto m = person->member().lock();

    m->outDate(std::make_shared<QDate>(date));
    m->exitReason(reason);

    Core()->db()->update(m);
}

MemberResult PersonService::membership(ulong idPerson) const
{
    auto q(MemberQuery::person == idPerson);
    return Core()->db()->query<Member>(q);
}


}
}
