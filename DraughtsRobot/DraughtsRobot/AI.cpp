#include "AI.hpp"

AI::AI(TheBoard *board) : TakeMoves(), Tpeices(), Moves(), Peices() {
  ChessBoard = board;
}

void AI::AVmoves() {
  for (int i = 1; i <= 64; i++) { //checks all the squares on the board
    // printf("in for loop\n\r");
    if (ChessBoard->GetBoard(i) == 2) { //looks for peices which are green (labled 2 on internal board)
      //printf("in counting 2's i is %d \n\r",i);
      if (i % 8 != 1) { //checks to see if it is a left edge square
        //printf("i mod 8 = %d\n\r",(i % 8));
        if (ChessBoard->GetBoard(i + 7) == 0) { //checks to see if the square to the forward-left is free.
          //printf("filling buffer i = %d moveleft\n\r",i);
          Peices.put(i);//places move from square on buffer
          Moves.put(i + 7);//places move to square on buffer
        } else if (ChessBoard->GetBoard(i + 7) == 1 & //ckecks to see if the forward left square has a peice that can be taken
                   ChessBoard->GetBoard(i + 18) == 0) {//checks to see if the following square is free. 
          Tpeices.put(i); // places move from square on buffer
          TakeMoves.put(i + 14); //places move to square on buffer
        }
      }
      if (i % 8 != 0) { //cheks to see if it is a right edge square
        if (ChessBoard->GetBoard(i + 9) == 0) {//checks to see if the square to the forward right is free
          //printf("filling buffer i = %d moveRight\n\r",i);
          Peices.put(i); //puts move from square on buffer 
          Moves.put(i + 9);//puts move to square on buffer 
        } else if (ChessBoard->GetBoard(i + 9) == 1 & // checks to see if the forward right square has a peice that can be taken. 
                   ChessBoard->GetBoard(i + 14) == 0) { //checks to see if the following square is free. 
          Tpeices.put(i);//puts move from square on buffer
          TakeMoves.put(i + 18); // puts move to square on buffer
        }
      }
    }
  };
}

void AI::DecideMove() {
  if (Tpeices.getsize() != 0) {//checks to see if a take move is available

    MoveFrom = Tpeices.pop();//removes square from buffer
    MoveTo = TakeMoves.pop();//removes square from buffer 

  } else if (Peices.getsize() != 0) {//checks to see if a normal move is available
    MoveFrom = Peices.pop();//removes square from buffer 
    MoveTo = Moves.pop();//removes square from buffer
    int TakenP = (((MoveTo-MoveFrom)/2)+MoveTo);//calculates square that has a peice removed
    ChessBoard->SetBoard(TakenP,0);//sets square that has a peice removed to 0. 

  } else {
    printf("I SURRENDER");// if there are no moves available the AI will surrender. 
  }
  //-----------------CLEAR ALL BUFFERS ----------------------
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
