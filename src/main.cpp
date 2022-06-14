#include "game.hh"

game load_values(){
    int size, required, maxdepth;
    char human, AI;

    cout<<endl<<"Podaj wielkosc planszy: ";
    cin>>size;
    while(cin.fail() || size<3 || size>10){
        cout << "Wprowadziles bledne dane" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Wprowadz wielkosc planszy ponownie:";
        cin >> size;
    }

    cout<<endl<<"Podaj ilosc figur pod rząd wymaganych do wygranej: ";
    cin>>required;
    while(cin.fail() || required<3 || required>size){
        cout << "Wprowadziles bledne dane" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Wprowadz ilosc figur pod rząd ponownie:";
        cin >> required;
    }

    cout<<endl<<"Podaj glębokosc rekurencji: ";
    cin>>maxdepth;
    while(cin.fail() || maxdepth<0){
        cout << "Wprowadziles bledne dane" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Wprowadz glębokosc rekurencji ponownie:";
        cin >> maxdepth;
    }

    cout<<endl<<"Podaj figure ktora chcesz grac(O/X): ";
    cin>>human;
    while(cin.fail() || !(human=='X' || human=='O')){
        cout << "Wprowadziles bledne dane" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Wprowadz figure ktora chcesz grac(O/X) ponownie:";
        cin >> human;
    }

    if(human=='X')
        AI = 'O';
    else
        AI = 'X';

    return game(size, required, maxdepth, AI, human);
}


int main(){
    char tmp='t';
    system("clear");
    cout<<"KOLKO I KRZYZYK"<<endl;
    char tmpA;


    while (tmp == 't')
    {
        cout<<"Grac w trybie animowanym? (t/n): ";
        cin>>tmpA;
        while(cin.fail() || !(tmpA== 't' || tmpA == 'n')){
            cout << "Wprowadziles bledne dane" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Wprowadz ponownie:";
            cin>>tmpA;
        }


        game tictac = load_values();
        if(tmpA == 't')
            tictac.play_animated();
        else
            tictac.play();
        tictac.score();
        cout<<"Grac dalej? (t/n): ";
        cin>>tmp;
        while(cin.fail() || !(tmp== 't' || tmp == 'n')){
            cout << "Wprowadziles bledne dane" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Wprowadz ponownie:";
            cin>>tmp;
        }
    }
}

