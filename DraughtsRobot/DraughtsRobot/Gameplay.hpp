#ifndef _GAMEPLAY_
#define _GAMEPLAY_

#include "StepperClass.hpp"
#include "Pins.hpp"
#include "coordinates.hpp"
#include "mbed.h"
#include "TheBoard.hpp"


class GPlay{
    private:

    DigitalOut EMagnet;
    stepper xaxis;
    stepper yaxis;
    stepper zaxis;

    TheBoard *ChessBoard; 

    int XCol = 0;
    int YRow = 0;
    int PeiceValue = 0;

    public:
    //constructor
    GPlay(StepperPins xPins, StepperPins yPins, StepperPins zPins, PinName Magnet, TheBoard *board);

        /* ----------------------------------------------------------
    @function		- Dmove
    @brief 			- gets location of end effector
    @brief 			- calulates distance to new location
    @brief 			- moves steppers, updates location
    @Param          - X square.
    @Param          - Peice Value
    @return			- none
    @Note			- the array is 1 below the square number. 
    */
    void Dmove(int);
    void Dmove(char,char);

    int Xcoord(char x,int *col);
    int Ycoord(char y,int *row);
    int ReturnX(int square);
    int ReturnY(int square);

    int CalBoardValue(int *XCol,int *YRow);
    void SetPeiceValue(int);
    int GetPeiceValue();

    void GrabPeice();
    void DropPeice();
};

#endif