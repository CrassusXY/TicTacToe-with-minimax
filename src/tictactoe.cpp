#include "tictactoe.hh"
#include <chrono>
using namespace std::chrono;

tictactoe::tictactoe(int size_, int required_, int maxdepth_){
    size = size_;
    required = required_;
    maxdepth = maxdepth_;
    grid = new char*[size];
    for(int i=0; i<size; i++) {
        grid[i] = new char[size];
    }
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
    cout<<endl;
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
    if(played<required*2-1)
        return 0;

    for (int y=0; y<size; y++){
        for (int x=0; x<size; x++){
            //skip parts wihout possibility to win 
            if(x>size-required && y>size-required)
                continue;

            //horizontally
            if(grid[x][y] != ' '){
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

void tictactoe::play(){
    int x, y;
    played=0;
    alphabeta=0;
    cout<<"KÓŁKO I KRZYŻYK"<<endl;
    cout<<"Zaczyna kółko"<<endl;
    AI='X';
    human='O';
    displayGrid();

    do{
        if(played%2==0 && AI == 'O'){
            minmax = 0;
            auto start = high_resolution_clock::now();
            std::pair<int, std::pair<int, int>> move = minimax(true, 0, -1000, 1000);
            grid[move.second.first][move.second.second] = AI;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            cout<<"Czas trwania ruchu: "<<duration.count()<<"s, minmaxXD="<<minmax<<" Ocena pozycji: "<<move.first<<endl;
            cout<<"Alphabeta: "<<alphabeta<<endl;
        }
        else if(played%2==1 && AI == 'X'){
            minmax = 0;
            auto start = high_resolution_clock::now();
            std::pair<int, std::pair<int, int>> move = minimax(true, 0, -1000, 1000);
            grid[move.second.first][move.second.second] = AI;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            cout<<"Czas trwania ruchu: "<<duration.count()<<"s, minmaxXD="<<minmax<<" Ocena pozycji: "<<move.first<<endl;
            cout<<"Alphabeta: "<<alphabeta<<endl;
        }
        else{
            cout<<endl<<"Gdzie postawić figurę?"<<endl;
            cin>>x;
            cin>>y;
            while (x<0 || x>=size || y<0 || y>=size){
                cout<<"Wychodzisz poza index! Podaj inne pole."<<endl;
                cin>>x;
                cin>>y;  
            }
            while (grid[x][y] == 'O' || grid[x][y] == 'X'){
                cout<<"To pole jest zajęte, wybierz inne!"<<endl;
                cin>>x;
                cin>>y;
            }
            grid[x][y] = human;
        }
        //system("clear");
        displayGrid();
        played++;
    }while (evaluate()==0 && !isDraw());



    
    //system("clear");
    displayGrid();
    if(evaluate()!=0){
        if(played%2==1)
            cout<<"Wygrało kółko!"<<endl;
        else
            cout<<"Wygrał krzyżyk!"<<endl;
    }
    else if(isDraw())
        cout<<"Remis i chuj!"<<endl;

}

std::pair<int, std::pair<int, int>> tictactoe::minimax(bool isMax, int depth, int alpha, int beta){
    int best_score;
    std::pair<int, int> best_move = std::make_pair(-1, -1);
    minmax++;
    // if(played==0){
    //     best_move = std::make_pair(2, 2);
    //     return std::make_pair(0, best_move);
    // }

    if(evaluate()!=0){
        if(isMax)
            return std::make_pair(evaluate()*100+depth, best_move);
        else
            return std::make_pair(evaluate()*100-depth, best_move);  
    }

    else if(depth == maxdepth || isDraw()){
        return std::make_pair(0, best_move);
    }

    //maksymalizacja
    if(isMax){
        best_score = -1000;
        for (int y=0; y<size; y++){
            for (int x=0; x<size; x++){
                if (grid[x][y] == ' '){
                    grid[x][y]=AI;
                    played++;

                    int score = minimax(!isMax, depth+1, alpha, beta).first;

                    grid[x][y]=' ';
                    played--;

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
    //minimalizacja
    else{
        best_score = 1000;
        for (int y=0; y<size; y++){
            for (int x=0; x<size; x++){
                if (grid[x][y] == ' '){
                    grid[x][y]=human;
                    played++;

                    int score = minimax(!isMax, depth+1, alpha, beta).first;

                    grid[x][y]=' ';
                    played--;

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

