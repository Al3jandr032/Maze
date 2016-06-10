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
    this->calcEntity( new Human(), this->p->getHuman(),this->a );
    this->calcEntity( new Octopus(), this->p->getOctopus(),this->b);
    this->calcEntity( new Monkey(), this->p->getMonkey(),this->c);
    this->calcEntity( new Croc(), this->p->getCroc(),this->d);
    this->calcEntity( new Sasquatch(), this->p->getSasq(),this->e);
    this->calcEntity( new Werewolf(), this->p->getWolf(),this->f);
    qDebug() << "Is done check this out"<< endl;


    //this->compare();
}

void Route::compare()
{
    if(a->at(10) > b->at(10)){
        if(a->at(10) < a->at(9)){
            this->humanTask = "I-D-K-P";
            this->octopustask = "I-P";
            costo = a->at(10) + b->at(0);
        }else{
            this->humanTask = "I-K-D-P";
            this->octopustask = "I-P";
            costo = a->at(9) + b->at(0);
        }
    }else{
        if(b->at(10) < b->at(9)){
            this->humanTask = "I-P";
            this->octopustask = "I-D-K-P";
            costo = b->at(10) + a->at(0);
        }else{
            this->humanTask = "I-P";
            this->octopustask =  "I-K-D-P";
            costo = b->at(9) + a->at(0);
        }
    }
}

void Route::setPoints(Points *p)
{
    this->p = p;
}

Points *Route::getPoints()
{
    return this->p;
}

unsigned int Route::getCosto()
{
    return this->costo;
}

QString Route::getHuman()
{
    return this->humanTask;
}

QString Route::getOctopus()
{
    return this->octopustask;
}

void Route::calcEntity(Entity *entity, Coordinates c,QVector<unsigned int> *v)
{
    this->setEntity(entity);
    unsigned int aux;
    aux = this->Solve(c,p->getPortal());
    clear();
    v->push_back(aux);
    //inicial- key
    aux = this->Solve(c,p->getKey());
    clear();
    v->push_back(aux);
    //inicial dark temple
    aux = this->Solve(c,p->getDark());
    clear();
    v->push_back(aux);
    //Key to dark
    aux = this->Solve(p->getKey(),p->getDark());
    clear();
    v->push_back(aux);
    //Dark to key
    aux = this->Solve(p->getDark(),p->getKey());
    clear();
    v->push_back(aux);
    //Key to portal
    aux = this->Solve(p->getKey(),p->getPortal());
    clear();
    v->push_back(aux);
    //Dark to portal
    aux = this->Solve(p->getDark(),p->getPortal());
    clear();
    v->push_back(aux);
    //calcular combinados
    v->push_back(v->at(1)+v->at(5));
    v->push_back(v->at(2)+v->at(6));
    v->push_back(v->at(1)+v->at(3)+v->at(6));
    v->push_back(v->at(2)+v->at(4)+v->at(5));
}

void Route::calcEntity(Entity *entity, QVector<unsigned int> *v)
{
    this->setEntity(entity);
    unsigned int aux;
    /******************************************/
    aux = this->Solve(p->getA(),p->getKey());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getA(),p->getDark());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getA(),p->getStones());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getA(),p->getFriend());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getA(),p->getPortal());
    clear();
    v->push_back(aux);
    /*--------------------------------------------*/
    /******************************************/
    aux = this->Solve(p->getB(),p->getKey());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getB(),p->getDark());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getB(),p->getStones());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getB(),p->getFriend());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getB(),p->getPortal());
    clear();
    v->push_back(aux);
    /*----------------------------------------*/
    /******************************************/
    aux = this->Solve(p->getC(),p->getKey());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getC(),p->getDark());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getC(),p->getStones());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getC(),p->getFriend());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getC(),p->getPortal());
    clear();
    v->push_back(aux);
    /*********************************/

    /******************************************/
    aux = this->Solve(p->getKey(),p->getA());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getKey(),p->getB());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getKey(),p->getC());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getKey(),p->getDark());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getKey(),p->getStones());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getKey(),p->getFriend());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getKey(),p->getPortal());
    clear();
    v->push_back(aux);


    /******************************************/
    aux = this->Solve(p->getDark(),p->getA());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getDark(),p->getB());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getDark(),p->getC());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getDark(),p->getKey());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getDark(),p->getStones());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getDark(),p->getFriend());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getDark(),p->getPortal());
    clear();
    v->push_back(aux);


    /******************************************/
    aux = this->Solve(p->getStones(),p->getA());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getStones(),p->getB());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getStones(),p->getC());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getStones(),p->getKey());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getStones(),p->getDark());
    clear();
    v->push_back(aux);

    /******************************************/
    aux = this->Solve(p->getStones(),p->getFriend());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getStones(),p->getPortal());
    clear();
    v->push_back(aux);


    /******************************************/
    aux = this->Solve(p->getFriend(),p->getA());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getFriend(),p->getB());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getFriend(),p->getC());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getFriend(),p->getKey());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getFriend(),p->getDark());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getFriend(),p->getStones());
    clear();
    v->push_back(aux);
    /******************************************/
    aux = this->Solve(p->getFriend(),p->getPortal());
    clear();
    v->push_back(aux);
}

void Route::clear()
{
    for(unsigned int i=0;i<m->getm();i++){
        for(unsigned int j=0;j<m->getn();j++){
            this->m->getValueAt(i,j)->View(false);
        }

    }
}



