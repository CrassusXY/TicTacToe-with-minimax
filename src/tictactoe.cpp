#include "tictactoe.hh"

tictactoe::tictactoe(){
    size = 9;
    char c='0';
    for(int i=0; i<size; i++){
        grid[i] = c;
        c++;
    }
}

void tictactoe::displayGrid(){
    int size_ = sqrt(size);
    for (int i=0; i<size; i++){
        if(i%size_ == 0)
            cout<<" "<<grid[i];
        else if(i%size_ == size_-1){
            cout<<" | "<<grid[i]<<endl;
            if(i != size-1){
                for(int j=0; j<size_; j++){
                    if(j%size_ == size_-1)
                        cout<<"---"<<endl;
                    else
                        cout<<"---|";
                }
            }
        
        }
        else 
            cout<<" | "<<grid[i];    
    }
}

bool tictactoe::isWon(){
    for(int i=0; i<size; i+=3){
        if(grid[i] == grid[i+1] && grid[i+1] == grid[i+2]){
            return true;
        }
    }
    for(int i=0; i<3; i++){
        if(grid[i] == grid[i+3] && grid[i+3] == grid[i+6]){
            return true;
        }
    }
    if(grid[0] == grid[4] && grid[4] == grid[8]){
        return true;
    }
    if(grid[6] == grid[4] && grid[4] == grid[2]){
        return true;
    }
    return false;
}

bool tictactoe::isDraw(){
    if(played == size && !isWon()){
        return true;
    }
    else 
        return false;
}

void tictactoe::play(){
    int choice;
    played=0;

    cout<<"KÓŁKO I KRZYŻYK"<<endl;
    cout<<"Zaczyna kółko"<<endl;
    
    do{
        system("clear");
        displayGrid();
        if(played%2==0){
            cout<<endl<<"Gdzie postawić kółko?"<<endl;
            cin>>choice;
            while (choice<0 || choice>8){
                cout<<"Wychodzisz poza index! Podaj inne pole."<<endl;
                cin>>choice;
            }
            while (grid[choice] == 'O' || grid[choice] == 'X'){
                cout<<"To pole jest zajęte, wybierz inne!"<<endl;
                cin>>choice;
            }
            setFigure(choice, 'O');
        }    
        else{
            cout<<endl<<"Gdzie postawić krzyżyk?"<<endl;
            cin>>choice;
            while (choice<0 || choice>8){
                cout<<"Wychodzisz poza index! Podaj inne pole."<<endl;
                cin>>choice;
            }
            while (grid[choice] == 'O' || grid[choice] == 'X'){
                cout<<"To pole jest zajęte, wybierz inne!"<<endl;
                cin>>choice;
            }
            setFigure(choice, 'X');
        }
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