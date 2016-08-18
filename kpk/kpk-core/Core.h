#ifndef CORE_H
#define CORE_H

#include <memory>

#include "core_global.h"
#include "DbService.h"
#include "PersonService.h"

namespace kpk{
namespace core{

/*!
 * \brief Класс Ядра
 *
 * Все службы собранные в кучу
 */
class CORESHARED_EXPORT CoreClass
{
public:
    CoreClass();

    /*!
     * \brief Служба управления базой данных
     * \return Указатель на службу
     */
    std::shared_ptr<DbService>& dbService();
    /*!
     * \brief Основная база данных
     * \return Указатель на базу данных
     */
    DbPtr db();
    /*!
     * \brief Служба управления личными данными
     * \return Указатель на службу
     */
    std::shared_ptr<PersonService>& person();

    /*!
     * \brief Начать транзакцию в основной базе
     */
    void begin();
    /*!
     * \brief Фиксировать транзакцию в основной базе
     */
    void commit();
    /*!
     * \brief Отменить транзакцию в основной базе
     */
    void rollback();
private:
    std::shared_ptr<PersonService> _person;
    std::shared_ptr<DbService> _dbService;
};

/*!
 * \brief Получить ядро
 * \return Указатель на ядро
 */
static CoreClass* Core(){
    static CoreClass instance;
    return &instance;
}

}
}
#endif // CORE_H
