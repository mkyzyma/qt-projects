#ifndef USER_H
#define USER_H

#include <memory>

#include <QtCore/QString>
#include <QtCore/QDate>

#include <odb/core.hxx>

#include "data_global.h"


#include "IsDeleted.h"

namespace kpk{
namespace data{
//class Person;
/*!
 * \brief Пользователь
 */
#pragma db object
class DATASHARED_EXPORT User : public IsDeleted
{
public:
    User();
    User(QString username, QString password);
    ulong id() const;

    QString username() const;
    void username(const QString &username);

    QString password() const;
    void password(const QString &password);

    /*std::shared_ptr<Person> person() const;
    void person(const std::shared_ptr<Person> &person);*/
private:
    friend class odb::access;

    #pragma db id auto
    ulong _id;

    QString _username;
    QString _password;

    /*#pragma db null
    #pragma db column("idPerson")
    std::shared_ptr<Person> _person;*/
};

}
}



#endif // USER_H
