#include "precedence.h"

Precedence::Precedence()
{

}

void Precedence::setNodes(Adyacent *in)
{
    this->nodes = in;
}

Adyacent *Precedence::getNodes()
{
    return this->nodes;
}

int Precedence::move()
{
    int aux = -1;
    //logic to make precedence
    if(nodes->canMove()){
        if(this->nodes->getUp() == 1){
            aux = 1;
        }else if(this->nodes->getDown() == 1){
            aux = 2;
        }else if(this->nodes->getLeft() == 1){
            aux = 3;
        }else if(this->nodes->getRight() == 1){
            aux = 4;
        }
    }

    return aux;
}

bool Precedence::isDecision()
{
    return this->decisionPoint();
}

bool Precedence::decisionPoint()
{
    /*
    qDebug()<< "Up" << this->nodes->getUp() <<endl;
    qDebug()<< "Down" << this->nodes->getDown() <<endl;
    qDebug()<< "Left" << this->nodes->getLeft() <<endl;
    qDebug()<< "Rigth" << this->nodes->getRight() <<endl;
    */
    if(nodes->canMove()){
        if(this->nodes->getUp() >= 1 && this->nodes->getDown() >= 1){
            return true;
        }else if(this->nodes->getUp() >= 1 && this->nodes->getLeft() >= 1){
            return true;
        }else if(this->nodes->getUp() >= 1 && this->nodes->getRight() >= 1){
            return true;
        }else if(this->nodes->getLeft() >= 1 && this->nodes->getRight() >= 1){
            return true;
        }else if(this->nodes->getDown() >= 1 && this->nodes->getUp() >= 1){
            return true;
        }else if(this->nodes->getDown() >= 1 && this->nodes->getLeft() >= 1){
            return true;
        }else if(this->nodes->getDown() >= 1 && this->nodes->getRight() >= 1){
            return true;
        }else
            return false;
    }
    return false;
}
