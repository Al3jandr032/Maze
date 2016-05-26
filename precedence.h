#ifndef PRECEDENCE_H
#define PRECEDENCE_H
#include <QDebug>
#include "adyacent.h"

class Precedence
{
public:
    Precedence();
    void setNodes(Adyacent* in);
    Adyacent* getNodes(void);
    int move();
    bool isDecision();
private:
    Adyacent * nodes; // node values
    bool decisionPoint();
    short int precd;

};

#endif // PRECEDENCE_H
