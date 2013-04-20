#include<iostream>
#include<cstdio>
using namespace std;

class tic_tac_board{
    public:
    char board[3][3];
    void input(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                scanf("%c",&board[i][j]);
            cin.ignore();
            //printf("\n");
        }
    }

    bool checkX(){
        bool diag = true, rDiag=true;
        for(int i=0;i<3;i++){
            bool row = true, column = true;
            for(int j=0;j<3;j++){
                if(!(board[i][j]=='X') || !row){
                    row = false;
                }
                if(!(board[j][i]=='X') || !column){
                    column = false;
                }
                if(!diag || (!(board[i][j]=='X') && i==j)){
                    diag = false;
                }
                if( !rDiag || ( !(board[i][j]=='X') && (4-1-i)==j)){
                    rDiag = false;
                }
            }
            if( row || column)
                return true;
        }
        if( diag || rDiag)
            return true;
    }

    bool checkO(){
        bool diag = true, rDiag=true;
        for(int i=0;i<4;i++){
            bool row = true, column = true;
            for(int j=0;j<4;j++){
                if(!(board[i][j]=='O') || !row){
                    row = false;
                }
                if(!(board[j][i]=='O') || !column){
                    column = false;
                }
                if( !diag || (i==j && !(board[i][j]=='O'))){
                    diag = false;
                }
                if( !rDiag || ((4-1-i)==j && !(board[i][j]=='O'))){
                        rDiag = false;
                }


            }
            if( row || column)
                return true;
        }
        if(diag || rDiag)
            return true;

    }

    bool checkDraw(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if(board[i][j]=='.')
                    return false;
        }
        return true;
    }

    string compute(){
        if(checkX())
            return "X won";
        else if(checkO())
            return "O won";
        else if(checkDraw())
            return "Draw";
        else
            return "Game has not completed";
    }
};

int main(){
    string output = "";
    tic_tac_board tObject;
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            cin >> tObject.board[j][k];
        }
    }
    output += tObject.compute();
    cout << output;
    return 0;
}