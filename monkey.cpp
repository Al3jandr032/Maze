#include "monkey.h"

Monkey::Monkey()
{
    this->Hash_cost.insert(1,Monkey::Mountain);
    this->Hash_cost.insert(2,Monkey::Earth);
    this->Hash_cost.insert(3,Monkey::Water);
    this->Hash_cost.insert(4,Monkey::Sand);
    this->Hash_cost.insert(5,Monkey::Forest);
    this->Hash_cost.insert(6,Monkey::Swamp);
    this->Hash_cost.insert(7,Monkey::Snow);
}
