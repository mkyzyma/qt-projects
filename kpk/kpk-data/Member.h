#ifndef MEMBER_H
#define MEMBER_H

#include <memory>

#include <odb/core.hxx>


#include "data_global.h"
#include "Person.h"

namespace kpk{
namespace data{

/*!
 * \brief Причина выхода
 */
enum ExitReason
{
    ER_NONE, ///<\brief Не вышел
    ER_EXIT, ///<\brief Вышел добровольно
    ER_KICK, ///<\brief Исключен
    ER_DEATH ///<\brief Умер
};

/*!
 * \brief Пайщик
 */
#pragma db object
class DATASHARED_EXPORT Member
{
public:    
    Member();
    /*!
     * \brief Конструктор
     * \param person - личные данные
     * \param inDate - дата вступления
     * \param outDate - дата выхода
     */
    Member(std::shared_ptr<Person> person,
           QDate inDate,
           std::shared_ptr<QDate> outDate = nullptr);

    /*!
     * \brief Получить идентификатор
     * \return Идкнтификатор
     */
    ulong id() const;

    /*!
     * \brief Получить личные данные
     * \return Личные данные
     */
    std::shared_ptr<Person> person() const;

    /*!
     * \brief Установить личные данные
     * \param person - личные данные
     */
    void person(const std::shared_ptr<Person> &person);

    /*!
     * \brief Получить дату вступления
     * \return  Дата вступления
     */
    QDate inDate() const;

    /*!
     * \brief Установить дату вступления
     * \param inDate - дата вступления
     */
    void inDate(const QDate &inDate);

    /*!
     * \brief Получить дату выхода
     * \return Указатель на дату выхода
     * \warning Может быть NULL
     */
    std::shared_ptr<QDate> outDate() const;

    /*!
     * \brief Установить дату выхода
     * \param outDate - Указатель на дату выхода
     * \warning Может быть NULL
     */
    void outDate(const std::shared_ptr<QDate> &outDate);

    /*!
     * \brief Получить причину выхода
     * \return Причина выхода
     */
    ExitReason exitReason() const;

    /*!
     * \brief Установить причину выхода
     * \param exitReason - причина выхода
     */
    void exitReason(const ExitReason &exitReason);
private:
    friend class odb::access;

#pragma db id auto
    ulong _id;

    QDate _inDate;

    #pragma db null
    std::shared_ptr<QDate> _outDate;

    ExitReason _exitReason;

    #pragma db not_null
    #pragma db column("idPerson")
    std::shared_ptr<Person> _person;
};

}
}
#endif // MEMBER_H
