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
    inline static float human_score = 0.0;
    inline static float AI_score = 0.0;
public:
    /**
     * @brief Construct a new game object
     * 
     * @param size_ size of the grid
     * @param required_ figures in row required to win 
     * @param maxdepth_ maximum depth of minimax search
     * @param AI_ AI's figure
     * @param human_ human's figure
     */
    game(int size_, int required_, int maxdepth_, char AI_, char human_):
    grid(size_, required_, maxdepth_, AI_, human_),
    AI(AI_),
    human(human_)
    {};

    /**
     * @brief manages game
     * 
     */
    void play();

    /**
     * @brief manages game but in animated way
     * 
     */
    void play_animated();

    /**
     * @brief shows current game results
     * 
     */
    void score(){cout<<"Komputer "<<AI_score<<" : "<<human_score<<" Ty"<<endl;};
};


#endif