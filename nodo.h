#ifndef NODO_H
#define NODO_H
#include <QDebug>
#include <vector>
using std::vector;
#include "casilla.h"


class Nodo
{
private:
    vector<Nodo *> *index;

protected:
    Coordinates value;
    Nodo* parent;
    bool leaf;
    bool done;
    unsigned int Total;
    unsigned int costo;
    unsigned int distancia;
    char label;

public:
    Nodo(Nodo *padre);
    Nodo(Nodo *padre,Coordinates value);
    Nodo(Coordinates value,bool in);
    ~Nodo(void);
    /*
     * Operaciones con el valor que almacena el nodo
    */
    Coordinates getValue(void);
    void addValue(Coordinates in);
    /*
     * Operaciones con el padre del nodo si existe(Nodo raiz)
    */
    Nodo* getPadre(void);
    void setPadre(Nodo* a);
    /*
    *
    * parametro done
    */
    bool isDone(void);
    void setDone(bool done);
    /*
     * Operaciones con los nodos hijos del arbol
    */
    vector<Nodo *>* getNodes(void);

    void addNode(Nodo * nodo);

    bool isleaft(void);

    void printNodes();

    bool Compare(Nodo *n);
    void calcTotal();

    void setTotal(unsigned int t);

    unsigned int getTotal();

    void setCosto(unsigned int t);

    unsigned int getCosto();

    void setDistancia(unsigned int t);

    unsigned int getDistancia();
    /*
    *   operacion con label
    *
    ****************/
    void setLable(char in);
    char getLabel(void);
};

#endif // NODO_H
