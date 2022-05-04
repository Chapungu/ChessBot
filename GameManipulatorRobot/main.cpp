#include "mbed.h"
#include "StepperClass.hpp"
#include "Pins.hpp"
#include "ReadabilityDefinitions.hpp"
#include "coordinates.hpp"

// main() runs in its own thread in the OS



DigitalOut Green(LED1);
DigitalOut Yellow(LED2);
DigitalOut Red(LED3);
stepper xaxis(xAxisPins);
stepper yaxis(yAxisPins);
stepper zaxis(zAxisPins);

Thread StepX, StepY, StepZ;

void Xaxis_thread();
void Yaxis_thread();
void Zaxis_thread();




int main()
{   
    
    

    printf("in Main \r\n");
    


    StepX.start(Xaxis_thread);
    StepY.start(Yaxis_thread);
    //StepZ.start(Zaxis_thread);



    while(1){
       // __NOP();  //prevent while from being compiled out
       sleep();
    }
        
    wait_us(5000000);

} 


void Xaxis_thread(){
    
    while(1){
        xaxis.move(XLeft, RowG);
        printf("Xaxis end move \n");
        while(1){__NOP();}
    }
};

void Yaxis_thread(){
    
    while(1){
        yaxis.move(Yforward, Row2);
        printf("Yaxis end move \n");
        while(1){__NOP();}
    }
};
void Zaxis_thread(){
    printf("Zaxis move \n");
    while(1){
        zaxis.move(1, 80);
    }
};
