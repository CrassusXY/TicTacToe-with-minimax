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
public:
    tictactoe();
    char getFigure(int x, int y){return grid[x][y];};
    void setFigure(int x, int y, char fig_){grid[x][y] = fig_;};
    int getSize(){return size;};

    void displayGrid();
    bool isWon();
    bool isDraw();
    void play();
    std::pair<int, std::pair<int, int>> minimax(bool isMax, int depth, int alpha, int beta);
};


#endif