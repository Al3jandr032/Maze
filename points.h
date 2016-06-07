#ifndef POINTS_H
#define POINTS_H
#include "coordinates.h"

class Points
{
public:
    Points();
    Points(Coordinates  h,Coordinates o,Coordinates k,Coordinates p,Coordinates d);
    Coordinates getHuman();
    void setHuman(Coordinates fp);
    Coordinates getOctopus();
    void setOctopus(Coordinates fp);
    Coordinates getKey();
    void setkey(Coordinates fp);
    Coordinates getPortal();
    void setPortal(Coordinates fp);
    Coordinates getDark();
    void setDark(Coordinates fp);
private:
    Coordinates inicialHuman,inicialOctopus,key,portal,dark;
};

#endif // POINTS_H
