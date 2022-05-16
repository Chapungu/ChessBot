#include "mbed.h"
#include "StepperClass.hpp"
#include "Pins.hpp"
#include "ReadabilityDefinitions.hpp"
#include "coordinates.hpp"
#include "iostream"
#include "buffer.h"
#include <cstdint>

// main() runs in its own thread in the OS

UnbufferedSerial control(USBTX,USBRX,115200);

Buffer coordBuff;

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
void getCoords();



int main()
{   
    printf("in Main \r\n");
    /*
    control.attach(getCoords, SerialBase::RxIrq);
    while(1){
    while(coordBuff.getsize()!=0){
        uint8_t check = coordBuff.pop();
        printf("Your input was %c\r\n", check);
    }
    }
    */
    


    StepX.start(Xaxis_thread);
    //StepY.start(Yaxis_thread);
    //StepZ.start(Zaxis_thread);

    xaxis.move(1,80);



    while(1){
       // __NOP();  //prevent while from being compiled out
       sleep();
    }
        
    wait_us(5000000);

} 

void getCoords(){
    char d;                 //provide plae to put charachter
    control.read(&d, 1);    //read serial data and copy data to d
 
    coordBuff.put(d);
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
