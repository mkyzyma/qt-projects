#ifndef TOSTRING_H
#define TOSTRING_H

#include <QString>

namespace common{

class ToString{
public:
    virtual QString toString() = 0;
    //virtual ~ToString() = 0;
};

}

#endif // TOSTRING_H
