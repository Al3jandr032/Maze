#include "croc.h"

Croc::Croc()
{
    this->Hash_cost.insert(1,Croc::Mountain);
    this->Hash_cost.insert(2,Croc::Earth);
    this->Hash_cost.insert(3,Croc::Water);
    this->Hash_cost.insert(4,Croc::Sand);
    this->Hash_cost.insert(5,Croc::Forest);
    this->Hash_cost.insert(6,Croc::Swamp);
    this->Hash_cost.insert(7,Croc::Snow);
}
