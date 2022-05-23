#ifndef _BUFFER_H_
#define _BUFFER_H_
#include "mbed.h"
#include <cstdint>

#define BUFFER_CAPACITY 32

class Buffer{
    public:
    Buffer(){
        head = 0;//pointer to start reading data
        tail = head; //pointer to stop reading data
        size = 0;//how much data. 
    }
    void put(uint8_t data){

        if (size >= BUFFER_CAPACITY){
            //printf("No Space in buffer\r\n");
            return;
        }else{
            buff[head] = data; //put data at head then increment head
            head = ((head + 1) % BUFFER_CAPACITY);
            size++;
        }

    }
    uint8_t pop(){
        uint8_t data = 0;

        if(size <= 0){
            printf("Buffer Underrun\r\n");
        }else{
            uint8_t data = buff[tail];
            tail = ((tail + 1) % BUFFER_CAPACITY);
            size--;
        }

        return data;
    }

    uint32_t getsize(){
        return size;
    }

    void clear(){
         head = 0;//pointer to start reading data
        tail = head; //pointer to stop reading data
        size = 0;//how much data. 
    }

    private:
        uint8_t buff[BUFFER_CAPACITY];
        uint8_t head;
        uint8_t tail;
        uint32_t size;
};

#endif