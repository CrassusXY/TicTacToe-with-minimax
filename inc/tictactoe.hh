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
    int maxdepth;
    char AI;
    char human;
public:
    tictactoe(int size_, int required_, int maxdepth_, char AI_, char human_);
    void init();
    void set_players(char AI_, char human_){AI=AI_; human=human_;};
    void set_value(int x, int y, char fig){grid[x][y] = fig; played++;};
    void clear_value(int x, int y){grid[x][y] = ' '; played--;};
    int moves_count(){return played;};
    int get_size(){return size;};
    char get_fig(int x, int y){return grid[x][y];};
    
    void displayGrid();
    int evaluate();
    bool isDraw();
    std::pair<int, std::pair<int, int>> minimax(bool isMax, int depth, int alpha, int beta);
    std::pair<int, std::pair<int, int>> animated_minimax(bool isMax, int depth, int alpha, int beta);
};


#endif