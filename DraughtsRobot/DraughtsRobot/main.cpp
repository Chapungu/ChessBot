#include "Pins.hpp"
#include "ReadabilityDefinitions.hpp"
#include "StepperClass.hpp"
#include "buffer.h"
#include "coordinates.hpp"
#include "iostream"
#include "mbed.h"
#include <cstdint>
#include <string>
#include "Gameplay.hpp"
#include "AI.hpp"



// main() runs in its own thread in the OS

TheBoard ChessBoard; 
GPlay Gameplay(xAxisPins,yAxisPins,zAxisPins,Elec_Magnet,&ChessBoard); 
AI Green(&ChessBoard);

//TODO work out where you want the buffer to be stored. 
char PickSquare[2];
char DropSquare[2];



// main() 
int main() {

    cout << "welcome you are playing orange" << endl;

  while (1) {
    cout << "enter pickup square (letter then number)" << endl;
    scanf("%s", PickSquare);
    cout << "enter drop off square (letter then number)" << endl; 
    scanf("%s",DropSquare);

    
    Gameplay.Dmove(PickSquare[0],PickSquare[1]);
    Gameplay.GrabPeice();
    Gameplay.Dmove(DropSquare[0],DropSquare[1]);
    Gameplay.DropPeice();
 
    Green.AVmoves();
    Green.DecideMove();
    Gameplay.Dmove(Green.GetMoveFrom());
    Gameplay.GrabPeice();
    Gameplay.Dmove(Green.GetMoveTo());
    Gameplay.DropPeice();
    

  }
 




}//end main

