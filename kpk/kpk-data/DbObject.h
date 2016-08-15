#ifndef DBOBJECT_H
#define DBOBJECT_H

#include <memory>

#include <QtCore/QDateTime>

#include <odb/core.hxx>

#include "data_global.h"

#include "IsDeleted.h"
#include "User.h"
namespace kpk {
namespace data {

#pragma db object abstract
/*!
 * \brief Базовый класс для объектов БД
 * \details Добавляет информацию о том когда и кем был создан объект
 */
class DATASHARED_EXPORT DbObject : public IsDeleted
{
public:
    DbObject();
    /*!
     * \brief Установить информацию о создании
     * \param time - время создания
     * \param user - создавший пользователь
     */
    void setCreateInfo(QDateTime time, std::shared_ptr<User> user);

    /*!
     * \brief Получить время создания
     * \return Время создания
     */
    QDateTime createTime() const;

    /*!
     * \brief Кем создан
     * \return Создавший пользователь
     */    std::shared_ptr<User> createdBy() const;
private:
    friend class odb::access;
    QDateTime _createTime;

    #pragma db not_null
    #pragma db column("idUser")
    std::shared_ptr<User> _createdBy;
};

}
}
#endif // DBOBJECT_H
