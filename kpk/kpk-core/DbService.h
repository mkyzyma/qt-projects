#ifndef DBSERVICE_H
#define DBSERVICE_H

#include <QSharedPointer>

#include <odb/database.hxx>

#include "core_global.h"

namespace kpk{
namespace core{

typedef QSharedPointer<odb::database> DbPtr;
typedef QSharedPointer<odb::transaction> TrPtr;

/*!
 * \brief Служба управления базой данных
 *
 * Подключение, создание, работа с транзакциями
 */
class CORESHARED_EXPORT DbService
{
private:
    DbPtr _db;
    TrPtr _tr;
public:
    DbService();

    /*!
     * \brief Подключение к БД
     * \return Указатель на БД
     */
    DbPtr& connect();

    /*!
     * \brief Получить объект БД
     * \return Указатель на БД
     */
    DbPtr& get();

    /*!
     * \brief Создать схему
     * \return Указатель на БД
     */
    DbPtr& createShcema();

    /*!
     * \brief Открыть транзакцию
     */
    void begin();

    /*!
     * \brief Фиксация транзакции
     */
    void commit();

    /*!
     * \brief Отмена транзакции
     */
    void rollback();
};

}
}

#endif // DBSERVICE_H
