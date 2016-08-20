#ifndef ISDELETED_H
#define ISDELETED_H

#include <memory>
#include <QtCore/QDate>

#include <odb/core.hxx>

#include "data_global.h"

namespace kpk{
namespace data{

#pragma db object abstract
/*!
 * \brief Признак удаления
 * \details Базовый класс для объектов БД с признаком удаления.
 *          То есть для объектов, которые не желательно физически удалять
 *          из БД, а можно установить признак удаления. *
 */
class DATASHARED_EXPORT IsDeleted
{
public:
    IsDeleted();

    /*!
     * \brief Получить признак удаления
     * \return Признак удаления
     * \retval true удален
     * \retval false  не удален
     */
    bool isDeleted() const;

    /*!
     * \brief Получить дату удаления
     * \return Дата удаления
     * \retval "Дата удаления" если удален
     * \retval nullptr если не удален
     */
    std::shared_ptr<QDate> deleteDate() const;

    /*!
     * \brief Установить признак удаления
     * \param deleteDate - дата удаления
     */
    void setDeleted(QDate deleteDate);

    /*!
     * \brief снять признак удаления
     */
    void resetDeleted();
protected:
    friend class odb::access;
    bool _isDeleted;

    #pragma db null
    std::shared_ptr<QDate> _deleteDate;
};

}
}
#endif // ISDELETED_H
