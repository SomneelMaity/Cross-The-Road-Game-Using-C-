#ifndef CGAME_H
#define CGAME_H
#include "cPlayer.h"
#include "cLane.h"
#include<bits/stdc++.h>
using namespace std;

class cGame
{
private:
    bool quit;
    int numberOflanes;
    int width;
    int score;
    cPlayer *player;
    vector<cLane *> map;
public:
    cGame(int, int);

    void Draw();
    void Input();
    void Logic();
    void Run();
    ~cGame()
    {
        delete player;

        for(int i=0; i<map.size(); i++)
        {
            cLane * current = map.back();
            map.pop_back();
            delete current;
        }
    }

};

#endif // CGAME_H
