
#ifndef Pins_hpp
#define Pins_hpp
#include "mbed.h"


typedef struct {
    PinName Enable;
    PinName Direction;
    PinName Step; 
} StepperPins;

const StepperPins yAxisPins{
    PD_14, //Enable     D10
    PD_15, //Direction  D9
    PF_12  //Step       D8
};

const StepperPins zAxisPins{
    PF_13, //Enable     D7
    PE_9,  //Direction  D6
    PE_11  //Step       D5
};

const StepperPins xAxisPins{
    PF_14, //Enable     D4
    PE_13, //Direction  D3
    PF_15  //Step       D2
};
#endif
