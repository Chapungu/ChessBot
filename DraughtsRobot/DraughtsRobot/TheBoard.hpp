#ifndef _THE_BOARD_
#define _THE_BOARD_

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
    /* ----------------------------------------------------------
    @function		- GetBoard
    @brief 			- gets the value of that square. 
    @Param          - square number
    @return			- value at square number 
    @Note			- the array is 1 below the square number. 
    */
    int GetBoard(int i);
        /* ----------------------------------------------------------
    @function		- SetBoard
    @brief 			- sets the value of a square
    @Param          - square number
    @Param          - Peice Value
    @return			- none
    @Note			- the array is 1 below the square number. 
    */
    void SetBoard(int i, int PV);
        /* ----------------------------------------------------------
    @function		- PrintBoard
    @brief 			- returns the board for analysis. 
    @Param          - none 
    @return			- none 
    @Note			- used for correcting code. 
    */
    void PrintBoard();


};

#endif