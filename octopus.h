#ifndef OCTOPUS_H
#define OCTOPUS_H

#include <QObject>
#include "entity.h"


class Octopus:public Entity
{
public:
    enum { Mountain = 0,Earth = 2,Water = 1,Sand = 0,Forest = 3,Swamp = 2,Snow = 0 };
    Octopus();
};

#endif // OCTOPUS_H
