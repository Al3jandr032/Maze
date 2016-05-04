#include "dfs.h"

DFS::DFS()
{
    this->p = new Precedence();
}

void DFS::anchura(Nodo *nodoaux){
    Nodo *n;
    Adyacent *adyacent;
    for(unsigned int i=0;i < nodoaux->getNodes()->size();i++){
        n = nodoaux->getNodes()->at(i);
        if(!n->isDone()){
            anchura(n);
        }else{
            adyacent = maping(n->getValue());
            if(adyacent->canMove()){
                this->current = n->getValue();
                this->a->addCurrent(n);
                if(this->m->getFinalPoint().Comp(n->getValue())){
                    this->foundFinalPoint = true;
                    emit updateMaze();
                }
                this->Search(n);
            }
            n->setDone(false);

        }
    }
    return;
}
void DFS::solve()
{
    Nodo *nodoaux;
    Coordinates cooraux;
    /************************************************/
    this->foundFinalPoint = false;
    this->a = new Arbol();
    this->current =  this->m->getInicialPoint();
    nodoaux = new Nodo(NULL,this->current);
    this->a->addNewNode(nodoaux);
    /************************************************/

    Adyacent *ady = this->maping(this->current);
    this->p->setNodes(ady);
    if(p->isDecision()){
        this->Search(nodoaux);
    }else{
        qDebug() << "no es un nodo de decision " << endl;
        while(!p->isDecision()){
            current= this->inverseMapping(); //moverlo hasta la primer decision
            this->checkMove(current);
        }
        this->a->addCurrent(nodoaux);
        nodoaux = new Nodo(nodoaux,this->current);
        this->a->addNode(nodoaux);
        this->a->addCurrent(nodoaux);
        this->Search(nodoaux);
    }


    //relizar una funcion recursiva para buscar los hijos de un nodo dado
    //this->Search(nodoaux);
    while(! this->foundFinalPoint ){
        qDebug() << "seguir" << endl;
        // busca los nodos hijo
        anchura(nodoaux);
        //this->searchInChilds(nodoaux,cooraux);
        //this->foundFinalPoint = true;
    }
    /************************************************/

    qDebug() << " end of while" << endl;
    qDebug()<< this->a->numOfNodes() <<endl;
    this->exportTree();

}

void DFS::Search(Nodo *nodoaux)
{
    if(checkMove(current)){  // si me puedo mover
        if(p->isDecision()){
            qDebug() << "make a new node" << endl;
            if(this->m->getFinalPoint().Comp(this->current)){
                this->foundFinalPoint = true;
                emit updateMaze();
                return;
            } // corregir si se tiene que mover
            this->addLevel(nodoaux);
        }
    }
}



void DFS::addLevel(Nodo *nodoaux)
{
    Nodo *n;
    Coordinates newcord;
    qDebug()<< current.getX() << " : "<<current.getY() << endl;
    Adyacent *ady = this->maping(this->current);
    this->p->setNodes(ady);
    if(ady->getUp() >= 1 ){
        newcord = this->current;
        newcord.setY(this->current.getY() - 1);
        qDebug() << " add new node up "<< endl;
        n = this->move(nodoaux,newcord);
        n->setDone(true);
        this->a->addNode(n);
    }
    if(ady->getDown() >= 1 ){
        newcord = this->current;
        newcord.setY(this->current.getY() + 1);
        qDebug() << " add new node Down "<< endl;
        n = this->move(nodoaux,newcord);
        n->setDone(true);
        this->a->addNode(n);
    }
    if(ady->getLeft() >= 1 ){
        newcord = this->current;
        newcord.setX(this->current.getX() -1);
        qDebug() << " add new node left "<< endl;
        n = this->move(nodoaux,newcord);
        n->setDone(true);
        this->a->addNode(n);
    }
    if(ady->getRight() >= 1 ){
        newcord = this->current;
        newcord.setX(this->current.getX() + 1);
        qDebug() << " add new node right "<< endl;
        n = this->move(nodoaux,newcord);
        n->setDone(true);
        this->a->addNode(n);
    }
}

Nodo* DFS::move(Nodo *nodoaux,Coordinates cord)
{
    Coordinates caux;
    bool find = false;
    this->m->getValueAt(cord.getX(),cord.getY())->View(true);
    while(!find){
        //
        if(this->m->getFinalPoint().Comp(cord)){
            this->foundFinalPoint = true;
            return new Nodo(nodoaux,cord);  //checar esta linea
        }
        if(checkMove(cord)){
            if(p->isDecision()){
                qDebug() << "D node" << endl;
                find = true;
                return new Nodo(nodoaux,cord);
            }else{
                // moverse
                qDebug() << p->move() << endl;
                caux = this->invMapping(cord); // nuevas coordenadas del siguiente punto
                emit updateMaze();
                if(!cord.Comp(caux)){
                    cord = caux;
                }
            }

        }else{
            this->m->getValueAt(cord.getX(),cord.getY())->View(true);
            emit Solver::updateMaze();
            return new Nodo(nodoaux,cord);
        }
    }
    return NULL;

}

Coordinates DFS::invMapping(Coordinates c)
{
    Coordinates aux;
    if(p->move() > 0){
        switch (p->move()) {
        case 1:
           // qDebug() << "arriba "<< endl;

            this->m->getValueAt(c.getX(),c.getY()-1)->View(true);
            aux.setX(c.getX());
            aux.setY(c.getY()-1);
            return aux;
            break;
        case 2:
            //qDebug() << "abajo "<< endl;

            this->m->getValueAt(c.getX(),c.getY()+1)->View(true);
            aux.setX(c.getX());
            aux.setY(c.getY()+1);
            return aux;
            break;
        case 3:
            //qDebug() << "izq"<< endl;

            this->m->getValueAt(c.getX()-1,c.getY())->View(true);
            aux.setX(c.getX()-1);
            aux.setY(c.getY());
            return aux;
            break;
        case 4:
            //qDebug() << "derecha "<< endl;

            this->m->getValueAt(c.getX()+1,c.getY())->View(true);
            aux.setX(c.getX()+1);
            aux.setY(c.getY());
            return aux;
            break;
        default:
            qDebug() << "error al decidir hacia donde continuar"<< endl;
        }

    }
    aux.setX(this->current.getX());
    aux.setY(this->current.getY());
    return aux;
}



