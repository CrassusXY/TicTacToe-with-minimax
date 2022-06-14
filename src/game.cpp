#include "game.hh"
using namespace std::chrono;

void game::play(){
    int x, y;
    system("clear");
    cout<<"Zaczyna kolko"<<endl;
    grid.displayGrid();

    do{
        if(grid.moves_count()%2==0 && AI == 'O'){
            cout<<"Mysle nad najlepszym ruchem..."<<endl;
            std::pair<int, std::pair<int, int>> move = grid.minimax(true, 0, -1000, 1000);
            grid.set_value(move.second.first, move.second.second, AI);
        }
        else if(grid.moves_count()%2==1 && AI == 'X'){
            cout<<"Mysle nad najlepszym ruchem..."<<endl;
            std::pair<int, std::pair<int, int>> move = grid.minimax(true, 0, -100, 1000);
            grid.set_value(move.second.first, move.second.second, AI);
        }
        else{
            cout<<endl<<"Gdzie postawic figure?"<<endl;
            cout<<"X: ";
            cin>>x;
            while(cin.fail()){
                cout << "Wprowadziles bledne dane!" << endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Wprowadz wartosc X ponownie: ";
                cin >> x;
            }
            cout<<"Y: ";
            cin>>y;
            while(cin.fail()){
                cout << "Wprowadziles bledne dane!" << endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Wprowadz wartosc Y ponownie: ";
                cin >> y;
            }

            while (x<0 || x>=grid.get_size() || y<0 || y>=grid.get_size()){
                cout<<"Wychodzisz poza index! Podaj inne pole."<<endl;
                cout<<"X: ";
                cin>>x;
                while(cin.fail()){
                    cout << "Wprowadziles bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Wprowadz wartosc X ponownie: ";
                    cin >> x;
                }
                cout<<"Y: ";
                cin>>y;
                while(cin.fail()){
                    cout << "Wprowadziles bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Wprowadz wartosc Y ponownie: ";
                    cin >> y;
                }  
            }

            while (grid.get_fig(x, y) == 'O' || grid.get_fig(x, y) == 'X'){
                cout<<"To pole jest zajete, wybierz inne!"<<endl;
                cout<<"X: ";
                cin>>x;
                while(cin.fail()){
                    cout << "Wprowadziles bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Wprowadz wartosc X ponownie: ";
                    cin >> x;
                }
                cout<<"Y: ";
                cin>>y;
                while(cin.fail()){
                    cout << "Wprowadziles bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Wprowadz wartosc Y ponownie: ";
                    cin >> y;
                } 
            }
            grid.set_value(x, y, human);
        }
        system("clear");
        grid.displayGrid();
    }while (grid.evaluate()==0 && !grid.isDraw());

    if(grid.evaluate()!=0){
        if(grid.moves_count()%2==1){
            cout<<"Wygralo kolko!"<<endl;
            if(AI=='O')
                AI_score++;
            else
                human_score++;
        }  
        else{
            cout<<"Wygral krzyzyk!"<<endl;
            if(AI=='X')
                AI_score++;
            else
                human_score++;
        }
    }
    else if(grid.isDraw()){
        AI_score += 0.5;
        human_score += 0.5;
        cout<<"Remis!"<<endl;
    }
}

void game::play_animated(){
    int x, y;
    system("clear");
    cout<<"Zaczyna kolko"<<endl;
    grid.displayGrid();

    do{
        if(grid.moves_count()%2==0 && AI == 'O'){
            cout<<"Mysle nad najlepszym ruchem..."<<endl;
            std::pair<int, std::pair<int, int>> move = grid.animated_minimax(true, 0, -1000, 1000);
            grid.set_value(move.second.first, move.second.second, AI);
        }
        else if(grid.moves_count()%2==1 && AI == 'X'){
            cout<<"Mysle nad najlepszym ruchem..."<<endl;
            std::pair<int, std::pair<int, int>> move = grid.animated_minimax(true, 0, -100, 1000);
            grid.set_value(move.second.first, move.second.second, AI);
        }
        else{
            cout<<endl<<"Gdzie postawic figure?"<<endl;
            cout<<"X: ";
            cin>>x;
            while(cin.fail()){
                cout << "Wprowadziles bledne dane!" << endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Wprowadz wartosc X ponownie: ";
                cin >> x;
            }
            cout<<"Y: ";
            cin>>y;
            while(cin.fail()){
                cout << "Wprowadziles bledne dane!" << endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Wprowadz wartosc Y ponownie: ";
                cin >> y;
            }

            while (x<0 || x>=grid.get_size() || y<0 || y>=grid.get_size()){
                cout<<"Wychodzisz poza index! Podaj inne pole."<<endl;
                cout<<"X: ";
                cin>>x;
                while(cin.fail()){
                    cout << "Wprowadziles bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Wprowadz wartosc X ponownie: ";
                    cin >> x;
                }
                cout<<"Y: ";
                cin>>y;
                while(cin.fail()){
                    cout << "Wprowadziles bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Wprowadz wartosc Y ponownie: ";
                    cin >> y;
                }  
            }

            while (grid.get_fig(x, y) == 'O' || grid.get_fig(x, y) == 'X'){
                cout<<"To pole jest zajete, wybierz inne!"<<endl;
                cout<<"X: ";
                cin>>x;
                while(cin.fail()){
                    cout << "Wprowadziles bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Wprowadz wartosc X ponownie: ";
                    cin >> x;
                }
                cout<<"Y: ";
                cin>>y;
                while(cin.fail()){
                    cout << "Wprowadziles bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Wprowadz wartosc Y ponownie: ";
                    cin >> y;
                } 
            }
            grid.set_value(x, y, human);
        }
        system("clear");
        grid.displayGrid();
    }while (grid.evaluate()==0 && !grid.isDraw());

    if(grid.evaluate()!=0){
        if(grid.moves_count()%2==1){
            cout<<"Wygralo kolko!"<<endl;
            if(AI=='O')
                AI_score++;
            else
                human_score++;
        }  
        else{
            cout<<"Wygral krzyzyk!"<<endl;
            if(AI=='X')
                AI_score++;
            else
                human_score++;
        }
    }
    else if(grid.isDraw()){
        AI_score += 0.5;
        human_score += 0.5;
        cout<<"Remis!"<<endl;
    }
}