#ifndef DATESERVICE_H
#define DATESERVICE_H

#include <QDate>
#include "core_global.h"
namespace kpk{
namespace core{
/*!
 * \brief Служба управления текущей датой
 *
 * Устанавливает рабочую дату для всей системы
 */
class CORESHARED_EXPORT DateService
{    
public:
    DateService();
    /*!
     * \brief Конструктор
     * \param current - текущая дата
     */
    DateService(const QDate &current);

    /*!
     * \brief Получить текущую дату
     * \return Текущая дата
     */
    QDate current() const;

    /*!
     * \brief Установить текущую дату
     * \param current - текущая дата
     */
    void current(const QDate &current);

    /*!
     * \brief Получить системную дату
     * \return Системная дата
     */
    QDate system() const;
private:
    QDate _current;
};

}
}
#endif // DATESERVICE_H
