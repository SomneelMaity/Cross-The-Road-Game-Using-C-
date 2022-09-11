#include "cLane.h"
#include<bits/stdc++.h>
using namespace std;

cLane::cLane(int width)
{
    for(int i=0; i<width; i++)
    {
        cars.push_front(true);
    }

    right = rand()%2;
}

void cLane::Move()
{
    if(right)
    {
        if(rand() % 10 == 1)
            cars.push_front(true);
        else
            cars.push_front(false);
        cars.pop_back();
    }
    else
    {
        if(rand() % 10 == 1)
            cars.push_back(true);
        else
            cars.push_back(false);
        cars.pop_front();
    }
}

bool cLane::checkPos(int pos)
{
    return cars[pos];
}

void cLane::changeDirection()
{
    right = !right;
}
