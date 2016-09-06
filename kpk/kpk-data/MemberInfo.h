#ifndef PERSONINFO_H
#define PERSONINFO_H

#include "data_global.h"

#include "Person.h"
#include "Member.h"

namespace kpk{
namespace data{

#pragma db object abstract
/*!
 * \brief Информация о пайщике
 * \details Базовый класс для объектов
 * в которых присутствует  иныормация о пайщике
 */
class DATASHARED_EXPORT MemberInfo
{
public:
    MemberInfo();

    /*!
     * \brief Конструктор
     * \param member - пайщик
     */
    MemberInfo(MemberPtr member);

    /*!
     * \brief Получить пайщика
     * \return Пайщик
     */
    MemberPtr member() const;

    /*!
     * \brief Установить пайщика
     * \param member - пайщик
     */
    void member(const MemberPtr &member);

    /*!
     * \brief Получить личные данные
     * \return Личные данные
     */
    PersonPtr person() const;
protected:
    friend class odb::access;

    #pragma db not_null
    #pragma db column("idPerson")
    PersonPtr _person;

    #pragma db not_null
    #pragma db column("idMember")
    MemberPtr _member;
};

}
}
#endif // PERSONINFO_H
