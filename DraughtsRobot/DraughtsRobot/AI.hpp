#ifndef _A_I_
#define _A_I_

#include "Gameplay.hpp"
#include "buffer.h"
#include "coordinates.hpp"
#include "mbed.h"


class AI : public TheBoard, public Buffer {
private:
  Buffer TakeMoves;
  Buffer Tpeices;
  Buffer Moves;
  Buffer Peices;

  int MoveFrom;
  int MoveTo; 

public:
  void AVmoves() {
    for (int i = 1; i < 65; i = i + 2) {
      if (GetBoard(i) == 2) {
        if (GetBoard(i + 7) == 0) {
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


void DecideMove(){
    if (Tpeices.getsize()!=0){
        MoveFrom = Tpeices.pop();
        MoveTo = TakeMoves.pop();
        Tpeices.clear();
        TakeMoves.clear();
    }
    else if (Peices.getsize()!=0){
        MoveFrom = Peices.pop();
        MoveTo = Moves.pop();
        Peices.clear();
        Moves.clear();
    }
    else{printf("I SURRENDER");}
}

int ReturnX(int square){
    int x = square%8;
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
    return xR;
}

int ReturnY(int square){
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
    return yR; 
}

};
#endif