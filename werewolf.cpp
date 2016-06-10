#include "werewolf.h"

Werewolf::Werewolf()
{
    this->Hash_cost.insert(1,Werewolf::Mountain);
    this->Hash_cost.insert(2,Werewolf::Earth);
    this->Hash_cost.insert(3,Werewolf::Water);
    this->Hash_cost.insert(4,Werewolf::Sand);
    this->Hash_cost.insert(5,Werewolf::Forest);
    this->Hash_cost.insert(6,Werewolf::Swamp);
    this->Hash_cost.insert(7,Werewolf::Snow);
}
