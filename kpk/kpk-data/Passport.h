#ifndef PASSPORT_H
#define PASSPORT_H


#include <QtCore/QString>
#include <QtCore/QDate>

#include <odb/core.hxx>

#include "data_global.h"

namespace kpk
{
namespace data
{
/*!
 * \brief Паспортные данные
 */
#pragma db value
class DATASHARED_EXPORT Passport
{    
public:
    Passport();

    /*!
     * \brief Получить серию
     * \return Серия
     */
    QString series() const;
    /*!
     * \brief Установить серию
     * \param series - серия
     */
    void series(const QString &series);
    /*!
     * \brief Получить номер
     * \return Номер
     */
    QString number() const;
    /*!
     * \brief Установить номер
     * \param number - номер
     */
    void number(const QString &number);

    /*!
     * \brief Получить дату выдачи
     * \return Дата выдачи
     */
    QDate date() const;

    /*!
     * \brief Установить дату выдачи
     * \param date - дата выдачи
     */
    void date(const QDate &date);

    /*!
     * \brief Получить организацию
     * \return Организация
     */
    QString org() const;

    /*!
     * \brief Установить организацию
     * \param org - организация
     */
    void org(const QString &org);

    /*!
     * \brief Получить код отделения
     * \return Код отделения
     */
    QString orgCode() const;

    /*!
     * \brief Установить код отделения
     * \param orgCode - Код отделения
     */
    void orgCode(const QString &orgCode);

    /*!
     * \brief Установить все данные
     * \param series - серия
     * \param number - номер
     * \param date - дата выдачи
     * \param org - организация
     * \param orgCode - код отделения
     * \return Строка со всеми данными
     */
    QString set(QString series, QString number, QDate date,
                QString org, QString orgCode);

    /*!
     * \brief Получить строку со всеми данными
     * \return Строка со всеми данными
     */
    QString full();

    /*!
     * \brief Преобразовать в строку
     * \return Строка со всеми данными
     */
    QString toString();
private:
    friend class odb::access;

    #pragma db type("char(4)")
    QString _series;
    #pragma db type("char(6)")
    QString _number;
    QDate _date;
    QString _org;
    #pragma db type("char(6)")
    QString _orgCode;
};

}
}

#endif // PASSPORT_H
