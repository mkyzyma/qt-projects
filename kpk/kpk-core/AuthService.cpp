#include "AuthService.h"
#include "Core.h"
#include "kpk-data/User-odb.hxx"
namespace kpk{
namespace core{

using namespace data;

AuthService::AuthService(QObject *parent) : QObject(parent)
{

}

UserPtr AuthService::user()
{
    return Core()->db()->load<User>(1);
}

}
}
