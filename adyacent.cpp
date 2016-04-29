#include "adyacent.h"

Adyacent::Adyacent()
{

}

Adyacent::Adyacent(int u, int d, int l, int r)
{
    this->up = u;
    this->down = d;
    this->left = l;
    this->right = r;
}

void Adyacent::setUp(int in){
    this->up = in;
}
int Adyacent::getUp(void){
    return this->up;
}
void Adyacent::setDown(int in){
    this->down = in;
}
int Adyacent::getDown(void){
    return this->down;
}
void Adyacent::setLeft(int in){
    this->left = in;
}
int Adyacent::getLeft(void){
    return this->left;
}
void Adyacent::setRight(int in){
    this->right = in;
}
int Adyacent::getRight(void){
    return this->right;
}
bool Adyacent::canMove(){
    if(up == 0 && down == 0 && left == 0 && right == 0)
        return false;
    else
        return true;
}
