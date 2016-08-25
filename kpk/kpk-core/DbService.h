#ifndef DBSERVICE_H
#define DBSERVICE_H

#include <memory>

#include <odb/database.hxx>

#include "core_global.h"



namespace kpk{
namespace core{


//! \brief Указатель на БД
using DbPtr = std::shared_ptr<odb::database>;
/*!
 * \brief Служба управления базой данных
 * \details Подключение, создание, работа с транзакциями
 * \note Строка: \code odb::session s; \endcode в DbService.cpp нужна для возможности
 *       работать с двунаправленными отношениями (один-к-одному, один-ко-многим)
 *       (см. odb-manual п. 11 "Session")
 */
class CORESHARED_EXPORT DbService
{
private:
    DbPtr _db;

    //! \brief Указатель на Транзакцию
    using TrPtr = std::shared_ptr<odb::transaction>;
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
     * \brief Начало транзакции
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
