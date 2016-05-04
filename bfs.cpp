#include "bfs.h"

BFS::BFS()
{

}



void BFS::solve()
{
    Nodo *nodoaux,*currentNode;
    Coordinates cooraux;
    //int cont=1;

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
            emit updateMaze();
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
                //emit updateMaze();
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
    this->a->addNode(new Nodo(this->a->getCurrent(),this->m->getFinalPoint()));
    qDebug() << " end of while" << endl;
    qDebug()<< this->a->numOfNodes() <<endl;
    this->exportTree();
}




