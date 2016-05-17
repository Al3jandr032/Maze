#include "route.h"

Route::Route()
{
    this->human = new Human();
    this->monkey = new Monkey();
    this->star = new AStar();

}

void Route::setDarkteample(Coordinates c)
{
    this->DT = c;
}

Coordinates Route::getDarkTeample()
{
    return this->DT;
}

void Route::setKey(Coordinates c)
{
    this->Key = c;
}

Coordinates Route::getKey()
{
    return this->Key;
}

void Route::setPortal(Coordinates c)
{
    this->portal = c;
}

Coordinates Route::getPortal()
{
    return this->portal;
}

void Route::setMatrix(Matrix *m)
{
    this->matrix = m;
    this->star->setMatrix(m);
    this->setDarkteample(matrix->getDarkTeample());
    this->setKey(matrix->getKey());
    this->setPortal(matrix->getFinalPoint());
    this->human->setInicial(matrix->getHuman());
    this->monkey->setInicial(matrix->getOcto());
}

Matrix *Route::getMatrix()
{
    return this->matrix;
}

void Route::calc()
{
    QVector<unsigned int> *routes1,*routes2;
    routes1 = this->calcRouteEntity(this->human);
    routes2 = this->calcRouteEntity(this->monkey);
    //star->Solve()
    qDebug() <<"costo de rutas" << endl;
    qDebug() <<"human" << endl;
    for(int i =0;i<routes1->size();i++){
        qDebug() << routes1->at(i) << endl;
    }
    qDebug() <<"monkey" << endl;
    for(int i =0;i<routes2->size();i++){
        qDebug() << routes2->at(i) << endl;
    }
}

QVector<unsigned int> * Route::calcRouteEntity(Entity *ent)
{
    QVector<unsigned int> *routes = new QVector<unsigned int>;
    unsigned int IP,IK,ID,KD,DK,KP,DP;
    star->setEntity(ent);
    IP =star->Solve(ent->getInicial(),this->portal);
    routes->append(IP);
    this->matrix->clear();
    IK =star->Solve(ent->getInicial(),this->Key);
    routes->append(IK);
    this->matrix->clear();
    ID =star->Solve(ent->getInicial(),this->DT);
    routes->append(ID);
    this->matrix->clear();
    KD =star->Solve(this->Key,this->DT);
    routes->append(KD);
    this->matrix->clear();
    DK =star->Solve(this->DT,this->Key);
    routes->append(DK);
    this->matrix->clear();
    KP =star->Solve(this->Key,this->portal);
    routes->append(KP);
    this->matrix->clear();
    DP =star->Solve(this->DT,this->portal);
    routes->append(DP);
    this->matrix->clear();
    return routes;
}
