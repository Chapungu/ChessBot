#include "AI.hpp"

AI::AI(TheBoard *board) : TakeMoves(), Tpeices(), Moves(), Peices() {
  ChessBoard = board;
}

void AI::AVmoves() {
  for (int i = 1; i <= 64; i++) {
    // printf("in for loop\n\r");
    if (ChessBoard->GetBoard(i) == 2) {
      //printf("in counting 2's i is %d \n\r",i);
      if (i % 8 != 1) {
        //printf("i mod 8 = %d\n\r",(i % 8));
        if (ChessBoard->GetBoard(i + 7) == 0) {
          //printf("filling buffer i = %d moveleft\n\r",i);
          Peices.put(i);
          Moves.put(i + 7);
        } else if (ChessBoard->GetBoard(i + 7) == 1 &
                   ChessBoard->GetBoard(i + 18) == 0) {
          Tpeices.put(i);
          TakeMoves.put(i + 18);
        }
      }
      if (i % 8 != 0) {
        if (ChessBoard->GetBoard(i + 9) == 0) {
          //printf("filling buffer i = %d moveRight\n\r",i);
          Peices.put(i);
          Moves.put(i + 9);
        } else if (ChessBoard->GetBoard(i + 9) == 1 &
                   ChessBoard->GetBoard(i + 14) == 0) {
          Tpeices.put(i);
          TakeMoves.put(i + 14);
        }
      }
    }
  };
}

void AI::DecideMove() {
  if (Tpeices.getsize() != 0) {

    MoveFrom = Tpeices.pop();
    MoveTo = TakeMoves.pop();

  } else if (Peices.getsize() != 0) {
    MoveFrom = Peices.pop();
    MoveTo = Moves.pop();

  } else {
    printf("I SURRENDER");
  }
  Tpeices.clear();
  TakeMoves.clear();
  Peices.clear();
  Moves.clear();
}

int AI::GetMoveFrom() {
  printf("MoveFrom = %d\n\r", MoveFrom);
  return MoveFrom;
}

int AI::GetMoveTo() {
  printf("MoveTo = %d \n\r", MoveTo);
  return MoveTo;
}

void AI::ClearCoordinates() {
  MoveFrom = 0;
  MoveTo = 0;
}
