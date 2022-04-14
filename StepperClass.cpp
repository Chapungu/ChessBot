// StepperClass.hpp


#ifndef StepperClass_hpp
#define StepperClass_hpp

#include <stdio.h>
#include <iostream>
#include "Pins.hpp"
 

class stepper{

    private:
        //PinName m_enable_pin, m_direction_pin, m_step_pin;
        DigitalOut m_enable, m_direction, m_step;

    public:
        //Default Constructor
        stepper(PinName direction, PinName enable, PinName step):m_enable(enable),m_direction(direction), m_step(step){ //this is a member initaliser list
    
        }

        stepper(StepperPins pins):m_enable(pins.Enable),m_direction(pins.Direction), m_step(pins.Step){ //this is a member initaliser list too
            m_enable = 0;
            m_direction = 0;
            m_step = 0;
        }

        /* ----------------------------------------------------------
        @function		- move
        @brief 			- moves the stepper motor in a direction.
        @Param          - dir: specifies which direction to move
        @Param          - steps/distance: specifies how far to move. 
        @return			- none 
        @Note			- 
        */
        void move(int dir, int dist){
            int steps;

            m_direction = dir;
            steps = distance(dist);

            
            for (int i = 0; i < steps; i++){
                m_step = 1; 
                wait_us(300);
                m_step = 0;
                wait_us(300);
                //printf("steps taken = %d \n",i);
            }// end for loop. 
        }//end move function. 


        /* ----------------------------------------------------------
        @function		- distance
        @brief 			- returns the steps which the stepper motor moves. 
        @Param          - Mmeter, distance in Milimeter. 
        @return			- steps
        @Note			- assumes 1/4 step, so 0.05mm per step. 
        */
        int distance(int Mmeter){
            int step;
            step = Mmeter*20;
            return step;
        }

};// end stepper class. 

#endif
