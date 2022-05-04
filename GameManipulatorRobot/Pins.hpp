
#ifndef Pins_hpp
#define Pins_hpp
#include "mbed.h"


typedef struct {
    PinName Enable;
    PinName Direction;
    PinName Step;
    PinName Switch; 
} StepperPins;

const StepperPins yAxisPins{
    PD_14,  //Enable     D10
    PD_15,  //Direction  D9
    PF_12,  //Step       D8
    PA_3    //Switch     A0
};

const StepperPins zAxisPins{
    PF_13,  //Enable     D7 
    PE_9,   //Direction  D6
    PE_11,  //Step       D5
    PC_3    //Switch     A2
};

const StepperPins xAxisPins{
    PF_14, //Enable     D4 (black)
    PE_13, //Direction  D3 (white)
    PF_15,  //Step      D2 (grey)
    PC_0,  //Switch     A1
};
#endif
