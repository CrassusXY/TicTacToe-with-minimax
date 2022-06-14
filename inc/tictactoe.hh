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
    /**
     * @brief Construct a new tictactoe object
     * 
     * @param size_ size of the grid
     * @param required_ figures in row required to win 
     * @param maxdepth_ maximum depth of minimax search
     * @param AI_ AI's figure
     * @param human_ human's figure
     */
    tictactoe(int size_, int required_, int maxdepth_, char AI_, char human_);

    /**
     * @brief initializes grid with empty spaces
     * 
     */
    void init();

    /**
     * @brief Set the players object
     * 
     * @param AI_ AI's figure
     * @param human_ human's figure
     */
    void set_players(char AI_, char human_){AI=AI_; human=human_;};

    /**
     * @brief Set fig value on x,y filed 
     * 
     * @param x x-coordinate
     * @param y y-coordinate
     * @param fig figure
     */
    void set_value(int x, int y, char fig){grid[x][y] = fig; played++;};
    
    /**
     * @brief Clear value on x,y filed 
     * 
     * @param x x-coordinate
     * @param y y-coordinate
     */
    void clear_value(int x, int y){grid[x][y] = ' '; played--;};

    /**
     * @brief Get moves played so far
     * 
     * @return int
     */
    int moves_count(){return played;};

    /**
     * @brief Get the size object
     * 
     * @return int 
     */
    int get_size(){return size;};

    /**
     * @brief Get value of x,y filed 
     * 
     * @param x x-coordinate
     * @param y y-coordinate
     * @return char 
     */
    char get_fig(int x, int y){return grid[x][y];};
    
    /**
     * @brief Displays grid
     * 
     */
    void displayGrid();

    /**
     * @brief Evaluates current game score
     * 
     * @return 1 if AI wins, 0 if it's a draw, -1 if opponent wins
     */
    int evaluate();

    /**
     * @brief 
     * 
     * @return true it's a draw
     * @return false it isn't a draw
     */
    bool isDraw();

    /**
     * @brief returns optimal move for AI
     * 
     * @param isMax bool telling if computer should maximize or minimalize this move
     * @param depth current depth 
     * @param alpha 
     * @param beta 
     * @return std::pair<int, std::pair<int, int>> move's score and coordinates
     */
    std::pair<int, std::pair<int, int>> minimax(bool isMax, int depth, int alpha, int beta);

    /**
     * @brief returns optimal move for AI and visualize the way computer analyzes moves
     * 
     * @param isMax bool telling if computer should maximize or minimalize this move
     * @param depth current depth 
     * @param alpha 
     * @param beta 
     * @return std::pair<int, std::pair<int, int>> move's score and coordinates
     */
    std::pair<int, std::pair<int, int>> animated_minimax(bool isMax, int depth, int alpha, int beta);
};


#endif