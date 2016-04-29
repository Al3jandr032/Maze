#include "casilla.h"


Casilla::Casilla()
{
    type = 0;
    view = false;
    finalp = false;
    inicialp = false;
    path = false;
    current = false;
}

void Casilla::setInitPoint(){
    qDebug() << "Set inicial point slot called"<< endl;
}
Coordinates Casilla::mapToCoordinates()
{
    Coordinates c;
    int qx,qy;
    if(this->x() > 0)
        qx = this->x()/37;
    else
        qx = this->x();
    if(this->y() > 0)
        qy = this->y()/37;
    else
        qy = this->y();
    c.setX(qx);
    c.setY(qy);
    return c;
}

void Casilla::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() <<event->type() << endl;
    Coordinates c;
    c = this->mapToCoordinates();
    this->setFocus();
    emit focusSignal(c);
}



void Casilla::setType(int type)
{
    this->type = type;
}

int Casilla::getType()
{
    return this->type;
}

bool Casilla::isView()
{
    return this->view;
}

void Casilla::View(bool in)
{
    this->view = in;
}

bool Casilla::isInicialPoint()
{
    return this->inicialp;
}

void Casilla::InicialPoint(bool in)
{
    this->inicialp = in;
}

bool Casilla::isFinalPoint()
{
    return this->finalp;
}

void Casilla::FinalPoint(bool in)
{
    this->finalp = in;
}

void Casilla::Path(bool in)
{
    this->path = in;
}

bool Casilla::isPath()
{
    return this->path;
}

void Casilla::Current(bool in)
{
    current = in;
}

bool Casilla::isCurrent()
{
    return current;
}

void Casilla::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "hi Key press "<< event->key()<< endl;
    switch(event->key())
       {
       case Qt::Key_Up:
            qDebug() << "up";
           emit move(this->mapToCoordinates(),1);
           break;
       case Qt::Key_Down:
        qDebug() << "down";
           emit move(this->mapToCoordinates(),2);
           break;
       case Qt::Key_Left:
        qDebug() << "left";
           emit move(this->mapToCoordinates(),3);
           break;
       case Qt::Key_Right:
            qDebug() << "Right";
           emit move(this->mapToCoordinates(),4);
           break;
       default:
           event->ignore();
           break;

    }
}
