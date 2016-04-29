#ifndef IDF_H
#define IDF_H


#include <QObject>
#include "dfs.h"

class IDF: public DFS
{
    Q_OBJECT
public:
    IDF();
    void solve();
    void setIP(unsigned int i,unsigned int p);
private:
    unsigned int profIterativa,profInicial,contProfIterativa,contProfInicial;
    unsigned int profundidad;
};

#endif // IDF_H
