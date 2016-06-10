#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QVector>
#include <QFileDialog>
#include <QInputDialog>
#include <QGraphicsItem>
#include "casilla.h"
#include "bfs.h"
#include "dfs.h"
#include "idf.h"
#include "astar.h"
#include "matrix.h"
#include "casilla.h"
#include "solver.h"
#include "human.h"
#include "points.h"
#include "route.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void make_move(Coordinates c,unsigned short int dir);
private slots:
    void move(Coordinates c,unsigned short int dir );

    void updateActiveBox(Coordinates c );

    void updateView();

    void updateOne();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionSet_triggered();

    void on_actionInicial_triggered();

    void on_actionFinal_triggered();

    void onClickChangeType();

    void on_actionBredth_First_Search_triggered();

    void on_actionDepth_First_Search_triggered();

    void on_actionIterative_Depth_First_Search_triggered();

    void on_actionA_triggered();

    void on_actionCover_map_triggered();

    void on_actionClear_triggered();

    void on_actionSolve_triggered();

    void on_actionSolve_2_triggered();

    void on_actionSolve_3_triggered();

    void on_actionSolve_4_triggered();

    void on_actionCosto_triggered();

    void on_actionSolve_5_triggered();

    void on_actionOriginal_triggered();

    void on_actionSolution_triggered();

    void on_actionKey_triggered();

    void on_actionDark_templ_triggered();

    void on_actionHuman_triggered();

    void on_actionOctopius_triggered();

    void on_actionPortal_triggered();

    void on_actionStones_triggered();

    void on_actionArrival_point_I_triggered();

    void on_actionArrival_Point_II_triggered();

    void on_actionArrival_Point_IIII_triggered();

    void on_actionFriend_triggered();

private:
    Ui::MainWindow *ui;

    Matrix * matrix;

    QGraphicsScene * scene;

    Coordinates activeCor;

    Solver *s;

    Points *p;

    //QGraphicsRectItem * rect;
    //QVector< QVector<Casilla> > *casillas;
    void loadMap();

    void drawMap(int x, int y,bool remove);
};

#endif // MAINWINDOW_H
