#include "coordinates.h"

Coordinates::Coordinates()
{
    this->x = 0;
    this->y = 0;
}

Coordinates::Coordinates(unsigned int x, unsigned int y)
{
    this->x = x;
    this->y = y;
}

unsigned int Coordinates::getX()
{
    return this->x;
}

unsigned int Coordinates::getY()
{
    return this->y;
}

void Coordinates::setX(unsigned int in)
{
    this->x = in;
}

void Coordinates::setY(unsigned int in)
{
    this->y = in;
}

bool Coordinates::Comp(Coordinates b)
{
    if((this->x ==  b.getX()) && (this->y ==  b.getY()) )
        return true;
    else
        return false;
}

QString Coordinates::text()
{
    QString aux;
    aux.append( QString::number(x) );
    aux.append(" , ");
    aux.append( QString::number(y) );
    return  aux;
}
