#include "astar.h"


AStar::AStar()
{
    this->p = new Precedence();
    this->close.clear();
    this->open.clear();
    this->entity = new Monkey();
    this->foundFinalPoint = false;
}

void AStar::setEntity(Entity *entity)
{
    this->entity = entity;
}

Entity *AStar::getEntity()
{
    return this->entity;
}

void AStar::solve()
{
    qDebug() << "Solving with a star" << endl;
    Nodo *nodoaux;
    Nodo *n;
    /************************************************/
    this->a = new Arbol();
    this->current =  this->m->getInicialPoint();
    nodoaux = new Nodo(NULL,this->current);
    nodoaux->setCosto(this->entity->getCost(this->m->getValueAt(current)->getType()));
    nodoaux->setDistancia(this->calcDistance(this->m->getFinalPoint(),nodoaux->getValue()));
    nodoaux->calcTotal();
    this->a->addNewNode(nodoaux);
    this->open.insert(nodoaux);
    /************************************************/
    while(!this->open.isEmpty() ){
        nodoaux = this->getMin();
        this->open.remove(nodoaux);
        addLevel(nodoaux);
        if(this->m->getFinalPoint().Comp(nodoaux->getValue())){
            this->foundFinalPoint = true;
            break;
        }
        for(unsigned int i =0; i < nodoaux->getNodes()->size();i++){
            n = nodoaux->getNodes()->at(i);
            if(this->m->getFinalPoint().Comp(n->getValue())){
                this->foundFinalPoint = true;
                break;
            }else{
                qDebug() << "Buscando " << endl;
                if(this->CheckNodo(this->close,n)){
                    continue;
                }
                if(this->CheckNodo(this->open,n)){
                    continue;
                }
                this->open.insert(n);
            }
        }
        this->m->getValueAt(nodoaux->getValue())->View(true);
        this->close.insert(nodoaux);
        if(this->foundFinalPoint)
            break;

    }
    while(n->getPadre() != NULL){
        this->m->getValueAt(n->getValue())->Path(true);
        n = n->getPadre();
    }
    emit updateMaze();
    qDebug() << "termine" << endl;
    this->exportTree();
    this->a->print();

}

unsigned int AStar::Solve(Coordinates a, Coordinates b)
{
    unsigned int costo=0;
    QSet<Nodo *>::iterator iter;
    qDebug() << "Solving with a star" << endl;
    this->close.clear();
    this->open.clear();
    Nodo *nodoaux,*nodoset;
    Nodo *n;
    /************************************************/
    this->a = new Arbol();
    this->current =  a;
    nodoaux = new Nodo(NULL,this->current);
    nodoaux->setCosto(this->entity->getCost(this->m->getValueAt(current)->getType()));
    nodoaux->setDistancia(this->calcDistance(this->m->getFinalPoint(),nodoaux->getValue()));
    nodoaux->calcTotal();
    this->a->addNewNode(nodoaux);
    this->open.insert(nodoaux);
    /************************************************/
    while(!this->open.isEmpty() ){
        nodoaux = this->getMin();
        this->open.remove(nodoaux);
        addLevel(nodoaux);

        if(b.Comp(nodoaux->getValue())){
            this->foundFinalPoint = true;
            break;
        }
        for(unsigned int i =0; i < nodoaux->getNodes()->size();i++){
            n = nodoaux->getNodes()->at(i);
            if(b.Comp(n->getValue())){
                this->foundFinalPoint = true;
                break;
            }else{
                qDebug() << "Buscando " << endl;
                if(this->CheckNodo(this->close,n)){
                    continue;
                }
                if(this->CheckNodo(this->open,n)){
                    continue;
                }
                this->open.insert(n);
            }
        }
        this->m->getValueAt(nodoaux->getValue())->View(true);
        this->close.insert(nodoaux);
        if(this->foundFinalPoint)
            break;

    }
    emit updateMaze();
    qDebug() << "termine" << endl;
    //emit updateMaze();

    while(n->getPadre() != NULL){
        qDebug() <<n->getValue().getX() << "."<< n->getValue().getY()<< endl;
        costo += n->getCosto();
        n = n->getPadre();
    }

    return costo;
}

Nodo* AStar::Search(Nodo *nodoaux,Coordinates cooraux)
{
    Nodo *naux;

    if(checkMove(current)){  // si me puedo mover
        if(this->m->getFinalPoint().Comp(this->current)){
            this->foundFinalPoint = true;
            emit updateMaze();
            return nodoaux;
        }

        this->addLevel(nodoaux);

        // moverse
        cooraux = this->inverseMapping(nodoaux); // nuevas coordenadas del siguiente punto
        emit updateMaze();
        naux = new Nodo(nodoaux,cooraux);
        if(!this->current.Comp(cooraux)){
            this->current = cooraux;
            return naux;
        }
    }
    return NULL;
}

void AStar::addLevel(Nodo *nodoaux)
{
    Nodo *n;
    Coordinates newcord;
    Adyacent *ady = this->maping(nodoaux->getValue());
    this->p->setNodes(ady);
   this->a->addCurrent(nodoaux);
    if(ady->getUp() >= 1 ){

        newcord = nodoaux->getValue();
        newcord.setY(nodoaux->getValue().getY() - 1);
        if(!this->m->getValueAt(newcord.getX(),newcord.getY())->isView()){
            qDebug() << " add new node up "<< endl;
            n = new Nodo(nodoaux,newcord);
            n->setCosto(this->entity->getCost(this->m->getValueAt(newcord)->getType()) + nodoaux->getCosto());
            n->setDistancia(this->calcDistance(this->m->getFinalPoint(),newcord));
            n->calcTotal();
            this->a->addNode(n);
            //this->open.insert(n);
        }

    }
    if(ady->getDown() >= 1 ){
        newcord = nodoaux->getValue();
        newcord.setY(nodoaux->getValue().getY() + 1);
        if(!this->m->getValueAt(newcord.getX(),newcord.getY())->isView()){
            qDebug() << " add new node Down "<< endl;
            n = new Nodo(nodoaux,newcord);
            n->setCosto(this->entity->getCost(this->m->getValueAt(newcord)->getType()) + nodoaux->getCosto());
            n->setDistancia(this->calcDistance(this->m->getFinalPoint(),newcord));
            n->calcTotal();
            this->a->addNode(n);
            //this->open.insert(n);
        }
    }
    if(ady->getLeft() >= 1 ){
        newcord = nodoaux->getValue();
        newcord.setX(nodoaux->getValue().getX() -1);
        if(!this->m->getValueAt(newcord.getX(),newcord.getY())->isView()){
            qDebug() << " add new node left "<< endl;
            n = new Nodo(nodoaux,newcord);
            n->setCosto(this->entity->getCost(this->m->getValueAt(newcord)->getType()) + nodoaux->getCosto());
            n->setDistancia(this->calcDistance(this->m->getFinalPoint(),newcord));
            n->calcTotal();
            this->a->addNode(n);
            //this->open.insert(n);
        }
    }
    if(ady->getRight() >= 1 ){
        newcord = nodoaux->getValue();
        newcord.setX(nodoaux->getValue().getX() + 1);
        if(!this->m->getValueAt(newcord.getX(),newcord.getY())->isView()){
            qDebug() << " add new node right "<< endl;
            n = new Nodo(nodoaux,newcord);
            n->setCosto(this->entity->getCost(this->m->getValueAt(newcord)->getType()) + nodoaux->getCosto());
            n->setDistancia(this->calcDistance(this->m->getFinalPoint(),newcord));
            n->calcTotal();
            this->a->addNode(n);
            //this->open.insert(n); buscar si existe con la misma posicion
        }
    }
    this->close.insert(nodoaux);
    //checar si esta en abierto y quitarlo
}

bool AStar::CheckNodo(QSet<Nodo *> set,Nodo *n)
{
    bool check = false;
    QSet<Nodo *>::iterator i;
    Nodo *nodoaux;
    for (i = set.begin(); i != set.end(); ++i){
        nodoaux = *i;
        if(n->getValue().Comp(nodoaux->getValue()) ){
            if( nodoaux->getTotal() < n->getTotal() ){
                check = true;
            }
        }

    }
    return check;
}

Nodo *AStar::getMin()
{
    QSet<Nodo *>::iterator i;
    Nodo *nodoaux;
    unsigned int aux_min =0;
    for (i = open.begin(); i != open.end(); ++i){
        nodoaux = *i;
        if(i == open.begin() )
            aux_min = nodoaux->getTotal();
        else if(aux_min > nodoaux->getTotal() ){
            aux_min = nodoaux->getTotal();
        }
    }

    for (i = open.begin(); i != open.end(); ++i){
        nodoaux = *i;
        if(aux_min == nodoaux->getTotal() ){
            open.remove(nodoaux);
            return nodoaux;
        }

    }
    return NULL;
}

Coordinates AStar::inverseMapping(Nodo *auxNodo) // adaptar para recibir el nodo
{
    Coordinates auxc;
    Nodo *nodo,*nodoset;
    QSet<Nodo *>::iterator iter;
    int cont =0,aux=0;
    if(auxNodo->getTotal() > 0)
        cont = auxNodo->getTotal();
    for(unsigned int i =0;i < auxNodo->getNodes()->size();i++){
        nodo = auxNodo->getNodes()->at(i);
        aux = nodo->getTotal();

        this->m->getValueAt(nodo->getValue().getX(),nodo->getValue().getY())->View(true);
        if( cont == 0){
            cont = aux;
        }else{
            if(cont > aux)
                cont = aux;
        }
    }
    for(unsigned int i =0;i < auxNodo->getNodes()->size();i++){
        nodo = auxNodo->getNodes()->at(i);
        aux = nodo->getTotal();
        if( cont == aux ){
            for (iter = open.begin(); iter != open.end(); ++iter){
                nodoset = *iter;
                if(nodoset->getTotal() < nodo->getTotal()){
                    if(!this->foundFinalPoint)
                        this->m->getValueAt(nodoset->getValue().getX(),nodoset->getValue().getY())->Path(true);
                    this->open.remove(nodoset);
                    this->close.insert(nodoset);
                    return nodoset->getValue();
                }
            }
            if(!this->foundFinalPoint)
                this->m->getValueAt(nodo->getValue().getX(),nodo->getValue().getY())->Path(true);
            this->close.insert(nodo);
            return nodo->getValue();
        }
    }
    return auxc;
}





unsigned int AStar::calcDistance(Coordinates a, Coordinates b)
{
    unsigned int aux1,aux2;
    aux1=0;
    aux2=0;
    if(a.getX() >=  b.getX()){
        aux1 = a.getX() - b.getX();
    }else if(a.getX() <=  b.getX()){
        aux1 = b.getX() - a.getX();
    }
    if(a.getY() >=  b.getY()){
        aux2 = a.getY() - b.getY();
    }else if(a.getY() <=  b.getY()){
        aux2 = b.getY() - a.getY();
    }
    return aux1 + aux2;
}

unsigned int AStar::CalcTotal(int type_t, Coordinates c)
{   //falta establecer los costos
    int a = this->entity->getCost(type_t);
    int b = this->calcDistance(this->m->getFinalPoint(),c);
    return a + b;
}
