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
    Coordinates getCroc();
    void setCroc(Coordinates fp);
    Coordinates getSasq();
    void setSasq(Coordinates fp);
    Coordinates getWolf();
    void setWolf(Coordinates fp);
    Coordinates getMonkey();
    void setMonkey(Coordinates fp);
    /****************************************/
    Coordinates getKey();
    void setkey(Coordinates fp);
    Coordinates getPortal();
    void setPortal(Coordinates fp);
    Coordinates getDark();
    void setDark(Coordinates fp);
    Coordinates getStones();
    void setStones(Coordinates fp);
    Coordinates getFriend();
    void setFriend(Coordinates fp);
     /****************************************/
    Coordinates getA();
    void setA(Coordinates fp);
    Coordinates getB();
    void setB(Coordinates fp);
    Coordinates getC();
    void setC(Coordinates fp);
private:
    Coordinates inicialHuman,inicialOctopus,inicialCroc,inicialSasq,inicialwolf,incialMonkey;
    Coordinates key,portal,dark,stones,f;
    Coordinates a,b,c;
};

#endif // POINTS_H
