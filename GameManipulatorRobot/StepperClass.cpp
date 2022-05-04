#include "StepperClass.hpp"
#include "mbed.h"

stepper::stepper(PinName direction, PinName enable, PinName step, PinName SSwitch)
    : m_enable(enable), m_direction(direction), m_step(step) ,m_switch(SSwitch) { // this is a member initaliser list
}

stepper::stepper(StepperPins pins)
    : m_enable(pins.Enable), m_direction(pins.Direction),m_step(pins.Step), m_switch(pins.Switch){ // this is a member initaliser list too
  m_enable = 0;
  m_direction = 0;
  m_step = 0;
}

void stepper::move(int dir, int dist) {
  int steps;

  m_direction = dir;
  steps = distance(dist);
  Location = dist;
  // ThisThread::flags_wait_all(someFlag, false); //wait for some flag

  for (int i = 0; i < steps; i++) {
    m_step = 1;
    ThisThread::sleep_for(1ms);
    m_step = 0;
    ThisThread::sleep_for(1ms);
    int check = m_switch.read();
    if(check == 0){
        printf("location at 0 \n");
        stepper::Calibrate();
        break;
        };

  } // end for loop.
    // ThisThread::flags_clear(someFlag); //clear flag

} // end move function.

int stepper::distance(int Mmeter) {
  int step;
  step = Mmeter * 5;

/*
Full Step = *5
Half Step = *10
Quarter Step = *20. 

*/
  return step;

  
}

void stepper::Calibrate() { Location = 0; }
