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


GPlay Gameplay(xAxisPins,yAxisPins,zAxisPins,Elec_Magnet); 
AI Green;

//TODO work out where you want the buffer to be stored. 
char PickSquare[2];
char DropSquare[2];



// main() 
int main() {

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
    Gameplay.Dmove(Green.ReturnX(Green.GetMoveFrom()),Green.ReturnY(Green.GetMoveFrom()));
    Gameplay.GrabPeice();
    Gameplay.Dmove(Green.ReturnX(Green.GetMoveTo()),Green.ReturnY(Green.GetMoveTo()));
    Gameplay.DropPeice();
    

  }
 




}//end main

