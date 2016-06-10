#include "octopus.h"

Octopus::Octopus()
{
    this->Hash_cost.insert(1,Octopus::Mountain);
    this->Hash_cost.insert(2,Octopus::Earth);
    this->Hash_cost.insert(3,Octopus::Water);
    this->Hash_cost.insert(4,Octopus::Sand);
    this->Hash_cost.insert(5,Octopus::Forest);
    this->Hash_cost.insert(6,Octopus::Swamp);
    this->Hash_cost.insert(7,Octopus::Snow);
}
