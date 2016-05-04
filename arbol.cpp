#include "arbol.h"


Arbol::Arbol()
{

    this->root = NULL;
    this->numBodos = 0;
    this->current = NULL;
}

Arbol::~Arbol()
{

    delete this->root;
    this->numBodos = 0;
    this->current = NULL;
    delete this->current;
}

void Arbol::addNode(Nodo *r)
{
    current->addNode(r);
    this->numBodos++;
}

void Arbol::addNewNode(Nodo *r)
{
    if(this->root == NULL){
        root = r;
        current = r;
    }else{
        current->addNode(r);
        current = r;
    }


    this->numBodos++;
}




void Arbol::addCurrent(Nodo *r)
{
    this->current = r;
}

Nodo *Arbol::getCurrent()
{
    return this->current;
}

void Arbol::setRoot(Nodo *r)
{
    this->root = r;
    this->numBodos++;
}

Nodo *Arbol::getRoot()
{
    return this->root ;
}



int Arbol::numOfNodes()
{
    return this->numBodos;
}

void Arbol::print()
{
    preorden(this->root);
}

QString Arbol::toString()
{
    QString stream;
    preorden(this->root,&stream);
    return stream;
}

void Arbol::preorden(Nodo * n,QString *qts){
    if(n->isleaft()){
        qts->append( QString::number( n->getValue().getX() ));
        qts->append(":");
        qts->append( QString::number(n->getValue().getY() ) );
        qts->append('\n');
        return;
    }

    qts->append( QString::number( n->getValue().getX() ));
    qts->append(":");
    qts->append( QString::number(n->getValue().getY() ) );
    qts->append('\n');
    for(unsigned int i =0; i<n->getNodes()->size();i++){
        preorden(n->getNodes()->at(i),qts);
    }
}



void Arbol::preorden(Nodo * n){
    if(n->isleaft())
        return;
    if(n->Compare(this->root))
        qDebug() << "Root" ;
    qDebug() << n->getValue().getX() << " : "<< n->getValue().getY() << endl;
    for(unsigned int i =0; i<n->getNodes()->size();i++){
        preorden(n->getNodes()->at(i));
    }
}
void Arbol::buscar(Nodo * n,Nodo * b, bool *s){
    if(n->isleaft())
        return;
    if(n->Compare(b)){
        *s = true;
        return;
    }
    for(unsigned int i =0; i<n->getNodes()->size();i++){
        buscar(n->getNodes()->at(i),b, s);
    }
}
bool Arbol::isIn(Nodo *r)
{
   bool find = false;
   this->buscar(this->root,r,&find);
   return false;
}
