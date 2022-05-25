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
      /* ----------------------------------------------------------
    @function		- AVmoves
    @brief 			- puts all the available moves on 4 seperate buffers. 
    @Param          - none
    @return			- none
    @Note			- the buffers: TPeices, TakeMoves, Peices, Moves
    */
  void AVmoves();
      /* ----------------------------------------------------------
    @function		- DecideMove
    @brief 			- picks the first available move and assignes the coordinates to class variables
    @Param          - none
    @return			- none
    @Note			- 
    */
  void DecideMove();
      /* ----------------------------------------------------------
    @function		- GetMoveFrom
    @brief 			- gets the coordinates of the square to move from
    @Param          - none
    @return			- square coordinate 
    @Note			- coordinates are in array format
    */
  int GetMoveFrom();
      /* ----------------------------------------------------------
    @function		- GetMoveTo
    @brief 			- gets coordinates of the square to move too
    @Param          - square number
    @return			- square coordinates
    @Note			- coordinates are in array format 
    */
  int GetMoveTo();
        /* ----------------------------------------------------------
    @function		- ClearCoordinates
    @brief 			- resets class variables holding MoveFrom and MoveTo coordinates
    @Param          - none
    @return			- none
    @Note			-  
    */
  void ClearCoordinates();
};
#endif