#include <iostream>
#include <stdlib.h>
class game{
private:
    int player = 0;
    char board[9] = {'0','1','2','3','4','5','6','7','8'}, *choise;
    std::string namePlayers[2];
public:
    game(){
        std::cout<<"Welcome to X || O GAME\n";
        std::cout<<"Player 1 pleas Enter your NICKNAME : ";
        std::cin>>namePlayers[0];
        std::cout<<"\nPlayer 2 pleas Enter your NICKNAME : ";
        std::cin>>namePlayers[1];
        std::cout<<std::endl;
        gameStart();
    }
    void gameStart(){
            for(int i = 0; i < 9; i++){
                if(i == 2 || i ==  5 || i == 8){
                  std::cout<<board[i]<<std::endl;
                }
                else{
                  std::cout<<board[i]<<" ";
                }
            }
            int playerName = (player%2) ? 0 : 1;
            std::cout<<"\n\nEnter Your Place that you wanna PUT your X O in it Mr."<<namePlayers[playerName]<<" : ";
            std::cin>>choise;
            int choise1 =  atoi(choise);
            checkPlace(*choise, choise1, player);
    }
    void checkPlace(char &choise, int choise1, int playerName){
        if(board[choise1] == choise){
                 if(playerName%2 == 0){
                    board[choise1] = 'X';
                    ++player;
                    checkWinner();
                 }
                 if(playerName%2 != 0){
                    board[choise1] = 'O';
                    ++player;
                    checkWinner();
                 }
        }else
            gameStart();

    }
    void checkWinner(){
        if(board[0] == board [1] && board[1] == board[2])
           std::cout<<namePlayers[(player%2) ? 1 : 0];
        else if(board[0] == board[3] && board[3] == board[6])
           std::cout<<namePlayers[(player%2) ? 1 : 0];
        else if(board[3] == board[4] && board[4] == board[5])
           std::cout<<namePlayers[(player%2) ? 1 : 0];
        else if(board[6] == board[7] && board[7] == board[8])
           std::cout<<namePlayers[(player%2) ? 1 : 0];
        else if(board[1] == board[4] && board[4] == board[7])
           std::cout<<namePlayers[(player%2) ? 1 : 0];
        else if(board[2] == board[5] && board[5] == board[8])
           std::cout<<namePlayers[(player%2) ? 1 : 0];
        else if (   board[0] != '0' && board[1] != '1' && board[2] != '2'
                 && board[3] != '3' && board[4] != '4' && board[5] != '5'
                 && board[6] != '6' && board[7] != '7' && board[8] != '8')
            std::cout<<"\n\n\tNO WINNER\n\n";
        else
           gameStart();
    }
};
int main(){
    std::cout<<"\tSome INFORMATION \nThe First Player will be using 'O' \nThe Second Player will be using 'X'\nI Will start with the second player why? cuz I'm the program ! xD \nYou need only to chose the place number to insert your X || O \n\n\n";
    game G;
}
