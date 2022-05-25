#ifndef _A_I_
#define _A_I_

#include "Gameplay.hpp"
#include "buffer.h"
#include "coordinates.hpp"
#include "mbed.h"
#include "TheBoard.hpp"

class AI :public Buffer {
private:
  Buffer TakeMoves;
  Buffer Tpeices;
  Buffer Moves;
  Buffer Peices;
  TheBoard *ChessBoard;    //provide place to store address of the board

  int MoveFrom;
  int MoveTo;
  

public:
  AI(TheBoard *board);     //provide interface to pass chess board address

  void AVmoves();
  void DecideMove();
  int GetMoveFrom();
  int GetMoveTo();
  void ClearCoordinates();
};
#endif