#include "tictactoe.hh"

tictactoe::tictactoe(){
    size = 4;
    required = 3;
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

bool tictactoe::isWon(){
    int tmpA, tmpB, tmpC, tmpD;
    for (int y=0; y<size; y++){
        for (int x=0; x<size; x++){
            if(x<=size-required && grid[x][y] != ' ' ){
                tmpA=0;
                for (int i=0; i<required; i++){
                    if(grid[x][y] == grid[x+i][y])
                        tmpA++;
                    else break;
                }
                //cout<<"Kurew konfidenckich poziomo "<<tmpA<<endl;
                if (tmpA == required)
                    return true;
            }
            if(y<=size-required && grid[x][y] != ' '){
                tmpB=0;
                for (int i=0; i<required; i++){
                    if(grid[x][y] == grid[x][y+i])
                        tmpB++;
                    else break;                    
                }
                //cout<<"Kurew konfidenckich pionowo "<<tmpB<<endl;
                if (tmpB == required)
                    return true;
            }
            if(x<=size-required && y<=size-required && grid[x][y] != ' '){
                tmpC=0;
                for (int i=0; i<required; i++){
                    if(grid[x][y] == grid[x+i][y+i])
                        tmpC++;
                    else break;  
                }
                //cout<<"Kurew konfidenckich skosnie- "<<tmpA<<endl;
                if (tmpC == required)
                    return true;
            }
            if(x<=size-required && y>size-required && grid[x][y] != ' '){
                tmpD=0;
                for (int i=0; i<required; i++){
                    if(grid[x][y] == grid[x+i][y-i])
                        tmpD++;
                    else break;  
                }
                //cout<<"Kurew konfidenckich skosnie+ "<<tmpA<<endl;
                if (tmpD == required)
                    return true;
            }
        }
    }
    return false;
}

bool tictactoe::isDraw(){
    if(played == size*size && !isWon()){
        return true;
    }
    else 
        return false;
}

void tictactoe::play(){
    int x, y;
    played=0;

    system("clear");
    cout<<"KÓŁKO I KRZYŻYK"<<endl;
    cout<<"Zaczyna kółko"<<endl;
    displayGrid();

    do{
        if(played%2==0){
            std::pair<int,int> move = bestMove();
            setFigure(move.first, move.second, 'O');
        }
        else{
            cout<<endl<<"Gdzie postawić krzyżyk?"<<endl;
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
            setFigure(x, y, 'X');
        }
        //system("clear");
        displayGrid();
        played++;
    }while (!isDraw() && !isWon());
    system("clear");
    displayGrid();
    if(isWon()){
        if(played%2==1){
            cout<<"Wygrało kółko!"<<endl;
        }
        else{
            cout<<"Wygrał krzyżyk!"<<endl;
        }
    }
    else if(isDraw()){
        cout<<"Remis i chuj."<<endl;
    }
}

int tictactoe::minimax(int depth, bool isMax){
    minmax++;
    if(isWon()){
        if(played%2==1)
            return 10-depth;
        else
            return -10+depth;
    }
    else if (isDraw())
        return 0;
    
    //maksymalizacja
    if (isMax)
    {
        int best = -1000;
        for (int y=0; y<size; y++){
            for (int x=0; x<size; x++){
                if (grid[x][y] == ' ')
                {
                    grid[x][y]='X';
                    played++;

                    best = std::max(best, minimax(depth + 1, !isMax));

                    // Undo the move
                    grid[x][y] = ' ';
                    played--;
                }
            }
        }
        return best;
    }

    //minimalizacja
    else
    {
        int best = 1000;
        for (int y=0; y<size; y++){
            for (int x=0; x<size; x++){
                if (grid[x][y] == ' ')
                {
                    grid[x][y]='O';
                    played++;
                    best = std::min(best, minimax(depth + 1, !isMax));

                    // Undo the move
                    grid[x][y] = ' ';
                    played--;
                }
            }
        }
        return best;
    }
}


std::pair<int,int> tictactoe::bestMove()
{
    int bestVal = -1000;
    int bestMove[2]={-1,-1};

    for (int y=0; y<size; y++){
        for (int x=0; x<size; x++){
            if (grid[x][y] == ' ')
            {
                grid[x][y]='O';
                played++;
                int moveValue = minimax(0, true);
                grid[x][y]=' ';
                played--;
                
                if (moveValue > bestVal)
                {
                    bestVal = moveValue;
                    bestMove[0] = x;
                    bestMove[1] = y;
                }
            }
        }
    }
    cout << "najlepszy ruch to: " << bestMove[0] << " " << bestMove[1] << endl;
    cout<<minmax<<endl;
    return std::pair<int,int>(bestMove[0], bestMove[1]);
}