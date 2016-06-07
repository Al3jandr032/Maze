#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T14:14:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matrix.cpp \
    casilla.cpp \
    coordinates.cpp \
    precedence.cpp \
    adyacent.cpp \
    solver.cpp \
    arbol.cpp \
    nodo.cpp \
    bfs.cpp \
    dfs.cpp \
    idf.cpp \
    astar.cpp \
    entity.cpp \
    monkey.cpp \
    octopus.cpp \
    human.cpp \
    points.cpp \
    route.cpp

HEADERS  += mainwindow.h \
    matrix.h \
    casilla.h \
    coordinates.h \
    precedence.h \
    adyacent.h \
    solver.h \
    arbol.h \
    nodo.h \
    bfs.h \
    dfs.h \
    idf.h \
    astar.h \
    entity.h \
    monkey.h \
    octopus.h \
    human.h \
    points.h \
    route.h

FORMS    += mainwindow.ui
