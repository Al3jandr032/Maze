#ifndef ASTAR_H
#define ASTAR_H

#include <QObject>
#include <QSet>
#include <QDebug>
#include "solver.h"
#include "entity.h"
#include "monkey.h"
#include "octopus.h"



class AStar:public Solver
{
    Q_OBJECT
public:
    AStar();
    void solve();
    unsigned int Solve(Coordinates a,Coordinates b);
    void setEntity(Entity *entity);
    Entity * getEntity();
private:
    Entity *entity;
    bool foundFinalPoint;
    QSet<Nodo *> open;
    QSet<Nodo *> close;
    unsigned int calcDistance(Coordinates a,Coordinates b);
    unsigned int CalcTotal(int type_t,Coordinates c);
    Coordinates inverseMapping(Nodo *auxNodo);
    Nodo* Search(Nodo *nodoaux,Coordinates cooraux);
    void addLevel(Nodo *nodoaux,Coordinates final);
    bool CheckNodo(QSet<Nodo *> set,Nodo *n);
    Nodo * getMin();



};

#endif // ASTAR_H
