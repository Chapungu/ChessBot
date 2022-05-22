#include "Gameplay.hpp"

void GPlay::Dmove(int x, int y) {
  int xmov, ymov, xdir, ydir = 0;
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


int GPlay::Xcoord(char x) {
  int xsquare;
  switch (x) {
  case 'a':
    xsquare = ColA;
    break;
  case 'b':
    xsquare = ColB;
    break;
  case 'c':
    xsquare = ColC;
    break;
  case 'd':
    xsquare = ColD;
    break;
  case 'e':
    xsquare = ColE;
    break;
  case 'f':
    xsquare = ColF;
    break;
  case 'g':
    xsquare = ColG;
    break;
  case 'h':
    xsquare = ColH;
    break;
  }
  return xsquare;
}

int GPlay::Ycoord(char y) {
  int ysquare = 0;
  switch (y) {
  case '1':
    ysquare = Row1;
    break;
  case '2':
    ysquare = Row2;
    break;
  case '3':
    ysquare = Row3;
    break;
  case '4':
    ysquare = Row4;
    break;
  case '5':
    ysquare = Row5;
    break;
  case '6':
    ysquare = Row6;
    break;
  case '7':
    ysquare = Row7;
    break;
  case '8':
    ysquare = Row8;
    break;
  }
  return ysquare;
}

void GPlay::GrabPeice(){
    zaxis.move(Zdown,GRAB);
    EMagnet = !EMagnet;
    ThisThread::sleep_for(1s);
    
    zaxis.move(Zup,GRAB);

}
