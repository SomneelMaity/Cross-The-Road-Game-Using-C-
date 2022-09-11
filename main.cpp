#include "cGame.h"
#include "cLane.h"
#include "cPlayer.h"
#include<bits/stdc++.h>
#include<time.h>
#include<conio.h>
using namespace std;

int main()
{
    srand(time(NULL));
    cGame game(30,5);
    game.Run();
    cout<<"\nGame Over!\n";
    getchar();
    return 0;
}

