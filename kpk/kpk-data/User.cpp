#include "User.h"

namespace kpk{
namespace data{

User::User()
{

}

User::User(QString username, QString password)
    : _username(username), _password(password)//, _person(person)
{

}

ulong User::id() const
{
    return _id;
}

QString User::username() const
{
    return _username;
}

void User::username(const QString &username)
{
    _username = username;
}

QString User::password() const
{
    return _password;
}

void User::password(const QString &password)
{
    _password = password;
}

/*std::shared_ptr<Person> User::person() const
{
    return _person;
}

void User::person(const std::shared_ptr<Person> &person)
{
    _person = person;
}*/

}
}
