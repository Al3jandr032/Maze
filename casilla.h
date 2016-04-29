#ifndef CASILLA_H
#define CASILLA_H

#include <QDebug>
#include <QGraphicsRectItem>
#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "coordinates.h"

class Casilla:public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    int  type;
    bool view;
    bool inicialp;
    bool finalp;
    bool path;
    bool current;
    Coordinates mapToCoordinates();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void focusSignal(Coordinates c);
    void move(Coordinates c,unsigned short int dir);
public slots:
    void setInitPoint();

public:
    Casilla();

    Casilla(qreal x, qreal y, qreal width, qreal height)
        :QGraphicsRectItem(x,y,width,height){
        this->setFlag(QGraphicsItem::ItemIsFocusable);
    }

    void keyPressEvent(QKeyEvent * event);

    void setType(int type);

    int getType(void);

    bool isView();

    void View(bool in);

    bool isInicialPoint();

    void InicialPoint(bool in);

    bool isFinalPoint();

    void FinalPoint(bool in);

    void Path(bool in);

    bool isPath();

    void Current(bool in);

    bool isCurrent();
};



#endif // CASILLA_H
