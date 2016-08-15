#ifndef DATESERVICE_H
#define DATESERVICE_H

#include <QObject>
#include <QDate>
#include <QDateTime>

#include "core_global.h"
namespace kpk{
namespace core{
/*!
 * \brief Служба управления рабочей датой
 *
 * Устанавливает рабочую дату для всей системы
 */
class CORESHARED_EXPORT DateService : public QObject
{    
    Q_OBJECT
public:
    explicit DateService(QObject *parent = 0);
    /*!
     * \brief Конструктор
     * \param working - рабочая дата
     */
    DateService(const QDate &working);

    /*!
     * \brief Получить рабочую дату
     * \return Рабочая дата
     */
    QDate working() const;

    /*!
     * \brief Установить рабочую дату
     * \param working - рабочая дата
     */
    void working(const QDate &working);

    /*!
     * \brief Получить текущую дату
     * \return Текущая дата
     */
    QDate current() const;

    QDateTime currentTime() const;
private:
    QDate _working;
};

}
}
#endif // DATESERVICE_H
