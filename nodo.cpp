#include "nodo.h"


Nodo::Nodo(Nodo* padre)
{
    this->parent = padre;
    //this->value = NULL;
    this->index = new vector<Nodo *>();
    this->leaf = false;
    this->done = false;
    this->Total =0;
    this->costo =0;
    this->distancia =0;
}

Nodo::Nodo(Nodo* padre, Coordinates value)
{
    this->parent = padre;
    this->value = value;
    this->index = new vector<Nodo *>();
    this->leaf = false;
    this->done = false;
    this->Total =0;
    this->costo =0;
    this->distancia =0;
}

Nodo::Nodo(Coordinates value,bool in)
{
    this->parent = NULL;
    this->value = value;
    this->index = new vector<Nodo *>();
    this->leaf = in;
    this->done = false;
    this->Total =0;
    this->costo =0;
    this->distancia =0;
}

Nodo::~Nodo()
{
    delete this->index;

}

Coordinates Nodo::getValue()
{
    return this->value;
}

void Nodo::addValue(Coordinates in)
{
    this->value = in;
}

Nodo* Nodo::getPadre()
{
    return this->parent;
}

void Nodo::setPadre(Nodo* a)
{
    this->parent = a;
}

bool Nodo::isDone()
{
    return this->done;
}

void Nodo::setDone(bool done)
{
    this->done = done;
}

vector<Nodo *> *Nodo::getNodes()
{
    return this->index;
}

void Nodo::addNode(Nodo * nodo)
{
    this->index->push_back(nodo);
}

bool Nodo::isleaft()
{
   if(this->index->size() == 0)
       return true;
   else
       return false;
}

void Nodo::printNodes()
{
    for(unsigned int i=0; i < index->size(); i++){
       qDebug() << index->at(i) << endl;
    }
}

bool Nodo::Compare(Nodo *n)
{
    if(this->value.Comp(n->getValue()))
        return true;
    else
        return false;
}

void Nodo::calcTotal()
{
    this->Total = this->costo + this->distancia;
}

void Nodo::setTotal(unsigned int t)
{
    this->Total = t;
}

unsigned int Nodo::getTotal()
{
    return this->Total;
}

void Nodo::setCosto(unsigned int t)
{
    this->costo = t;
}

unsigned int Nodo::getCosto()
{
    return this->costo;
}

void Nodo::setDistancia(unsigned int t)
{
    this->distancia = t;
}

unsigned int Nodo::getDistancia()
{
    return this->distancia;
}

void Nodo::setLable(char in)
{
    this->label = in;
}

char Nodo::getLabel()
{
    return this->label;
}
