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
  AI();

  void AVmoves();
  void DecideMove();
  int ReturnX(int square);
  int ReturnY(int square);
  int GetMoveFrom();
  int GetMoveTo();
  void ClearCoordinates();
};
#endif