#include "human.h"

Human::Human()
{
    this->Hash_cost.insert(1,Human::Mountain);
    this->Hash_cost.insert(2,Human::Earth);
    this->Hash_cost.insert(3,Human::Water);
    this->Hash_cost.insert(4,Human::Sand);
    this->Hash_cost.insert(5,Human::Forest);
    this->Hash_cost.insert(6,Human::Swamp);
    this->Hash_cost.insert(7,Human::Snow);
}
