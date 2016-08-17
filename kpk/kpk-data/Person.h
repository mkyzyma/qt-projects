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
/*!
 * \brief Личные данные
 */
#pragma db object
class  DATASHARED_EXPORT Person
{    
public:    
    Person();

    /*!
     * \brief Получить идентификатор
     * \return Идентификатор
     */
    ulong id() const;

    /*!
     * \brief Получить имя
     * \return Имя
     */
    Name &name();

    /*!
     * \brief Получить паспортные данные
     * \return Паспортные данные
     */
    Passport &passport();

    /*!
     * \brief Получить ИНН
     * \return ИНН
     */
    QString inn() const;

    /*!
     * \brief Установить ИНН
     * \param inn - ИНН
     */
    void inn(const QString &inn);

    /*!
     * \brief Получить СНИЛС
     * \return СНИЛС
     */
    QString snils() const;

    /*!
     * \brief Установить СНИЛС
     * \param snils - СНИЛС
     */
    void snils(const QString &snils);

    /*!
     * \brief Сохранен ли в системе
     * \return false - сохранен, true - не сохранен
     */
    bool isNew();

    /*!
     * \brief Получить последнюю запись о членстве
     * \return Последнеяя запись о членстве
     */
    QSharedPointer<Member> member() const;

    /*!
     * \brief Установить последнюю запись о членстве
     * \param member - последнеяя запись о членстве
     */
    void member(const QSharedPointer<Member> &member);

    /*!
     * \brief Является ли членом
     * \return true - является, false - не является
     */
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
