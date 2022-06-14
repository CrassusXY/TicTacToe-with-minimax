#include "tictactoe.hh"
#include <chrono>
#include<thread>

tictactoe::tictactoe(int size_, int required_, int maxdepth_, char AI_, char human_){
    if(size_>=3 && size_<=10)
       size = size_;
    else
        throw std::logic_error("Niepoprawny rozmiar!");

    
    if(required_<=size && required_>=3)
       required = required_;
    else
        throw std::logic_error("Niepoprawna ilosc ruchow do wygranej!");

    if(maxdepth_>0)
       maxdepth = maxdepth_;
    else
        throw std::logic_error("Niepoprawna glebokosc!");

    if(AI_!='O' || AI_!='X')
        AI = AI_;
    else
        throw std::logic_error("Niepoprawna figura!");

    if(human_!='O' || human_!='X')
        human = human_;
    else
        throw std::logic_error("Niepoprawna figura!");

    grid = new char*[size];
    for(int i=0; i<size; i++) {
        grid[i] = new char[size];
    }
    init();
}

void tictactoe::init(){
    played = 0;
    for(int y=0; y<size; y++){
        for(int x=0; x<size; x++){
            grid[x][y] = ' ';
        }
    }
}

void tictactoe::displayGrid(){
    for(int x=0; x<size; x++){
        if(x==0){
            cout<<" ";
        }
        cout<<"   "<<x;
    }
    cout<<endl<<endl;
    int i=0;
    for (int y=0; y<size; y++){
        for (int x=0; x<size; x++){
            if(x%size == 0){
                cout<<i<<"   "<<grid[x][y];
                i++;
            }
            else if(x%size == size-1){
                cout<<" | "<<grid[x][y]<<endl;
                if(y != size-1){
                    for(int j=0; j<size; j++){
                        if(j%size == size-1)
                            cout<<"---"<<endl;
                        else if(j%size == 0)
                            cout<<"   ---|";
                        else
                            cout<<"---|";
                    }
                }
            }
            else 
                cout<<" | "<<grid[x][y];  
        } 
    }
}

bool tictactoe::isDraw(){
    if(played == size*size)
        return true;
    else
        return false;
}

int tictactoe::evaluate(){
    int tmp;
    //skips part when there wasn't enough moves to win
    if(played<required*2-1)
        return 0;

    for (int y=0; y<size; y++){
        for (int x=0; x<size; x++){
            //skip parts wihout possibility to win, cuz i start checking only right and down from current position 
            if(x>size-required && y>size-required)
                continue;

            
            if(grid[x][y] != ' '){
                //horizontally
                if(x<=size-required){
                    tmp=1;
                    for (int i=1; i<required; i++){
                        if(grid[x][y] == grid[x+i][y])
                            tmp++;
                        else break;
                    }
                    if (tmp == required){
                        if(played%2==1)
                            return (AI == 'O' ? 1 : -1);
                        else
                            return (AI == 'X' ? 1 : -1);
                    }
                }
                //vertically
                if(y<=size-required){
                    tmp=1;
                    for (int i=1; i<required; i++){
                        if(grid[x][y] == grid[x][y+i])
                            tmp++;
                        else break;             
                    }
                    if (tmp == required){
                        if(played%2==1)
                            return (AI == 'O' ? 1 : -1);
                        else
                            return (AI == 'X' ? 1 : -1);
                    }
                }
                //pos slope
                if(x<=size-required && y<=size-required){
                    tmp=1;
                    for (int i=1; i<required; i++){
                        if(grid[x][y] == grid[x+i][y+i])
                            tmp++;
                        else break;  
                    }
                    if (tmp == required){
                        if(played%2==1)
                            return (AI == 'O' ? 1 : -1);
                        else
                            return (AI == 'X' ? 1 : -1);
                    }
                }
                //neg slope
                if(x<=size-required && y>size-required){
                    tmp=1;
                    for (int i=1; i<required; i++){
                        if(grid[x][y] == grid[x+i][y-i])
                            tmp++;
                        else break;  
                    }
                    if (tmp == required){
                        if(played%2==1)
                            return (AI == 'O' ? 1 : -1);
                        else
                            return (AI == 'X' ? 1 : -1);
                    }
                }
            }
        }
    }
    return 0;
}

std::pair<int, std::pair<int, int>> tictactoe::minimax(bool isMax, int depth, int alpha, int beta){
    int best_score;
    std::pair<int, int> best_move = std::make_pair(-1, -1);

    //if the game is in terminating state, return evaluation of this position
    if(evaluate()!=0){
        if(isMax)
            return std::make_pair(evaluate()*100+depth, best_move);
        else
            return std::make_pair(evaluate()*100-depth, best_move);  
    }
    else if(depth == maxdepth || isDraw()){
        return std::make_pair(0, best_move);
    }

    //maximization
    if(isMax){
        best_score = -1000;
        for (int y=0; y<size; y++){
            for (int x=0; x<size; x++){
                if (grid[x][y] == ' '){
                    set_value(x, y, AI);
                    
                    int score = minimax(!isMax, depth+1, alpha, beta).first;

                    clear_value(x, y);

                    if (best_score < score){
                        best_score = score;
                        best_move = std::make_pair(x, y);

                        alpha = std::max(alpha, best_score);    //alpha beta pruning
                        if (beta <= alpha){
                            return std::make_pair(alpha, best_move);
                        }
                    }
                }
            }
        }
        return std::make_pair(best_score, best_move);
    }

    //minimalization
    else{
        best_score = 1000;
        for (int y=0; y<size; y++){
            for (int x=0; x<size; x++){
                if (grid[x][y] == ' '){
                    set_value(x, y, human);

                    int score = minimax(!isMax, depth+1, alpha, beta).first;

                    clear_value(x, y);

                    if (best_score > score){
                        best_score = score;
                        best_move = std::make_pair(x, y);

                        beta = std::min(beta, best_score);      //alpha beta pruning
                        if (beta <= alpha){
                            return std::make_pair(beta, best_move);
                        }
                            
                    }
                }
            }
        }
        return std::make_pair(best_score, best_move);
    }
}

std::pair<int, std::pair<int, int>> tictactoe::animated_minimax(bool isMax, int depth, int alpha, int beta){
    int best_score;
    std::pair<int, int> best_move = std::make_pair(-1, -1);

    //if the game is in terminating state, return evaluation of this position
    if(evaluate()!=0){
        if(isMax)
            return std::make_pair(evaluate()*100+depth, best_move);
        else
            return std::make_pair(evaluate()*100-depth, best_move);  
    }
    else if(depth == maxdepth || isDraw()){
        return std::make_pair(0, best_move);
    }

    //maximization
    if(isMax){
        best_score = -1000;
        for (int y=0; y<size; y++){
            for (int x=0; x<size; x++){
                if (grid[x][y] == ' '){
                    set_value(x, y, AI);
                    displayGrid();
                    std::this_thread::sleep_for(std::chrono::milliseconds(2));
                    system("clear");
                    
                    int score = animated_minimax(!isMax, depth+1, alpha, beta).first;
                
                    clear_value(x, y);

                    if (best_score < score){
                        best_score = score;
                        best_move = std::make_pair(x, y);
                        alpha = std::max(alpha, best_score);
                        if (beta <= alpha){
                            return std::make_pair(alpha, best_move);
                        }
                    }
                }
            }
        }
        return std::make_pair(best_score, best_move);
    }
    //minimization
    else{
        best_score = 1000;
        for (int y=0; y<size; y++){
            for (int x=0; x<size; x++){
                if (grid[x][y] == ' '){
                    set_value(x, y, human);
                    displayGrid();
                    std::this_thread::sleep_for(std::chrono::milliseconds(2));
                    system("clear");

                    int score = animated_minimax(!isMax, depth+1, alpha, beta).first;

                    clear_value(x, y);

                    if (best_score > score){
                        best_score = score;
                        best_move = std::make_pair(x, y);
                        beta = std::min(beta, best_score);
                        if (beta <= alpha){
                            return std::make_pair(beta, best_move);
                        }
                            
                    }
                }
            }
        }
        return std::make_pair(best_score, best_move);
    }
}