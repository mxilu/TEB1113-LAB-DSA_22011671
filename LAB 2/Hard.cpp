/*Validity of Tic-Tac-Toe Game*/

#include <iostream>

using namespace std;

int win[8][3]={
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
};

bool isCWin(char* board, char c){
     for(int i=0;i<8;i++){
        if (board[win[i][0]]==c &&
            board[win[i][1]]==c &&
            board[win[i][2]]==c
        ) return true;
     } return false;
}

bool isValid(char board[9]){
    int countX=0;int countO=0;

    for(int i=0; i<9; i++){
        if (board[i]=='X') countX++;
        if (board[i]=='O') countO++;
    }

    if (countX==countO || countX==countO+1){
        if (isCWin(board,'O')){
            if (isCWin(board, 'X')) return false;
            return (countX==countO);
        }
        if (isCWin(board,'X') && countX != countO+1) return false;

        return true;
    }
    return false;
}

int main(){
    char board[9]={
        'X', 'X', 'O',
        'O', 'O', 'X',
        'X', 'O', 'X'
    };

    (isValid(board))? cout<<"Board is valid": cout<<"Board is invalid";

    return 0;
}