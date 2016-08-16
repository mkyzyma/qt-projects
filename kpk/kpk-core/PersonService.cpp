#include "PersonService.h"
#include "Core.h"

#include <odb/pgsql/exceptions.hxx>

#include "kpk-data/Person-odb.hxx"

namespace kpk{
namespace core{

using namespace data;

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
    return PersonPtr(Core()->db()->load<Person>(id));
}



}
}
