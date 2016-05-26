#include "precedence.h"

Precedence::Precedence()
{
    precd = 1;
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
    switch(this->precd){
    case 1  :
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
        break; // arriba-abajo-izq-der
    case 2  :
        if(nodes->canMove()){
            if(this->nodes->getDown() == 1){
                aux = 1;
            }else if(this->nodes->getUp() == 1){
                aux = 2;
            }else if(this->nodes->getLeft() == 1){
                aux = 3;
            }else if(this->nodes->getRight() == 1){
                aux = 4;
            }
        }
        break; // arriba-abajo-izq-der
    case 3  :
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
        break; // arriba-abajo-izq-der
    case 4  :
        if(nodes->canMove()){
            if(this->nodes->getLeft() == 1){
                aux = 1;
            }else if(this->nodes->getDown() == 1){
                aux = 2;
            }else if(this->nodes->getUp() == 1){
                aux = 3;
            }else if(this->nodes->getRight() == 1){
                aux = 4;
            }
        }
        break; // arriba-abajo-izq-der
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
