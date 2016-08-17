#ifndef NAME_H
#define NAME_H

#include <QtCore/QString>

#include <odb/core.hxx>


#include "data_global.h"
namespace kpk
{
namespace data
{

#pragma db value
/*!
 * \brief Полное имя
 */
class DATASHARED_EXPORT Name
{    
public:
    explicit Name(){}

    /*!
     * \brief Конструктор
     * \param first - имя
     * \param middle - отчество
     * \param last - фамилия
     */
    explicit Name(QString first, QString middle, QString last)
        : _first(first), _middle(middle), _last(last)
    {}

    /*!
     * \brief Получить имя
     * \return Имя
     */
    QString first() const;

    /*!
     * \brief Установить имя
     * \param first - имя
     */
    void first(const QString &first);

    /*!
     * \brief Получить фамилию
     * \return Фамилия
     */
    QString last() const;

    /*!
     * \brief Установить фамилию
     * \param last - фамилия
     */
    void last(const QString &last);

    /*!
     * \brief Получить отчество
     * \return Отчество
     */
    QString middle() const;

    /*!
     * \brief Установить отчество
     * \param middle - отчество
     */
    void middle(const QString &middle);

    /*!
     * \brief Установить имя
     * \param first - имя
     * \param middle - отчество
     * \param last - фамилия
     * \return Полное имя
     */
    QString set(const QString &first, const QString &middle, const QString &last);

    /*!
     * \brief Получить полное имя
     * \return Полное имя
     */
    QString full() const;

    /*!
     * \brief Преобразовать в строку
     * \return Полное имя
     */
    QString toString();

private:
    friend class odb::access;

    QString combine();

    QString _first;
    QString _middle;
    QString _last;
    QString _full;
};

}
}
#endif // NAME_H
