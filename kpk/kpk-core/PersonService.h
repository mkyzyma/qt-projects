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
 * \brief Результат запроса пайщиков
 */
using MemberResult = odb::result<data::Member>;
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

    data::PersonPtr create();
    /*!
     * \brief Добавить личные данные
     * \param person - личные данные
     */
    void add(data::PersonPtr person);

    /*!
     * \brief Изменить личные данные
     * \param person - личные данные
     */
    void update(data::PersonPtr person);

    /*!
     * \brief Удалить личные данные
     * \param person - личные данные
     */
    void remove(data::PersonPtr person);

    /*!
     * \brief Получить личные данные
     * \param id - идентификатор
     * \return  Личные данные
     */
    data::PersonPtr get(ulong id);

    /*!
     * \brief Вступить в кооператив
     * \param person - Личные данные
     * \param date - Дата вступления
     * \throw kpk::exception::AlreadyMemberException если person уже пайщик
     */
    void enter(data::PersonPtr person, QDate date);

    /*!
     * \brief Выйти из кооператива
     * \param person - Личные данные
     * \param date - Дата выхода
     * \param reason - Причина
     * \throw kpk::exception::NotAMemberException если person не пайщик
     */
    void exit(data::PersonPtr person, QDate date, data::ExitReason reason);

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
