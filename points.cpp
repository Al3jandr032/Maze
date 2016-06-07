#include "points.h"

Points::Points()
{

}

Points::Points(Coordinates h, Coordinates o, Coordinates k, Coordinates p, Coordinates d)
{
    this->inicialHuman=h;
    this->inicialOctopus=o;
    this->key = k;
    this->portal = p;
    this->dark = d;
}


Coordinates Points::getHuman(){
    return this->inicialHuman;
}
void Points::setHuman(Coordinates fp){
    this->inicialHuman = fp;
}
Coordinates Points::getOctopus(){
    return this->inicialOctopus;
}
void Points::setOctopus(Coordinates fp){
    this->inicialOctopus = fp;
}
Coordinates Points::getKey(){
    return this->key;
}
void Points::setkey(Coordinates fp){
    this->key = fp;
}
Coordinates Points::getPortal(){
    return this->portal;
}
void Points::setPortal(Coordinates fp){
    this->portal = fp;
}
Coordinates Points::getDark(){
    return this->dark;
}
void Points::setDark(Coordinates fp){
    this->dark = fp;
}
