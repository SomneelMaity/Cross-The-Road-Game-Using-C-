#ifndef CLANE_H
#define CLANE_H
#include<bits/stdc++.h>
using namespace std;


class cLane
{
private:
    deque<bool> cars;
    bool right;
public:
    cLane(int);
    void Move();
    bool checkPos(int);
    void changeDirection();


};

#endif // CLANE_H
