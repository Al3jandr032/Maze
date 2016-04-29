#ifndef MONKEY_H
#define MONKEY_H

#include <QObject>
#include "entity.h"

class Monkey:public Entity
{
public:
    enum { Mountain = 0,Earth = 2,Water = 4,Sand = 3,Forest = 1 };
    Monkey();
};

#endif // MONKEY_H
