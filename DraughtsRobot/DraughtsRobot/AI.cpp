#include "AI.hpp"

  AI::AI():TakeMoves(),Tpeices(),Moves(),Peices(){
      //TODO work out how to get AI to use an instance of the same board. This won't work
      //TODO work out problem with coordinates, there is a problem there. see ReturnX
  }

  void AI::AVmoves(){
    for (int i = 1; i < 65; i++) {
        printf("in for loop\n\r");
      if (GetBoard(i) == 2) {
          printf("in counting 2's\n\r");
        if (GetBoard(i + 7) == 0) {
            printf("filling buffer\n\r");
          Peices.put(i);
          Moves.put(i + 7);
        } else if (GetBoard(i + 7) == 1 & GetBoard(i + 18) == 0) {
          Tpeices.put(i);
          TakeMoves.put(i + 18);
        }
        if (GetBoard(i + 9) == 0) {
          Peices.put(i);
          Moves.put(i + 7);
        } else if (GetBoard(i + 9) == 1 & GetBoard(i + 14) == 0) {
          Tpeices.put(i);
          TakeMoves.put(i + 14);
        }
      }
    };
  }


void AI::DecideMove(){
    if (Tpeices.getsize()!=0){

        MoveFrom = Tpeices.pop();
        MoveTo = TakeMoves.pop();

    }
    else if (Peices.getsize()!=0){
        MoveFrom = Peices.pop();
        MoveTo = Moves.pop();

    }else{printf("I SURRENDER");}
    Tpeices.clear();
    TakeMoves.clear();
    Peices.clear();
    Moves.clear();
}

int AI::ReturnX(int square){
    int x = square%8;//TODO this can return 0 there is no case for that. 
    int xR = 0;
    switch (x) {
    case 1:
        xR = ColA;
        break;
    case 2:
        xR = ColB;
        break;
    case 3:
        xR = ColC;
        break;
    case 4:
        xR = ColD;
        break;
    case 5:
        xR = ColE;
        break;
    case 6:
        xR = ColF;
        break;
    case 7:
        xR = ColG;
        break;
    case 8:
        xR = ColH;
        break;
    }
    printf("coordinate X = %d \n\r",xR);
    return xR;
}

int AI::ReturnY(int square){
    int y = (square/8);
    int yR = 0;
    switch (y) {
    case 1:
        yR = Row1;
        break;
    case 2:
        yR = Row2;
        break;
    case 3:
        yR = Row3;
        break;
    case 4:
        yR = Row4;
        break;
    case 5:
        yR = Row5;
        break;
    case 6:
        yR = Row6;
        break;
    case 7:
        yR = Row7;
        break;
    case 8:
        yR = Row8;
        break;
    }
    printf("coordinate Y = %d \n\r",yR);
    return yR; 
}

int AI::GetMoveFrom(){
    printf("MoveFrom = %d\n\r",MoveFrom);
    return MoveFrom;
}

int AI::GetMoveTo(){
    printf("MoveTo = %d \n\r", MoveTo);
    return MoveTo;
}

void AI::ClearCoordinates(){
    MoveFrom = 0;
    MoveTo = 0;
}
