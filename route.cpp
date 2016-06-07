#include "route.h"

Route::Route()
{
    this->p = nullptr;
    this->a = new QVector<unsigned int>();
    this->b = new QVector<unsigned int>();
}

Route::Route(Points *p)
{
    this->p = p;
    this->a = new QVector<unsigned int>();
    this->b = new QVector<unsigned int>();
}

Route::~Route()
{
    a->clear();
    b->clear();
    delete p;
    delete a;
    delete b;
}

void Route::calc()
{
    this->calcHuman(new Human());
    this->calcOcto(new Octopus());
    qDebug() << "Is done check this out"<< endl;
    a->push_back(a->at(1)+a->at(5));
    a->push_back(a->at(2)+a->at(6));
    a->push_back(a->at(1)+a->at(3)+a->at(6));
    a->push_back(a->at(2)+a->at(4)+a->at(5));
    b->push_back(b->at(1)+b->at(5));
    b->push_back(b->at(2)+b->at(6));
    b->push_back(b->at(1)+b->at(3)+b->at(6));
    b->push_back(b->at(2)+b->at(4)+b->at(5));
}

void Route::setPoints(Points *p)
{
    this->p = p;
}

Points *Route::getPoints()
{
    return this->p;
}

void Route::calcHuman(Entity *entity)
{
    this->setEntity(entity);
    unsigned int aux;
    aux = this->Solve(p->getHuman(),p->getPortal());
    a->push_back(aux);
    //inicial- key
    aux = this->Solve(p->getHuman(),p->getKey());
    a->push_back(aux);
    //inicial dark temple
    aux = this->Solve(p->getHuman(),p->getDark());
    a->push_back(aux);
    //Key to dark
    aux = this->Solve(p->getKey(),p->getDark());
    a->push_back(aux);
    //Dark to key
    aux = this->Solve(p->getDark(),p->getKey());
    a->push_back(aux);
    //Key to portal
    aux = this->Solve(p->getKey(),p->getPortal());
    a->push_back(aux);
    //Dark to portal
    aux = this->Solve(p->getDark(),p->getPortal());
    a->push_back(aux);

}

void Route::calcOcto(Entity *entity)
{
    this->setEntity(entity);
    unsigned int aux;//IP
    //incial to portal
    aux = this->Solve(p->getOctopus(),p->getPortal());
    b->push_back(aux);
    //inicial- key
    aux = this->Solve(p->getOctopus(),p->getKey());
    b->push_back(aux);
    //inicial dark temple
    aux = this->Solve(p->getOctopus(),p->getDark());
    b->push_back(aux);
    //Key to dark
    aux = this->Solve(p->getKey(),p->getDark());
    b->push_back(aux);
    //Dark to key
    aux = this->Solve(p->getDark(),p->getKey());
    b->push_back(aux);
    //Key to portal
    aux = this->Solve(p->getKey(),p->getPortal());
    b->push_back(aux);
    //Dark to portal
    aux = this->Solve(p->getDark(),p->getPortal());
    b->push_back(aux);
}


