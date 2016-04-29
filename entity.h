#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QHash>

class Entity: public QObject
{
    Q_OBJECT
public:
    Entity();
    void setCost(int type_t , int cost);
    int getCost(int type_t);
protected:
    QHash<int, int> Hash_cost;
};

#endif // ENTITY_H
