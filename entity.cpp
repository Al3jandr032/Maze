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
