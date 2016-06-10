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

Coordinates Points::getCroc()
{
    return this->inicialCroc;
}

void Points::setCroc(Coordinates fp)
{
    this->inicialCroc = fp;
}

Coordinates Points::getSasq()
{
    return this->inicialSasq;
}

void Points::setSasq(Coordinates fp)
{
    this->inicialSasq = fp;
}

Coordinates Points::getWolf()
{
    return this->inicialwolf;
}

void Points::setWolf(Coordinates fp)
{
    this->inicialwolf = fp;
}

Coordinates Points::getMonkey()
{
    return this->incialMonkey;
}

void Points::setMonkey(Coordinates fp)
{
    this->incialMonkey= fp;
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

Coordinates Points::getStones()
{
    return this->stones;
}

void Points::setStones(Coordinates fp)
{
    this->stones = fp;
}

Coordinates Points::getFriend()
{
    return this->f;
}

void Points::setFriend(Coordinates fp)
{
    this->f = fp;
}

Coordinates Points::getA()
{
    return this->a;
}

void Points::setA(Coordinates fp)
{
    this->a = fp;
}

Coordinates Points::getB()
{
    return this->b;
}

void Points::setB(Coordinates fp)
{
    this->b= fp;
}

Coordinates Points::getC()
{
    return this->c;
}

void Points::setC(Coordinates fp)
{
    this->c= fp;
}
