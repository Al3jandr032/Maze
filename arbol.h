#ifndef ARBOL_H
#define ARBOL_H
#include <QDebug>
#include <QHash>
#include <QString>
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
    QString toString();
    void preorden(Nodo * n,QString *stream);
    void treeLabel(Nodo *n,QString *stream);
    bool isIn(Nodo *r);
private:
    Nodo *root;
    Nodo* current;
    char label;
    int numBodos;
    void preorden(Nodo * n);

    void buscar(Nodo * n,Nodo * b, bool *s);
};

#endif // ARBOL_H
