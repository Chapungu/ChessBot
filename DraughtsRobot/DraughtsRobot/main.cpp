#include "Pins.hpp"
#include "ReadabilityDefinitions.hpp"
#include "StepperClass.hpp"
#include "buffer.h"
#include "coordinates.hpp"
#include "iostream"
#include "mbed.h"
#include <cstdint>
#include <string>

// main() runs in its own thread in the OS

UnbufferedSerial control(USBTX, USBRX, 115200);

Buffer coordBuff;

DigitalOut Green(LED1);
DigitalOut Yellow(LED2);
DigitalOut Red(LED3);
stepper xaxis(xAxisPins);
stepper yaxis(yAxisPins);
stepper zaxis(zAxisPins);

char myBuffer[2];

void Dmove(int, int);
void GrabPeice();
int Xcoord(char);
int Ycoord(char);

// main() runs in its own thread in the OS
int main() {
  /*
  while(1){
      printf("move the z axis test\n\r");
      scanf("%s",myBuffer);
      printf("scanned is: %s\n\r",myBuffer);
      if(myBuffer[0] == '1'){zaxis.move(1,200);}
      if(myBuffer[0] == '0'){zaxis.move(0,200);}
  }
  */
  xaxis.setlocation(0);
  yaxis.setlocation(0);

  while (1) {
    cout << "enter MoveSquare (letter then number)" << endl;
    scanf("%s", myBuffer);

    printf("moveing to: %s\n\r", myBuffer);  
    
    Dmove(Xcoord(myBuffer[0]), Ycoord(myBuffer[1]));
    GrabPeice();
  }

  // int test = stod("24");


}

void Dmove(int x, int y) {
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

int Xcoord(char x) {
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

int Ycoord(char y) {
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

void GrabPeice(){
    zaxis.move(Zdown,GRAB);
    //electromagnet= !electromagnet;
    ThisThread::sleep_for(1s);
    
    zaxis.move(Zup,GRAB);

}
