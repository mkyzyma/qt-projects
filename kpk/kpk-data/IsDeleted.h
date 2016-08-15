#ifndef ISDELETED_H
#define ISDELETED_H

#include <memory>
#include <QtCore/QDateTime>

#include <odb/core.hxx>

#include "data_global.h"

namespace kpk{
namespace data{

class User;
/*!
 * \brief Признак удаления
 * \details Базовый класс для объектов БД с признаком удаления.
 *          То есть для объектов, которые не желательно физически удалять
 *          из БД, а можно установить признак удаления. *
 */
#pragma db object abstract
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
     * \brief Получить время удаления
     * \return Время удаления
     * \retval "Время удаления" если удален
     * \retval nullptr если не удален
     */
    std::shared_ptr<QDateTime> deleteTime() const;

    /*!
     * \brief Получить удалившего пользователя
     * \return Удаливший пользователь
     * \retval "Удаливший пользователь" если удален
     * \retval nullptr если не удален
     */
    std::shared_ptr<User> deletedBy() const;
    /*!
     * \brief Установить признак удаления
     * \param time - время удаления
     * \param user - удаляющий пользователь
     */
    void setDeleted(QDateTime time, std::shared_ptr<User> user);

    /*!
     * \brief снять признак удаления
     */
    void resetDeleted();


protected:
    friend class odb::access;
    bool _isDeleted = false;

    #pragma db null
    std::shared_ptr<QDateTime> _deleteTime;

    #pragma db null
    std::shared_ptr<User> _deletedBy;
};

}
}
#include "User.h"
#endif // ISDELETED_H
