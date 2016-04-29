#ifndef ADYACENT_H
#define ADYACENT_H


class Adyacent
{
public:
    Adyacent();
    Adyacent(int u,int d,int l, int r);
    void setUp(int in);
    int getUp(void);
    void setDown(int in);
    int getDown(void);
    void setLeft(int in);
    int getLeft(void);
    void setRight(int in);
    int getRight(void);
    bool canMove();
private:
    int up;
    int down;
    int left;
    int right;
};

#endif // ADYACENT_H
