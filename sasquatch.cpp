#include "sasquatch.h"

Sasquatch::Sasquatch()
{
    this->Hash_cost.insert(1,Sasquatch::Mountain);
    this->Hash_cost.insert(2,Sasquatch::Earth);
    this->Hash_cost.insert(3,Sasquatch::Water);
    this->Hash_cost.insert(4,Sasquatch::Sand);
    this->Hash_cost.insert(5,Sasquatch::Forest);
    this->Hash_cost.insert(6,Sasquatch::Swamp);
    this->Hash_cost.insert(7,Sasquatch::Snow);
}
