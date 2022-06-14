#include "game.hh"
using namespace std::chrono;

void game::play(){
    int x, y;
    system("clear");
    cout<<"Zaczyna kółko"<<endl;
    grid.displayGrid();

    do{
        if(grid.moves_count()%2==0 && AI == 'O'){
            std::pair<int, std::pair<int, int>> move = grid.minimax(true, 0, -1000, 1000);
            grid.set_value(move.second.first, move.second.second, AI);
        }
        else if(grid.moves_count()%2==1 && AI == 'X'){
            std::pair<int, std::pair<int, int>> move = grid.minimax(true, 0, -100, 1000);
            grid.set_value(move.second.first, move.second.second, AI);
        }
        else{
            cout<<endl<<"Gdzie postawić figurę?"<<endl;
            cin>>x;
            cin>>y;
            while (x<0 || x>=grid.get_size() || y<0 || y>=grid.get_size()){
                cout<<"Wychodzisz poza index! Podaj inne pole."<<endl;
                cin>>x;
                cin>>y;  
            }
            while (grid.get_fig(x, y) == 'O' || grid.get_fig(x, y) == 'X'){
                cout<<"To pole jest zajęte, wybierz inne!"<<endl;
                cin>>x;
                cin>>y;
            }
            grid.set_value(x, y, human);
        }
        system("clear");
        grid.displayGrid();
    }while (grid.evaluate()==0 && !grid.isDraw());

    if(grid.evaluate()!=0){
        if(grid.moves_count()%2==1){
            cout<<"Wygrało kółko!"<<endl;
            if(AI=='O')
                AI_score++;
            else
                human_score++;
        }  
        else{
            cout<<"Wygrał krzyżyk!"<<endl;
            if(AI=='X')
                AI_score++;
            else
                human_score++;
        }
    }
    else if(grid.isDraw())
        cout<<"Remis!"<<endl;
}

void game::play_animated(){
    int x, y;
    system("clear");
    cout<<"Zaczyna kółko"<<endl;
    grid.displayGrid();

    do{
        if(grid.moves_count()%2==0 && AI == 'O'){
            std::pair<int, std::pair<int, int>> move = grid.animated_minimax(true, 0, -1000, 1000);
            grid.set_value(move.second.first, move.second.second, AI);
        }
        else if(grid.moves_count()%2==1 && AI == 'X'){
            std::pair<int, std::pair<int, int>> move = grid.animated_minimax(true, 0, -100, 1000);
            grid.set_value(move.second.first, move.second.second, AI);
        }
        else{
            cout<<endl<<"Gdzie postawić figurę?"<<endl;
            cin>>x;
            cin>>y;
            while (x<0 || x>=grid.get_size() || y<0 || y>=grid.get_size()){
                cout<<"Wychodzisz poza index! Podaj inne pole."<<endl;
                cin>>x;
                cin>>y;  
            }
            while (grid.get_fig(x, y) == 'O' || grid.get_fig(x, y) == 'X'){
                cout<<"To pole jest zajęte, wybierz inne!"<<endl;
                cin>>x;
                cin>>y;
            }
            grid.set_value(x, y, human);
        }
        system("clear");
        grid.displayGrid();
    }while (grid.evaluate()==0 && !grid.isDraw());

    if(grid.evaluate()!=0){
        if(grid.moves_count()%2==1){
            cout<<"Wygrało kółko!"<<endl;
            if(AI=='O')
                AI_score++;
            else
                human_score++;
        }  
        else{
            cout<<"Wygrał krzyżyk!"<<endl;
            if(AI=='X')
                AI_score++;
            else
                human_score++;
        }
    }
    else if(grid.isDraw())
        cout<<"Remis!"<<endl;
}