#ifndef BANK_H
#define BANK_H

#include <memory>
#include <odb/core.hxx>

#include "data_global.h"

#include "DbObject.h"

namespace kpk{
namespace data{

/*!
 * \brief Банк
 */
#pragma db object
class DATASHARED_EXPORT Bank : public DbObject
{
public:
    Bank();

    /*!
     * \brief Конструктор
     * \param bik - БИК
     * \param name - название
     */
    Bank(const QString &bik, const QString &name);

    /*!
     * \brief Получить идентификатор
     * \return Идентификатор
     */
    ulong id() const;

    /*!
     * \brief Получить БИК
     * \return БИК
     */
    QString bik() const;
    /*!
     * \brief Установить БИК
     * \param bik - БИК
     */
    void bik(const QString &bik);

    /*!
     * \brief Получить название
     * \return Название
     */
    QString name() const;
    /*!
     * \brief Установить название
     * \param name - название
     */
    void name(const QString &name);

    /*!
     * \brief Получить значение счетчика обращений
     * \return значение счетчика обращений
     */
    ulong cnt() const;    

    /*!
     * \brief Увеличить счетчик обращений
     */
    void incCnt();
private:
    friend class odb::access;

    #pragma db id auto
    ulong _id;

    #pragma db type("char(9)")
    QString _bik;
    QString _name;
    ulong _cnt;
};

/*!
 * Указатель на банк
 */
using BankPtr = std::shared_ptr<Bank>;

}
}
#endif // BANK_H
