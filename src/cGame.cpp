#include "cGame.h"
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

cGame::cGame(int w = 20, int h = 10)
{
    numberOflanes = h;
    width = w;
    quit = false;
    for(int i=0; i<numberOflanes; i++)
    {
        map.push_back(new cLane(width));
    }
    player = new cPlayer(width);
}


void cGame::Draw()
{
    system("cls");
    for(int i=0; i<numberOflanes; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(i == 0 and (j == 0 or j == width - 1))
                cout<<"S";
            if(i == numberOflanes - 1 and (j == 0 or j == width - 1))
                cout<<"F";
            if(map[i]->checkPos(j)and i != 0 and i != numberOflanes-1)
                cout<<"#";
            else if(player->x == j and player->y == i)
                cout<<"V";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    cout<<"Score: "<<score<<endl;
}

void cGame::Input()
{
    if(_kbhit())
    {
        char current = _getch();
        if(current == 'a')
            player->x--;
        if(current == 'd')
            player->x++;
        if(current == 'w')
            player->y--;
        if(current == 's')
            player->y++;
        if(current == 'q')
            quit = true;
    }
}

void cGame::Logic()
{
    for(int i=1; i<numberOflanes-1; i++)
    {
        if(rand() % 10 == 1)
            map[i]->Move();
        if(map[i]->checkPos(player->x) and player->y == i)
            quit = true;
    }

    if(player->y == numberOflanes - 1)
    {
        score++;
        player->y = 0;
        cout<<"\x07";
        map[rand() % numberOflanes]->changeDirection();
    }
}

void cGame::Run()
{
    while(!quit)
    {
        Input();
        Draw();
        Logic();
    }
}
