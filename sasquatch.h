#ifndef SASQUATCH_H
#define SASQUATCH_H
#include <QObject>
#include "entity.h"


class Sasquatch:public Entity
{
public:
    Sasquatch();
    enum { Mountain = 15,Earth = 4,Water = 0,Sand = 0,Forest = 4,Swamp = 5,Snow = 3 };
};

#endif // SASQUATCH_H
