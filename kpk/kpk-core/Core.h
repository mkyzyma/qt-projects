#ifndef CORE_H
#define CORE_H

#include <memory>

#include "core_global.h"
#include "DbService.h"
#include "AuthService.h"
#include "PersonService.h"
#include "LoanService.h"
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
     * \brief Получить службу авторизации
     * \return Служба авторизации
     */
    std::shared_ptr<AuthService> auth() const;
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
     * \brief Получить службу управления займами
     * \return Служба управления займами
     */
    std::shared_ptr<LoanService> loan() const;
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
     * \brief Число из строки
     * \param str - строка
     * \return Число
     */
    long numberFormString(QString str);
    /*!
     * \brief Получить экземпляр объекта
     * \return Экземпляр объекта
     */
    static CoreClass* instance();    
protected:
    enum constants{DEC_DIGITS = 4};
    CoreClass();
    virtual ~CoreClass();
private:
    std::shared_ptr<DbService> _dbService = std::make_shared<DbService>();
    std::shared_ptr<AuthService> _auth = std::make_shared<AuthService>();
    std::shared_ptr<PersonService> _person = std::make_shared<PersonService>();
    std::shared_ptr<LoanService> _loan = std::make_shared<LoanService>();
    std::shared_ptr<DateService> _date = std::make_shared<DateService>(QDate::currentDate());
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
