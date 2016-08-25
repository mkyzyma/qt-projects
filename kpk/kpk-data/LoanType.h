#ifndef LOANTYPE_H
#define LOANTYPE_H
#include <QtCore/QString>

#include <odb/core.hxx>

#include "data_global.h"

#include "DbObject.h"
namespace kpk{
namespace data{

/*!
 * \brief Вид займа
 */
#pragma db object
class DATASHARED_EXPORT LoanType : public DbObject
{
public:
    LoanType();
    /*!
     * \brief Конструктор
     * \param caption - название
     * \param rate - ставка по умолчанию
     */
    LoanType(QString caption, long rate);

    /*!
     * \brief Получить идентификатор
     * \return Идентификатор
     */
    ulong id();

    /*!
     * \brief Получить название
     * \return Название
     */
    QString caption() const;

    /*!
     * \brief Установить название
     * \param caption - название
     */
    void caption(const QString &caption);

    /*!
     * \brief Получить ставку по умолчанию
     * \return Ставка по умолчанию
     */
    long rate() const;

    /*!
     * \brief Установить ставку по умолчанию
     * \param rate - ставка по умолчанию
     */
    void rate(long rate);

private:
    friend class odb::access;
    #pragma db id auto
    ulong _id;

    #pragma db type("char(63)")
    QString _caption;

    long _rate;
};

/*!
 * \brief Указатель на вид займа
 */
using LoanTypePtr = std::shared_ptr<LoanType>;

}
}

#endif // LOANTYPE_H
