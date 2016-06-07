#ifndef ROUTE_H
#define ROUTE_H
#include "astar.h"
#include "points.h"
#include "octopus.h"
#include "human.h"
#include <QVector>

class Route:public AStar
{
    Q_OBJECT
public:
    Route();
    Route(Points *p);
    ~Route();
    void calc();
    void setPoints(Points *p);
    Points * getPoints(void);
private:
    void calcHuman(Entity *entity);
    void calcOcto(Entity * entity);
    Points *p;
    QVector<unsigned int> *a,*b;
    void clear();


};

#endif // ROUTE_H
