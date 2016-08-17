#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <QSharedPointer>
#include <QDate>

#include "core_global.h"

#include "kpk-data/Person.h"
#include "kpk-data/Member.h"
namespace kpk{
namespace core{
/*!
 * \brief PersonPtr Указатель на личные данные
 */
typedef QSharedPointer<data::Person> PersonPtr;
/*!
 * \brief Указатель на запись членства
 */
typedef QSharedPointer<data::Member> MemberPtr;
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
    PersonPtr get(ulong id);

    /*!
     * \brief Вступить в кооператив
     * \param [in] person - Личные данные
     * \param [in] date - Дата вступления
     */
    void enter(PersonPtr person, QDate date);

    /*!
     * \brief Выйти из кооператива
     * \param [in] person - Личные данные
     * \param [in] date - Дата выхода
     */
    void exit(PersonPtr person, QDate date, data::ExitReason reason);
};

}
}
#endif // PERSONSERVICE_H
