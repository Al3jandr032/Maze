#ifndef HUMAN_H
#define HUMAN_H


#include <QObject>
#include "entity.h"

class Human:public Entity
{
public:
    enum { Mountain = 0,Earth = 1,Water = 2,Sand = 3,Forest = 4 };
    Human();
};

#endif // HUMAN_H
