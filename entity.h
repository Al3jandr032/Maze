#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QHash>
#include "coordinates.h"

class Entity: public QObject
{
    Q_OBJECT
public:
    Entity();
    void setCost(int type_t , int cost);
    int getCost(int type_t);
    void setInicial(Coordinates c);
    Coordinates getInicial();
    void setFinal(Coordinates c);
    Coordinates getFinal();
protected:
    QHash<int, int> Hash_cost;
    Coordinates inicial,final;
};

#endif // ENTITY_H
