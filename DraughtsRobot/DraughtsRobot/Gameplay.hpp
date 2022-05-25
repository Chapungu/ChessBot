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
    /* ----------------------------------------------------------
    @function		- Dmove
    @brief 			- takes char coordiantes from buffer in main
    @brief 			- gets location of end effector
    @brief 			- calulates distance to new location
    @brief 			- moves steppers, updates location
    @Param          - X character (a-h)
    @Param          - Y character (1-8)
    @return			- none
    @Note			-  
    */
    void Dmove(char,char);
    /* ----------------------------------------------------------
    @function		- Xcoord
    @brief 			- converts (scanned)characters into distances 
    @Param          - character x columb (a-h)
    @Param          - takes a pointer to update. 
    @return			- xsquare
    @Note			- 
    */
    int Xcoord(char x,int *col);
        /* ----------------------------------------------------------
    @function		- Ycoord
    @brief 			- converts (scanned)characters into distances 
    @Param          - character y row (1-8)
    @Param          - takes a pointer to update. 
    @return			- ysquare
    @Note			- 
    */
    int Ycoord(char y,int *row);
    /* ----------------------------------------------------------
    @function		- ReturnX
    @brief 			- takes array coordinates and converts into distances 
    @Param          - int (1-64)
    @return			- xR
    @Note			- 
    */
    int ReturnX(int square);
    /* ----------------------------------------------------------
    @function		- ReturnY
    @brief 			- takes array coordinates and converts into distances 
    @Param          - int (1-64)
    @return			- xY
    @Note			- 
    */
    int ReturnY(int square);
    /* ----------------------------------------------------------
    @function		- CalBoardValue
    @brief 			- calculates the array coordinates from the input X and Y values
    @Param          - int (1-64)
    @return			- boardValue
    @Note			- this function is unfinished
    */
    int CalBoardValue(int *XCol,int *YRow);
    /* ----------------------------------------------------------
    @function		- SetPeiceValue
    @brief 			- sets the value of peice put down
    @Param          - int (1 or 2)
    @return			- none
    @Note			- 
    */
    void SetPeiceValue(int);
    /* ----------------------------------------------------------
    @function		- SetPeiceValue
    @brief 			- Gets the value of hte peice picked up
    @Param          - none
    @return			- PeiceValue
    @Note			- 
    */
    int GetPeiceValue();
    /* ----------------------------------------------------------
    @function		- GrabPeice
    @brief 			- adjusts the value of the board. 
    @brief 			- moves the grabber down to grab a peice. 
    @Param          - none
    @return			- none
    @Note			- 
    */
    void GrabPeice();
    /* ----------------------------------------------------------
    @function		- DropPeice
    @brief 			- adjusts the value of the board. 
    @brief 			- moves the grabber down to grab a peice. 
    @Param          - none
    @return			- none
    @Note			- 
    */
    void DropPeice();
};

#endif