#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
/*!
 *\file
 * \brief Исключения
 * \todo Разобраться с передачей сообщений в исключениях и вообще с исключениями с++
 */
namespace kpk{
namespace exception{

/*!
 * \brief Уже является членом кооператива
 */
class AlreadyMemberException : public std::exception
{
    const char * what() const throw()
    {
        return "Уже является членом кооператива";
    }
};

/*!
 * \brief Не является членом кооператива
 */
class NotAMemberException : public std::exception
{
    const char * what() const throw()
    {
        return "Не является членом кооператива";
    }
};

}
}

#endif // EXCEPTIONS_H
