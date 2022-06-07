#include "StepperClass.hpp"
#include "mbed.h"

stepper::stepper(PinName direction, PinName enable, PinName step,
                 PinName SSwitch)
    : m_enable(enable), m_direction(direction), m_step(step),
      m_switch(SSwitch) { // this is a member initaliser list
}

stepper::stepper(StepperPins pins)
    : m_enable(pins.Enable), m_direction(pins.Direction), m_step(pins.Step),
      m_switch(pins.Switch) { // this is a member initaliser list too
  m_enable = 0;
  m_direction = 0;
  m_step = 0;
}

void stepper::move(int dir, int dist) {
  int steps;

  m_direction = dir;
  steps = distance(dist);//gets amount of steps from distance function. 

  


  for (int i = 0; i < steps; i++) { //creates a 2ms pulse. 
    m_step = 1;//sets step high
    ThisThread::sleep_for(1ms);
    m_step = 0;//sets step low
    ThisThread::sleep_for(1ms);
    int check = 1; // m_switch.read(); //SET TO IGNORE SWITCH
    if (check == 0) {
      printf("location at 0 \n");
      stepper::Calibrate();
      break;
    };

  } // end for loop.
    // ThisThread::flags_clear(someFlag); //clear flag

} // end move function.

int stepper::distance(int Mmeter) {
  int step;
  step = Mmeter * 5;//calculate steps

  /*
  Full Step = *5
  Half Step = *10
  Quarter Step = *20.
  */
  return step;
}

void stepper::Calibrate() { Location = 0; }

int stepper::getlocation(){ return Location;}
void stepper::setlocation(int set){Location = set;}