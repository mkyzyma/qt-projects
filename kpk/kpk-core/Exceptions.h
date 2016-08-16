#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

namespace kpk{
namespace exception{

struct AlreadyMemberException : std::exception
{
    const char * what() const throw()
    {
        return "Уже является членом кооператива";
    }
};

struct NotAMemberException : std::exception
{
    const char * what() const throw()
    {
        return "Не является членом кооператива";
    }
};

}
}

#endif // EXCEPTIONS_H
