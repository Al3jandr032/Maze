#include "idf.h"

IDF::IDF()
{

}

void IDF::setIP(unsigned int i,unsigned int p)
{
    this->profInicial = i;
    this->profIterativa = p;
}

void IDF::solve()
{
    Nodo *nodoaux;

    this->contProfInicial = 0;

    this->setIP(1,1);
    this->profundidad =0;
    /************************************************/
    this->foundFinalPoint = false;
    this->a = new Arbol();
    this->current =  this->m->getInicialPoint();
    nodoaux = new Nodo(NULL,this->current);
    this->a->addNewNode(nodoaux);
    /************************************************/
    this->Search(nodoaux);
    this->contProfInicial++;
    while(contProfInicial < this->profInicial){
        anchura(nodoaux);
        this->contProfInicial++;
    }

    while(! this->foundFinalPoint ){
        qDebug() << "utilizar mas iteraciones" << endl;
        this->contProfIterativa = 0;
        while(contProfIterativa < this->profIterativa){
            anchura(nodoaux);
            this->contProfIterativa++;
        }
    }
    /************************************************/

    qDebug() << " end of while" << endl;
    this->exportTree();

}


