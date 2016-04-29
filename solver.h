#ifndef SOLVER_H
#define SOLVER_H

#include <QObject>
#include <QDebug>
#include "matrix.h"
#include "coordinates.h"
#include "casilla.h"
#include "precedence.h"
#include "adyacent.h"
#include "arbol.h"

class Solver: public QObject
{
    Q_OBJECT
protected:
    Coordinates current;
    Precedence *p;
    Matrix *m;
    Arbol *a;
    void move(void);
    Adyacent * maping(Coordinates c);
    Coordinates inverseMapping();
    Coordinates invMapping(Coordinates c);
    int checkMove(Coordinates c);
    bool noMoreChilds(Nodo *n);
    bool show(Casilla *casilla);
public:
    Solver();
    ~Solver();
    void setMatrix(Matrix *m);
    virtual void solve();
    void solveManual();
signals:
    void moveOneStep();
    void updateMaze();

public slots:
    void on_move(Coordinates c,unsigned short int dir);
};

#endif // SOLVER_H
