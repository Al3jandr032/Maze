#ifndef CROC_H
#define CROC_H

#include <QObject>
#include "entity.h"

class Croc:public Entity
{
public:
    Croc();
    enum { Mountain = 0,Earth = 4,Water = 2,Sand = 4,Forest = 5,Swamp = 1,Snow = 0 };
};

#endif // CROC_H
