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
    char grid[9];
    int size;
    int played;
public:
    tictactoe();
    char getFigure(int i){return grid[i];};
    void setFigure(int i, char fig_){grid[i] = fig_;};
    int getSize(){return size;};

    void displayGrid();
    bool isWon();
    bool isDraw();
    void play();
};


#endif