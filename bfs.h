#ifndef BFS_H
#define BFS_H

#include <QObject>
#include "solver.h"

class BFS: public Solver
{
    Q_OBJECT
public:
    BFS();
    void solve();

};

#endif // BFS_H
