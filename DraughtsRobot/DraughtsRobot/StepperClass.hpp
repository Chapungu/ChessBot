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
        /* ----------------------------------------------------------
        @function		- Calibrate
        @brief 			- Calibrates the stepper motors to location 0
        @Param          - none
        @return			- 
        @Note			- . 
        */
        void Calibrate();
        /* ----------------------------------------------------------
        @function		- getlocation
        @brief 			- gets the location of the stepper motor from the class instance
        @Param          - none
        @return			- location.
        @Note			- . 
        */
        int getlocation();
                /* ----------------------------------------------------------
        @function		- setlocation
        @brief 			- sets the location variable in the class instance
        @Param          - the location value. 
        @return			- .
        @Note			- . 
        */
        void setlocation(int);
}; //end stepper class


#endif