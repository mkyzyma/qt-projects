#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <memory>
#include <QDate>

#include "core_global.h"

#include "kpk-data/Person.h"
#include "kpk-data/Member.h"
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
 * \brief Служба по управлению личными данными
 *
 * Хранение личных данных, вступление/выход, поручительство и т.д.
 * \todo Добавить работу с адресами
 */
class CORESHARED_EXPORT PersonService
{
public:
    PersonService();

    /*!
     * \brief Добавить личные данные
     * \param [in] person - личные данные
     */
    void add(PersonPtr person);

    /*!
     * \brief Изменить личные данные
     * \param [in] person - личные данные
     */
    void update(PersonPtr person);

    /*!
     * \brief Удалить личные данные
     * \param [in] id - идентификатор
     */
    void remove(ulong id);

    /*!
     * \brief Получить личные данные
     * \param [in] id - идентификатор
     * \return  Личные данные
     */
    std::shared_ptr<data::Person> get(ulong id);

    /*!
     * \brief Вступить в кооператив
     * \param [in] person - Личные данные
     * \param [in] date - Дата вступления
     * \throw kpk::exception::AlreadyMemberException если person уже пайщик
     */
    void enter(PersonPtr person, QDate date);

    /*!
     * \brief Выйти из кооператива
     * \param [in] person - Личные данные
     * \param [in] date - Дата выхода
     * \throw kpk::exception::NotAMemberException если person не пайщик
     */
    void exit(PersonPtr person, QDate date, data::ExitReason reason);
};

}
}
#endif // PERSONSERVICE_H
