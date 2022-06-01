#include "tictactoe.hh"

// void displayGrid(tictactoe game){
//     int size = sqrt(game.getSize());
//     for (int i=0; i<size*size; i++){

//         //if(i<=10){
//             if(i%size == 0)
//                 cout<<" "<<game.getFigure(i);
//             else if(i%size == size-1){
//                 cout<<" | "<<game.getFigure(i)<<endl;
//                 if(i != size*size-1){
//                     for(int j=0; j<size; j++){
//                         if(j%size == size-1)
//                             cout<<"---"<<endl;
//                         else
//                             cout<<"---|";
//                     }
//                 }
            
//             }
//             else 
//                 cout<<" | "<<game.getFigure(i);
//         //}


//         // else if(i<100){
//         //     if(i%size == 0)
//         //         cout<<" "<<game.getFigure(i);
//         //     else if(i%size == size-1){
//         //         cout<<"| "<<game.getFigure(i)<<endl;
//         //         if(i != size*size-1){
//         //             for(int j=0; j<size; j++){
//         //                 if(j%size == size-1)
//         //                     cout<<"---"<<endl;
//         //                 else
//         //                     cout<<"---|";
//         //             }
//         //         }
            
//         //     }
//         //     else 
//         //         cout<<"| "<<game.getFigure(i);
//         // }       
//     }
// }

int main(){
    tictactoe game;
    cout<<"Jebać psy, kochać pieski"<<endl;
    game.play();
}

