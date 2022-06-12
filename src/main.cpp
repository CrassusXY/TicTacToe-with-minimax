#include "tictactoe.hh"

int main(){
    //system("clear");
    // int size, required, maxdepth;
    // cout<<"Podaj wielkość planszy: ";
    // cin>>size;
    // cout<<endl<<"Podaj ilość figur pod rząd wymaganych do wygranej: ";
    // cin>>required;
    // cout<<endl<<"Podaj głębokość rekurencji: ";
    // cin>>maxdepth;
    // tictactoe game(size, required, maxdepth);
    tictactoe game(3, 3, 15);
    cout<<"Jebać psy, kochać pieski"<<endl;
    game.play();
}

