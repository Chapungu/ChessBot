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
int Xcoord(char);
int Ycoord(char);

// main() runs in its own thread in the OS
int main() {
  cout << "enter MoveSquare (letter then number)" << endl;
  scanf( "%s",myBuffer);

  printf("moveing to: %s\n\r",myBuffer);


  // int test = stod("24");



  Dmove(Xcoord(myBuffer[0]),Ycoord(myBuffer[1]));
}

void Dmove(int x, int y) {
  yaxis.move(Yforward, y);
  xaxis.move(XLeft, x);
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