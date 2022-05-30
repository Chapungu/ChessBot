#ifndef STEPPER_CLASS
#define STEPPER_CLASS

#include "mbed.h"
#include "Pins.hpp"
#include "ReadabilityDefinitions.hpp"

class stepper{

    private:
        //PinName m_enable_pin, m_direction_pin, m_step_pin;
        DigitalOut m_enable, m_direction, m_step;
        DigitalIn m_switch;

        int Location;

    public:
        //Default Constructor
        stepper(PinName direction, PinName enable, PinName step, PinName m_switch);

        //alternate constructor
        stepper(StepperPins pins);

        
        /* ----------------------------------------------------------
        @function		- move
        @brief 			- moves the stepper motor in a direction.
        @Param          - dir: specifies which direction to move
        @Param          - steps/distance: specifies how far to move. 
        @return			- none 
        @Note			- 
        */
        void move(int dir, int dist);


        /* ----------------------------------------------------------
        @function		- distance
        @brief 			- returns the steps which the stepper motor moves. 
        @Param          - Mmeter, distance in Milimeter. 
        @return			- steps
        @Note			- assumes 1/4 step, so 0.05mm per step. 
        */
        int distance(int Mmeter);

        void Calibrate();

}; //end stepper class


#endif