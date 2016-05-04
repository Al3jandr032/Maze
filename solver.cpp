#include "solver.h"


Solver::Solver()
{

}

Solver::~Solver()
{
    delete a;
    this->m = NULL;
    delete m;
}

void Solver::setMatrix(Matrix *m)
{
    this->m = m;
}

void Solver::solve()
{
    Nodo *nodoaux,*currentNode;
    Coordinates cooraux;
    /************************************************/
    this->a = new Arbol();
    this->current =  this->m->getInicialPoint();
    nodoaux = new Nodo(NULL,this->current);
    currentNode = nodoaux;
    this->a->addNewNode(nodoaux);
    /************************************************/
    while(! this->current.Comp(this->m->getFinalPoint()) ){
        qDebug() << "seguir" << endl;

        if(checkMove(current)){
            cooraux = this->inverseMapping(); // nuevas coordenadas del siguiente punto
            if(!this->current.Comp(cooraux)){
                if(p->isDecision()){
                    qDebug() << "make a new node" << endl;
                    currentNode = new Nodo(nodoaux,this->current);

                    if(!this->a->isIn(currentNode)){
                        //this->a->addNode(nodoaux,cont+1);
                        this->a->addNewNode(currentNode);
                        nodoaux = currentNode;
                        //this->a->addCurrent(nodoaux);
                    }
                }
                this->current = cooraux;
                qDebug() << "new curent" << endl;
                emit updateMaze();
            }

        }else{
            qDebug() << "no puedo seguir"<< endl;
            currentNode = new Nodo(this->a->getCurrent(),this->current);
            if(this->noMoreChilds(this->a->getCurrent())){
                this->current = this->a->getCurrent()->getPadre()->getValue();
                this->a->addCurrent( this->a->getCurrent()->getPadre() );
                nodoaux = this->a->getCurrent();
            }else{
                this->current = this->a->getCurrent()->getValue();
            }

            currentNode->setDone(true);
            this->a->addNode(currentNode);
        }

    }
    qDebug() << " end of while" << endl;
    qDebug()<< this->a->numOfNodes() <<endl;

}

void Solver::solveManual()
{
    Coordinates aux;
    aux = this->m->getInicialPoint();
    if(aux.getY() > 0)
        this->show(this->m->getValueAt(aux.getX(),aux.getY()-1));
    if( aux.getY()+1 < this->m->getn())
        this->show(this->m->getValueAt(aux.getX(),aux.getY()+1));
    if(aux.getX() > 0)
        this->show(this->m->getValueAt(aux.getX()-1,aux.getY()));
    if( aux.getX()+1 < this->m->getm())
        this->show(this->m->getValueAt(aux.getX()+1,aux.getY()));
}

void Solver::exportTree()
{
    QString filename = "/home/alex/Documentos/tree2.dot";
    QFile file(filename);
    //Nodo *aux;
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "digraph G {"<< endl;
        stream << this->a->toString() << endl;
        stream << "}" << endl;
    }
    file.close();
}

void Solver::on_move(Coordinates c,unsigned short int dir)
{
    Casilla *aux;
    if(c.getY() > 0)
        this->show(this->m->getValueAt(c.getX(),c.getY()-1));
    if( c.getY()+1 < this->m->getn())
        this->show(this->m->getValueAt(c.getX(),c.getY()+1));
    if(c.getX() > 0)
        this->show(this->m->getValueAt(c.getX()-1,c.getY()));
    if( c.getX()+1 < this->m->getm())
        this->show(this->m->getValueAt(c.getX()+1,c.getY()));
    qDebug() << checkMove(c) <<"dir : "<<dir<< endl;
    switch(dir){
    case 1  :
        if(c.getY() > 0 ){
            aux  = this->m->getValueAt(c.getX(),c.getY()-1);
            if(this->show(aux)){
                aux->setFocus();
                aux->Current(true);
                show(aux);
            }

        }
        break; //optional
    case 2  :
        if( c.getY()+1 < this->m->getn()){
            aux  = this->m->getValueAt(c.getX(),c.getY()+1);
            if(this->show(aux)){
                aux->setFocus();
                aux->Current(true);
                show(aux);
            }
        }

        break; //optional
    case 3  :
        if(c.getX() > 0 ){
            aux = this->m->getValueAt(c.getX()-1,c.getY());
            if(this->show(aux)){
                aux->setFocus();
                aux->Current(true);
                show(aux);
            }
        }

        break; //optional
    case 4  :
        if(c.getX()+1 < this->m->getm()){
            aux = this->m->getValueAt(c.getX()+1,c.getY());
            if(this->show(aux)){
                aux->setFocus();
                aux->Current(true);
                show(aux);
            }
        }

        break; //optional
        // you can have any number of case statements.
    default : //Optional
        qDebug() << "default" << endl;
    }

    aux = this->m->getValueAt(c);
    aux->Current(false);
    this->show(aux);
    emit Solver::updateMaze();
}



Coordinates Solver::inverseMapping() // adaptar para recibir el nodo
{
    Coordinates aux;
    if(p->move() > 0){
        switch (p->move()) {
        case 1:
           // qDebug() << "arriba "<< endl;

            this->m->getValueAt(this->current.getX(),this->current.getY()-1)->View(true);
            aux.setX(this->current.getX());
            aux.setY(this->current.getY()-1);
            return aux;
            break;
        case 2:
            //qDebug() << "abajo "<< endl;

            this->m->getValueAt(this->current.getX(),this->current.getY()+1)->View(true);
            aux.setX(this->current.getX());
            aux.setY(this->current.getY()+1);
            return aux;
            break;
        case 3:
            //qDebug() << "izq"<< endl;

            this->m->getValueAt(this->current.getX()-1,this->current.getY())->View(true);
            aux.setX(this->current.getX()-1);
            aux.setY(this->current.getY());
            return aux;
            break;
        case 4:
            //qDebug() << "derecha "<< endl;

            this->m->getValueAt(this->current.getX()+1,this->current.getY())->View(true);
            aux.setX(this->current.getX()+1);
            aux.setY(this->current.getY());
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

Coordinates Solver::invMapping(Coordinates c)
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

Adyacent* Solver::maping(Coordinates c){
    int u,d,l,r;
    //check limits
    /*
    *   check for Y axis
    *   up and down , to dont go out of index
    */
    // check up
    if(c.getY() > 0 )
        if(!this->m->getValueAt(c.getX(),c.getY()-1)->isView()){
            u = this->m->getValueAt(c.getX(),c.getY()-1)->getType();
        }else{
            u = 0;
        }
    else
        u = 0;
    // check Down
    if(c.getY()+1 < this->m->getn() )
        if( !this->m->getValueAt(c.getX(),c.getY()+1)->isView() ){
            d = this->m->getValueAt(c.getX(),c.getY()+1)->getType();
        }else{
            d =0;
        }
    else
        d = 0;
    /*
    *   check for X axis
    *   up and down , to dont go out of index
    */
    //check for left
    if((unsigned)c.getX() > 0)
        if( !this->m->getValueAt(c.getX()-1,c.getY())->isView() ){
            l = this->m->getValueAt(c.getX()-1,c.getY())->getType();
        }else{
            l =0;
        }
    else
        l = 0;
    //check right
    if((unsigned)c.getX()+1 < this->m->getm())
        if( !this->m->getValueAt(c.getX()+1,c.getY())->isView() ){
            r = this->m->getValueAt(c.getX()+1,c.getY())->getType();
        }else{
            r =0;
        }
    else
        r = 0;

    /********************************/
    /*
    qDebug()<< "Up" << u <<endl;
    qDebug()<< "Down" << d <<endl;
    qDebug()<< "Left" << l <<endl;
    qDebug()<< "Rigth" << r <<endl;
    */
    Adyacent *ady = new Adyacent(u,d,l,r);
    return ady;
}

int Solver::checkMove(Coordinates c)
{
    qDebug() << "cheching for how to move"<< endl;
    /********************************/
    Adyacent *ady = this->maping(c);
    //qDebug() << "set inicial point Matrix's slots x:" << c.getX() << "y: "<< c.getY() << endl;

    this->p = new Precedence();
    this->p->setNodes(ady);
    //qDebug() << "end fo mapping result  " << p->move() << endl;

    return ady->canMove();
}

bool Solver::noMoreChilds(Nodo *n)
{
    Nodo *aux;
    if(n->getNodes()->size() > 0){
        for(unsigned int i =0;i < n->getNodes()->size();i++){
            aux = n->getNodes()->at(i);
            if(!aux->isDone())
                return false;
        }
        n->setDone(true);
        return true;
    }else{
        return false;
    }
}

bool Solver::show(Casilla *casilla)
{

    bool find = true;
    int type_t = casilla->getType();

    if(!casilla->isCurrent()){
        if(type_t == 0){
            casilla->setBrush(Qt::gray);
            find = false;
        }else if(type_t == 1){
            casilla->setBrush(Qt::white);
        }else if(type_t == 2){
            casilla->setBrush(Qt::blue);
        }else if(type_t == 3){
            casilla->setBrush(Qt::yellow);
        }else if(type_t == 4){
            casilla->setBrush(Qt::green);
        }
    }else{
        casilla->setBrush(Qt::red);
    }


    return find;

}

