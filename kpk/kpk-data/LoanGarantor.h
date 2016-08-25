#ifndef LOANGARANTOR_H
#define LOANGARANTOR_H

#include <memory>

#include <QtCore/QDate>

#include <odb/core.hxx>

#include "data_global.h"

#include "DbObject.h"
#include "Person.h"
#include "Loan.h"

namespace kpk {
namespace data {

/*!
 * \brief Поручитель
 */
#pragma db object
class DATASHARED_EXPORT LoanGarantor : public DbObject
{
public:    
    /*!
     * \brief Конструктор
     * \param addDate Дата добавления поручителя
     * \param loan Займ
     * \param person Личные данные
     */
    LoanGarantor(QDate addDate, LoanPtr loan, PersonPtr person);

    /*!
     * \brief Получить идентификатор
     * \return Идентификатор
     */
    ulong id() const;

    /*!
     * \brief Получить дату добавления поручителя
     * \return Дата добавления поручителя
     */
    QDate addDate() const;

    /*!
     * \brief Получить займ
     * \return Займ
     */
    LoanPtr loan() const;

    /*!
     * \brief Получить личные данные
     * \return Личные данные
     */
    PersonPtr person() const;
private:
    LoanGarantor();

    friend class odb::access;
    #pragma db id auto

    ulong _id;

    QDate _addDate;

    #pragma db not_null
    #pragma db column("idLoan")
    LoanPtr _loan;

    #pragma db not_null
    #pragma db column("idPerson")
    PersonPtr _person;
};

/*!
 * \brief Указатель на поручителя
 */
using LoanGarantorPtr = std::shared_ptr<LoanGarantor>;

}
}
#endif // LOANGARANTOR_H
