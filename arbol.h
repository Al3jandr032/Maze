#ifndef ARBOL_H
#define ARBOL_H
#include <QDebug>
#include <QHash>
#include "nodo.h"



class Arbol
{
public:
    Arbol();
    ~Arbol();

    void addNode(Nodo *r);
    void addNewNode(Nodo *r);

    void addCurrent(Nodo *r);
    Nodo* getCurrent(void);

    void setRoot(Nodo *r);
    Nodo* getRoot(void);


    int numOfNodes();

    void print();
    bool isIn(Nodo *r);
private:
    Nodo *root;
    Nodo* current;
    int numBodos;
    void preorden(Nodo * n);
    void buscar(Nodo * n,Nodo * b, bool *s);
};

#endif // ARBOL_H
