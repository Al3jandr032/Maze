#ifndef ROUTE_H
#define ROUTE_H
#include "astar.h"
#include "points.h"
#include "octopus.h"
#include "human.h"
#include "monkey.h"
#include "croc.h"
#include "sasquatch.h"
#include "werewolf.h"
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
    unsigned int getCosto();
    QString getHuman();
    QString getOctopus();
private:
    void calcEntity(Entity *entity,Coordinates c,QVector<unsigned int> *v);
    void calcEntity(Entity *entity,QVector<unsigned int> *v);
    Points *p;
    QVector<unsigned int> *a,*b,*c,*d,*e,*f;
    unsigned int costo;
    void clear();
    void compare();
    QString humanTask,octopustask,monkeytask,croctask,sasquatchtask,werewolftask;


};

#endif // ROUTE_H
