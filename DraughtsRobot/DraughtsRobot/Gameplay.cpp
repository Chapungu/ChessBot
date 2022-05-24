
#include "Gameplay.hpp"

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

GPlay::GPlay(StepperPins xPins, StepperPins yPins, StepperPins zPins, PinName Magnet):
    xaxis(xPins),
    yaxis(yPins),
    zaxis(zPins),
    EMagnet(Magnet){
        
    }

void GPlay::Dmove(int inputx,int inputy){
      int xmov, ymov, xdir, ydir = 0;

  int x = inputx;
  int y = inputy;
  

  int xloc = xaxis.getlocation();
  int yloc = yaxis.getlocation();

  if (x > xloc) {
    xdir = XLeft;
    xmov = x - xloc;
  } else if (x < xloc) {
    xdir = XRight;
    xmov = xloc - x;
  }
  if (y > yloc) {
    ydir = Yforward;
    ymov = y - yloc;
  } else if (y < yloc) {
    ydir = Ybackward;
    ymov = yloc - y;
  }

  yaxis.move(ydir, ymov);
  xaxis.move(xdir, xmov);
  xaxis.setlocation(x);
  yaxis.setlocation(y);
  xloc = xaxis.getlocation();
  yloc = yaxis.getlocation();
  printf("the location is x: %d and y %d\n\r",xloc,yloc);
}

void GPlay::Dmove(char b0, char b1) {
  int xmov, ymov, xdir, ydir = 0;

  int x = Xcoord(b0,&XCol);
  int y = Ycoord(b1,&YRow);
  

  int xloc = xaxis.getlocation();
  int yloc = yaxis.getlocation();

  if (x > xloc) {
    xdir = XLeft;
    xmov = x - xloc;
  } else if (x < xloc) {
    xdir = XRight;
    xmov = xloc - x;
  }
  if (y > yloc) {
    ydir = Yforward;
    ymov = y - yloc;
  } else if (y < yloc) {
    ydir = Ybackward;
    ymov = yloc - y;
  }

  yaxis.move(ydir, ymov);
  xaxis.move(xdir, xmov);
  xaxis.setlocation(x);
  yaxis.setlocation(y);
  xloc = xaxis.getlocation();
  yloc = yaxis.getlocation();
  printf("the location is x: %d and y %d\n\r",xloc,yloc);
}


int GPlay::Xcoord(char x,int *col) {
  int xsquare;
  switch (x) {
  case 'a':
    xsquare = ColA;
    *col = 1;
    break;
  case 'b':
    xsquare = ColB;
    *col = 2;
    break;
  case 'c':
    xsquare = ColC;
    *col = 3;
    break;
  case 'd':
    xsquare = ColD;
    *col = 4;
    break;
  case 'e':
    xsquare = ColE;
    *col = 5;
    break;
  case 'f':
    xsquare = ColF;
    *col = 6;
    break;
  case 'g':
    xsquare = ColG;
    *col = 7;
    break;
  case 'h':
    xsquare = ColH;
    *col = 8;
    break;
  case '0':
    xsquare = 0;
    break;
  }
  return xsquare;
}
int GPlay::Ycoord(char y ,int *row) {
  int ysquare = 0;
  switch (y) {
  case '1':
    ysquare = Row1;
    *row = 0;
    break;
  case '2':
    ysquare = Row2;
    *row = 8;
    break;
  case '3':
    ysquare = Row3;
    *row = 16;
    break;
  case '4':
    ysquare = Row4;
    *row = 24;
    break;
  case '5':
    ysquare = Row5;
    *row = 32;
    break;
  case '6':
    ysquare = Row6;
    *row = 40;
    break;
  case '7':
    ysquare = Row7;
    *row = 48;
    break;
  case '8':
    ysquare = Row8;
    *row = 56;
    break;
  case '0':
    ysquare = 0;
  }
  return ysquare;
}

int GPlay::CalBoardValue(int *XCol,int *YRow){

    int boardValue = (*YRow + *XCol);
    *YRow = 0;
    *XCol = 0; 

    return boardValue; 

}

void GPlay::SetPeiceValue(int PV){
 PeiceValue = PV; 
}

int GPlay::GetPeiceValue(){
    return PeiceValue; 
}

void GPlay::GrabPeice(){
    int UpBoard = CalBoardValue(&XCol,&YRow);
    SetPeiceValue(GetBoard(UpBoard));
    SetBoard(UpBoard,0);
    zaxis.move(Zdown,GRAB);
    EMagnet = 1;
    ThisThread::sleep_for(1s);
    zaxis.move(Zup,GRAB);
}

void GPlay::DropPeice(){
    int DwnBoard = CalBoardValue(&XCol, &YRow);
    SetBoard(DwnBoard,PeiceValue);
    zaxis.move(Zdown,GRAB);
    EMagnet = 0; 
    ThisThread::sleep_for(1s);
    zaxis.move(Zup,GRAB);
}
