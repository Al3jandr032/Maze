#ifndef ROUTE_H
#define ROUTE_H
#include "coordinates.h"
#include "human.h"
#include "monkey.h"
#include <QObject>

class Route
{
public:
    Route();
private:
    Coordinates DT;
    Coordinates Key;
    Entity *human;
    Entity * Monkey;

};

#endif // ROUTE_H
