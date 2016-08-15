#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <memory>
#include <list>

#include <QDate>

#include "core_global.h"

#include "kpk-data/Person.h"
#include "kpk-data/Member.h"
#include "kpk-data/Member-odb.hxx"

namespace kpk{
namespace core{
/*!
 * \brief Указатель на личные данные
 */
typedef std::shared_ptr<data::Person> PersonPtr;
/*!
 * \brief Указатель на пайщика
 */
typedef std::shared_ptr<data::Member> MemberPtr;
/*!
 * \brief Результат запроса пайщиков
 */
typedef odb::result<data::Member> MemberResult;
/*!
 * \brief Служба по управлению личными данными
 *
 * Хранение личных данных, вступление/выход, поручительство и т.д.
 * \todo Добавить работу с адресами
 */
class CORESHARED_EXPORT PersonService
{
public:
    PersonService();
    PersonPtr create();
    /*!
     * \brief Добавить личные данные
     * \param person - личные данные
     */
    void add(PersonPtr person);

    /*!
     * \brief Изменить личные данные
     * \param person - личные данные
     */
    void update(PersonPtr person);

    /*!
     * \brief Удалить личные данные
     * \param person - личные данные
     */
    void remove(PersonPtr person);

    /*!
     * \brief Получить личные данные
     * \param id - идентификатор
     * \return  Личные данные
     */
    std::shared_ptr<data::Person> get(ulong id);

    /*!
     * \brief Вступить в кооператив
     * \param person - Личные данные
     * \param date - Дата вступления
     * \throw kpk::exception::AlreadyMemberException если person уже пайщик
     */
    void enter(PersonPtr person, QDate date);

    /*!
     * \brief Выйти из кооператива
     * \param person - Личные данные
     * \param date - Дата выхода
     * \param reason - Причина
     * \throw kpk::exception::NotAMemberException если person не пайщик
     */
    void exit(PersonPtr person, QDate date, data::ExitReason reason);

    /*!
     * \brief Получить историю членства
     * \param idPerson - идентификатор личных данных
     * \return История членства
     */
    MemberResult membership(ulong idPerson) const;
};

}
}
#endif // PERSONSERVICE_H
