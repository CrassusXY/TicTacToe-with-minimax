#ifndef GAME_HH
#define GAME_HH
#include "tictactoe.hh"
#include <chrono>

class game
{
private:
    tictactoe grid;
    char AI;
    char human;
    int human_score;
    int AI_score;
public:
    game(int size_, int required_, int maxdepth_, char AI_, char human_):
    grid(size_, required_, maxdepth_, AI_, human_),
    AI(AI_),
    human(human_),
    human_score(0),
    AI_score(0)
    {};
    void play();
    void play_animated();
    void score(){cout<<"Komputer "<<AI_score<<" : "<<human_score<<" Ty"<<endl;};
};


#endif