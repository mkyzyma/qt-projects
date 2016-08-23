#ifndef CORE_H
#define CORE_H

#include <memory>

#include "core_global.h"
#include "DbService.h"
#include "PersonService.h"
#include "DateService.h"

namespace kpk{
namespace core{

/*!
 * \brief Ядро системы
 * \note Реализует шаблон "одиночка"
 *
 * Все службы собранные в кучу
 */
class CORESHARED_EXPORT CoreClass
{
public:    

    /*!
     * \brief Служба управления базой данных
     * \return Указатель на службу
     */
    std::shared_ptr<DbService> dbService() const;
    /*!
     * \brief Основная база данных
     * \return Указатель на базу данных
     */
    DbPtr db();
    /*!
     * \brief Получить cлужбу управления текущей датой
     * \return Служба управления текущей датой
     */
    std::shared_ptr<DateService> date() const;
    /*!
     * \brief Служба управления личными данными
     * \return Указатель на службу
     */
    std::shared_ptr<PersonService> person() const;
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
    /*!
     * \brief Получить экземпляр объекта
     * \return Экземпляр объекта
     */
    static CoreClass* instance();
protected:
    CoreClass();
    virtual ~CoreClass();
private:
    std::shared_ptr<PersonService> _person;
    std::shared_ptr<DbService> _dbService;
    std::shared_ptr<DateService> _date;
};

/*!
 * \brief Получить ядро
 * \return Указатель на ядро
 */
static CoreClass* Core(){
    return CoreClass::instance();
}

}
}
#endif // CORE_H
