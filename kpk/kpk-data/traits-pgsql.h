#ifndef TRAITSPGSQL_H
#define TRAITSPGSQL_H

#include <odb/pgsql/traits.hxx>
#include <odb/pgsql/details/endian-traits.hxx>

#include <QDecNumber.hh>
#include <QDecDouble.hh>

#include "data_global.h"
namespace odb{
namespace pgsql{

/*!
 * \brief Особенность работы в PostgreSQL c QDecNumber
 *
 * Реализует возможность работать odb с полями типа QDecNumber
 * Значение в БД сохраняется как целое, умноженное 10000.
 * То есть точность - 4 знака после запятой
 */
template <>
class value_traits<QDecNumber, id_bigint>
{
public:
    typedef QDecNumber value_type;
    typedef QDecNumber query_type;
    typedef __int64 image_type;

    static void
    set_value (value_type& v, const image_type& i, bool is_null)
    {
        if (is_null)
        {
            v.fromInt32(0);
            return;
        }

        image_type l(details::endian_traits::ntoh(i));

        QDecDouble d((double)l);
        d.setExponent(-4);

        v = d.toQDecNumber();
    }

    static void
    set_image (image_type& i, bool& is_null, const value_type& v)
    {
        is_null = false;

        QDecDouble d;
        d.fromQDecNumber(v);

        d *= 10000;
        d = d.toIntegralValue(rounding::DEC_ROUND_HALF_EVEN);

        image_type l((image_type)d.toDouble());

        i = details::endian_traits::hton(l);
    }
};

}
}

#endif // TRAITSPGSQL_H
