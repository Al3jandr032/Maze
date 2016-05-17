#include "entity.h"

Entity::Entity()
{

}

void Entity::setCost(int type_t, int cost)
{
    this->Hash_cost.insert(type_t,cost);
}

int Entity::getCost(int type_t)
{
    return this->Hash_cost.value(type_t+1);
}

void Entity::setInicial(Coordinates c)
{
    this->inicial = c;
}

Coordinates Entity::getInicial()
{
    return this->inicial;
}

void Entity::setFinal(Coordinates c)
{
    this->final = c;
}

Coordinates Entity::getFinal()
{
    return this->final;
}
