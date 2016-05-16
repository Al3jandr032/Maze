#include "matrix.h"


Matrix::Matrix(unsigned int m,unsigned int n)
{
    this->m = m;
    this->n = n;
    maze.resize(m);
    for (size_t i = 0; i < m; i++) {
        maze[i].resize(n);
    }
    this->precedence = NULL;
    this->loaded = false;
}

Matrix::~Matrix()
{
    //for(unsigned int i =0;i < this->m ;i++)
    //  delete this->maze[i];
}

void Matrix::setValueAt(int m, int n, Casilla *value)
{
    this->maze[m][n] = value;
}

Casilla *Matrix::getValueAt(int m, int n)
{
    return this->maze[m][n];
}

Casilla *Matrix::getValueAt(Coordinates c)
{
    return this->maze[c.getX()][c.getY()];
}

Coordinates Matrix::getInicialPoint()
{
    return this->inicialPoint;
}

void Matrix::setInicialPoint(Coordinates ip)
{
    this->inicialPoint = ip;
}

Coordinates Matrix::getFinalPoint()
{
    return this->finalPoint;
}

void Matrix::setFinalPoint(Coordinates fp)
{
    this->finalPoint = fp;
}

Coordinates Matrix::getDarkTeample()
{
    return this->dt;
}

void Matrix::setDarkTeample(Coordinates fp)
{
    this->dt = fp;
}

Coordinates Matrix::getKey()
{
    return this->key;
}

void Matrix::setKey(Coordinates fp)
{
    this->key = fp;
}

unsigned int Matrix::getm()
{
    return this->m;
}

unsigned int Matrix::getn()
{
    return this->n;
}

void Matrix::print()
{
    for(unsigned int i = 0; i < m ; i++){
        for(unsigned int j = 0; j < n ; j++)
            qDebug() << this->maze[i][j]->getType();
        qDebug() << endl;
    }

}

bool Matrix::isLoaded()
{
    return this->loaded;
}

void Matrix::Load(bool in)
{
    this->loaded = in;
}

void Matrix::setPoint(Coordinates c)
{
    this->setFinalPoint(c);

    emit ChangeActiveBox(c);
}




