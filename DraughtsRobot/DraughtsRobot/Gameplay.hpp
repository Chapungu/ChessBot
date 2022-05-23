#ifndef _GAMEPLAY_
#define _GAMEPLAY_

#include "StepperClass.hpp"
#include "Pins.hpp"
#include "coordinates.hpp"
#include "mbed.h"

class TheBoard {
    
    private:

    int Board[64] = {   2,3,2,3,2,3,2,3,
                        3,2,3,2,3,2,3,2,
                        2,3,2,3,2,3,2,3,
                        3,0,3,0,3,0,3,0,
                        0,3,0,3,0,3,0,3,
                        3,1,3,1,3,1,3,1,
                        1,3,1,3,1,3,1,3,
                        3,1,3,1,3,1,3,1     }; 
    
    
    public:

    int GetBoard(int i);
    void SetBoard(int i, int PV);


};


class GPlay: public TheBoard{
    private:

    DigitalOut EMagnet;
    stepper xaxis;
    stepper yaxis;
    stepper zaxis;

    int XCol = 0;
    int YRow = 0;
    int PeiceValue = 0;
/*
      int Board[64] = {     2,0,2,0,2,0,2,0,
                            0,2,0,2,0,2,0,2,
                            2,0,2,0,2,0,2,0,
                            0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,
                            0,1,0,1,0,1,0,1,
                            1,0,1,0,1,0,1,0,
                            0,1,0,1,0,1,0,1     }; 
*/
    public:
    //constructor
    GPlay(StepperPins xPins, StepperPins yPins, StepperPins zPins, PinName Magnet);



    void Dmove(char,char);

    int Xcoord(char x,int *col);
    int Ycoord(char y,int *row);

    int CalBoardValue(int *XCol,int *YRow);
    void SetPeiceValue(int);
    int GetPeiceValue();

    void GrabPeice();
    void DropPeice();
};

#endif