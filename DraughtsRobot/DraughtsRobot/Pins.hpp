
#ifndef Pins_hpp
#define Pins_hpp
#include "mbed.h"


struct StepperPins{
    PinName Enable;
    PinName Direction;
    PinName Step;
    PinName Switch; 
} ;

const StepperPins yAxisPins={
    PD_14,  //Enable     D10
    PD_15,  //Direction  D9
    PF_12,  //Step       D8
    PA_3    //Switch     A0
};

const StepperPins zAxisPins={
    PF_13,  //Enable     D7 
    PE_9,   //Direction  D6
    PE_11,  //Step       D5
    PC_3    //Switch     A2
};

const StepperPins xAxisPins={
    PF_14, //Enable     D4 (orange)
    PE_13, //Direction  D3 (yellow)
    PF_15,  //Step      D2 (green)
    PC_0,  //Switch     A1
};

#define Elec_Magnet PF_10  // A5

#endif
