#ifndef MATRIX_H
#define MATRIX_H


#include <QDebug>
#include <QVector>
#include "casilla.h"
#include "precedence.h"


class Matrix:public QObject
{
    Q_OBJECT

public:
    Matrix(unsigned int m,unsigned int n);
    ~Matrix();
    void setValueAt(int m,int n, Casilla *value);

    Casilla * getValueAt(int m,int n);
    Casilla * getValueAt(Coordinates c);
    Coordinates getInicialPoint();
    void setInicialPoint(Coordinates ip);
    Coordinates getFinalPoint();
    void setFinalPoint(Coordinates fp);
    Coordinates getDarkTeample();
    void setDarkTeample(Coordinates fp);
    Coordinates getKey();
    void setKey(Coordinates fp);
    unsigned int getm();
    unsigned int getn();
    void print(void);
    bool isLoaded();
    void Load(bool in);
public slots:
    void setPoint(Coordinates c);
signals:
    void ChangeActiveBox(Coordinates c);

private:
    //bool **maze; QVector< QVector<Casilla> >
    bool loaded;
    QVector< QVector<Casilla *> > maze;
    Coordinates inicialPoint,finalPoint,dt,key;
    unsigned int m,n;
    Precedence *precedence;

};

#endif // MATRIX_H
