#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <QSharedPointer>

#include "core_global.h"

#include "kpk-data/Person.h"
namespace kpk{
namespace core{
/*!
 * \brief PersonPtr Указатель на личные данные
 */
typedef QSharedPointer<data::Person> PersonPtr;
/*!
 * \brief Служба по управлению личными данными
 *
 * Хранение личных данных, вступление/выход, поручительство и т.д.
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
};

}
}
#endif // PERSONSERVICE_H
