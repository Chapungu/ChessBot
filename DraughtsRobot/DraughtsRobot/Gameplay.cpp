
#include "Gameplay.hpp"
#include <locale>


//Constructor
GPlay::GPlay(StepperPins xPins, StepperPins yPins, StepperPins zPins, PinName Magnet, TheBoard *board):
    xaxis(xPins),//passes pins for x axis
    yaxis(yPins),//passes pins for y axis 
    zaxis(zPins),//passes pins for z axis
    EMagnet(Magnet){//passes pins for electromagnet
    ChessBoard = board;//passes a referance for an instance of the board. 
    }

void GPlay::Dmove(int square){
      int xmov, ymov, xdir, ydir = 0;//creates internal variables for this function to use

  int x = ReturnX(square,&XCol);//creates coordinates for x
  int y = ReturnY(square,&YRow);//creates coordinates for y
  

  int xloc = xaxis.getlocation(); //gets current x location
  int yloc = yaxis.getlocation(); //gets current y location

  if (x > xloc) { //is x on the left of current location
    xdir = XLeft; // sets direction left
    xmov = x - xloc; //sets distance to move
  } else if (x < xloc) {//is x on the right of current location
    xdir = XRight;//sets direction right
    xmov = xloc - x;//sets distance to move
  }
  if (y > yloc) {//is y on forward of current location
    ydir = Yforward;//sets direction forward
    ymov = y - yloc;//sets distance to move
  } else if (y < yloc) {//is y behind current location 
    ydir = Ybackward;//sets direction backward
    ymov = yloc - y;//sets distance to move
  }

  yaxis.move(ydir, ymov);//moves y axis
  xaxis.move(xdir, xmov);//moves x axis 
  xaxis.setlocation(x);//sets x location
  yaxis.setlocation(y);//sets y location
  xloc = xaxis.getlocation(); //updates location for printf
  yloc = yaxis.getlocation(); //updates location for printf
  printf("the location is x: %d and y %d\n\r",xloc,yloc);
}

void GPlay::Dmove(char b0, char b1) {//this is a function overload, please see function above
  int xmov, ymov, xdir, ydir = 0;

  int x = Xcoord(b0,&XCol);//converts into coordinates from char
  int y = Ycoord(b1,&YRow);//converts into coordinates from char
  

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
int GPlay::ReturnX(int square, int *col){
    int x = square%8; 
    int xR = 0;
    switch (x) {
    case 1:
        xR = ColA;
        *col = 1;
        break;
    case 2:
        xR = ColB;
        *col = 2;
        break;
    case 3:
        xR = ColC;
        *col = 3;
        break;
    case 4:
        xR = ColD;
        *col = 4;
        break;
    case 5:
        xR = ColE;
        *col = 5;
        break;
    case 6:
        xR = ColF;
        *col = 6;
        break;
    case 7:
        xR = ColG;
        *col = 7;
        break;
    case 0:
        xR = ColH;
        *col = 8;
        break;
    }
    printf("coordinate X = %d \n\r",xR);
    return xR;
}
int GPlay::ReturnY(int square ,int *row){
    int y = (square/8);
    int yR = 0;
    switch (y) {
    case 0:
        yR = Row1;
        *row = 0;
        break;
    case 1:
        yR = Row2;
        *row = 8;
        break;
    case 2:
        yR = Row3;
        *row = 16;
        break;
    case 3:
        yR = Row4;
        *row = 24;
        break;
    case 4:
        yR = Row5;
        *row = 32;
        break;
    case 5:
        yR = Row6;
        *row = 40;
        break;
    case 6:
        yR = Row7;
        *row = 48;
        break;
    case 7:
        yR = Row8;
        *row = 56;
        break;
    }
    printf("coordinate Y = %d \n\r",yR);
    return yR; 
}

int GPlay::CalBoardValue(int *XCol,int *YRow){

    int boardValue = (*YRow + *XCol);//adds x squares to y squares. 
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
    UpBoard = CalBoardValue(&XCol,&YRow);//gets internal coordinates
    SetPeiceValue(ChessBoard->GetBoard(UpBoard));//records value of peice
    ChessBoard->SetBoard(UpBoard,0);//sets board value to 0 
    zaxis.move(Zdown,GRAB);//moves stepper motor down to grab peice 
    EMagnet = 1;//turns electromagnet on 
    ThisThread::sleep_for(1s);//waits for one second 
    zaxis.move(Zup,GRAB);//moves stepper motor up, to move peice 
}

void GPlay::DropPeice(){
    DwnBoard = CalBoardValue(&XCol, &YRow);//gets internal coordinates 
    if(DwnBoard<UpBoard){//if a peice has been taken by player
        int TakenP = UpBoard-((UpBoard-DwnBoard)/2); //clear that peice. 
    }
    ChessBoard->SetBoard(DwnBoard,PeiceValue);//update internal coordinates with peice value
    zaxis.move(Zdown,GRAB);//place peice down 
    EMagnet = 0; //turn electromagnet off
    ThisThread::sleep_for(1s);//wait for one second 
    zaxis.move(Zup,GRAB);//move stepper motor up
}
