#include "StepperClass.hpp"
#include "mbed.h"



stepper::stepper(PinName direction, PinName enable, PinName step):m_enable(enable),m_direction(direction), m_step(step){ //this is a member initaliser list
    
        }

stepper::stepper(StepperPins pins):m_enable(pins.Enable),m_direction(pins.Direction), m_step(pins.Step){ //this is a member initaliser list too
    m_enable = 0;
    m_direction = 0;
    m_step = 0;
}

void stepper::move(int dir, int dist){
            int steps;

            m_direction = dir;
            steps = distance(dist);
            //ThisThread::flags_wait_all(someFlag); //wait for some flag
            
            
            for (int i = 0; i < steps; i++){
                m_step = 1; 
                ThisThread::sleep_for(1ms);
                m_step = 0;
                ThisThread::sleep_for(1ms);
                //printf("steps taken = %d \n",i);
            }// end for loop. 
            //ThisThread::flags_clear(someFlag); //clear flag
            
        }//end move function. 



int stepper::distance(int Mmeter){
            int step;
            step = Mmeter*20;
            return step;
        }