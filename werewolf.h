#ifndef WEREWOLF_H
#define WEREWOLF_H
#include <QObject>
#include "entity.h"


class Werewolf:public Entity
{
public:
    Werewolf();
    enum { Mountain = 0,Earth = 1,Water = 3,Sand = 4,Forest = 2,Swamp = 0,Snow = 3 };
};

#endif // WEREWOLF_H
