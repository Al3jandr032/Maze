#ifndef ROUTE_H
#define ROUTE_H
#include "coordinates.h"
#include "human.h"
#include "monkey.h"
#include "astar.h"
#include "matrix.h"
#include <QObject>

class Route
{
public:
    Route();
    void setDarkteample(Coordinates c);
    Coordinates getDarkTeample();
    void setKey(Coordinates c);
    Coordinates  getKey();
    void setPortal(Coordinates c);
    Coordinates getPortal();
    void setMatrix(Matrix *m);
    Matrix* getMatrix();
    void calc();
private:
    Coordinates DT;
    Coordinates Key;
    Coordinates portal;
    Entity *human;
    Entity * monkey;
    AStar *star;
    Matrix *matrix;
    QVector<unsigned int> * calcRouteEntity(Entity *ent);

};

#endif // ROUTE_H
