#include "MemberInfo.h"

namespace kpk{
namespace data{

MemberInfo::
MemberInfo()
{}

MemberInfo::
MemberInfo(MemberPtr member)
    : _member(member), _person(member->person())
{}

MemberPtr
MemberInfo::
member() const
{
    return _member;
}

void MemberInfo::
member(const MemberPtr &member)
{
    _member = member;
    _person = member->person();
}

PersonPtr MemberInfo::
person() const
{
    return _person;
}

}
}
