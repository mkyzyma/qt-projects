#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <memory>

#include <QObject>

#include "core_global.h"

#include "kpk-data/User.h"

namespace kpk{
namespace core{

/*!
 * \brief Служба авторизации
 * \warning Не реализована
 * \todo Реализовать службу авторизации
 */
class CORESHARED_EXPORT AuthService : public QObject
{
    Q_OBJECT
public:
    explicit AuthService(QObject *parent = 0);

    /*!
     * \brief Получить пользователя
     * \return Пользователь
     */
    data::UserPtr user();
};

}
}
#endif // AUTHSERVICE_H
