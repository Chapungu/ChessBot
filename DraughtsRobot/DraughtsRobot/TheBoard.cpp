#include "TheBoard.hpp"




int TheBoard::GetBoard(int i){
        i--;
        return Board[i];
    }

void TheBoard::SetBoard(int i,int PV){
    i--;
    Board[i] = PV;
}
void TheBoard::PrintBoard(){
    for (int i = 1; i < 9; i++){
        for (int j = 1; j < 9; j++){
            int location = (i*8)+j;
            location = GetBoard(location);
            printf("%d ",location);
        }
        printf("/n/r");
    }
}