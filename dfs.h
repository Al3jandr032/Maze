#ifndef DFS_H
#define DFS_H


#include <QObject>
#include "solver.h"

class DFS: public Solver
{
    Q_OBJECT
public:
    DFS();
    virtual void solve();
protected:
    void addLevel(Nodo *nodoaux);
    Nodo * move(Nodo *nodoaux,Coordinates cord);
    Coordinates invMapping(Coordinates c);
    void Search(Nodo *nodoaux);
    bool foundFinalPoint;
    void anchura(Nodo *n);

};

#endif // DFS_H
