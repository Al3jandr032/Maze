#ifndef COORDINATES_H
#define COORDINATES_H

#include <QString>

class Coordinates
{

private:
    unsigned int x,y;

public:
    Coordinates();

    Coordinates(unsigned int x,unsigned int y);

    unsigned int getX(void);

    unsigned int getY(void);

    void setX(unsigned int in);

    void setY(unsigned int in);

    bool Comp(Coordinates b);

    QString text();
};

#endif // COORDINATES_H
