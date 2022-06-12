#ifndef TICTACTOE_HH
#define TICTACTOE_HH
#include <iostream>
#include <cmath>
using std::string;
using std::cout;
using std::cin;
using std::endl;


class tictactoe
{
private:
    char **grid;
    int required;
    int size;
    int played;
    int minmax;
    int maxdepth;
    char AI;
    char human;
    int alphabeta;
public:
    tictactoe(int size_, int required_, int maxdepth_);

    void displayGrid();
    int evaluate();
    bool isDraw();
    void play();
    std::pair<int, std::pair<int, int>> minimax(bool isMax, int depth, int alpha, int beta);
};


#endif