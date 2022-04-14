#include "mbed.h"
#include "StepperClass.cpp"
#include "Pins.hpp"
// main() runs in its own thread in the OS
DigitalOut Green(LED1);
DigitalOut Yellow(LED2);
DigitalOut Red(LED3);
stepper xaxis(xAxisPins);
stepper yaxis(yAxisPins);
stepper zaxis(zAxisPins);

//Thread StepX, StepY, StepZ;

int main()
{   
    bool direction = 0; //direction 0 towards comp side. 
    int dist = 80;
    printf("in Main \r\n");
    
    while(1){
        Red = 0;
        Green = 1;  //turn on green light before move
        printf("Xaxis move \n");
        xaxis.move(direction, dist);
        printf("Yaxis move \n");
        yaxis.move(direction, dist);
        printf("Zaxis move \n");
        zaxis.move(direction, dist);
        Red = 1;
        Green = 0;
        
        wait_us(5000000);
        
    }

} 
