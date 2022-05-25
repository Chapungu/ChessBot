#ifndef _BUFFER_H_
#define _BUFFER_H_
#include "mbed.h"
#include <cstdint>

#define BUFFER_CAPACITY 32

class Buffer {
private:
  uint8_t buff[BUFFER_CAPACITY];
  uint8_t head;
  uint8_t tail;
  uint32_t size;

public:
  Buffer() {
    head = 0;    // pointer to start reading data
    tail = head; // pointer to stop reading data
    size = 0;    // how much data.
  }
  /* ----------------------------------------------------------
@function		- put
@brief 			- puts data into the buffer
@Param          - data
@return			- none
@Note			-
*/
  void put(uint8_t data) {

    if (size >= BUFFER_CAPACITY) {
      printf("No Space in buffer\r\n");
      return;
    } else {
      buff[head] = data; // put data at head then increment head
      head = ((head + 1) % BUFFER_CAPACITY);
      size++;
      printf("buffer filling, Head = %d, Tail = %d\n\r", head, tail);
    }
  }
  /* ----------------------------------------------------------
@function		- pop
@brief 			- takes data off the buffer
@Param          - none
@return			- data
@Note			-
*/
  uint8_t pop() {
    uint8_t data = 0;

    if (size <= 0) {
      printf("Buffer Underrun\r\n");
    } else {
      data = buff[tail];
      tail = ((tail + 1) % BUFFER_CAPACITY);
      size--;
      printf("buffer emptying, Head = %d, Tail = %d\n\r", head, tail);
    }

    return data;
  }
  /* ----------------------------------------------------------
@function		- getsize
@brief 			- gets the amount of data in the
@Param          - none
@return			- the amount of data in the buffer
@Note			-
*/
  uint32_t getsize() { return size; }
  /* ----------------------------------------------------------
@function		- clear
@brief 			- empties the buffer
@Param          - none
@return			- none
@Note			-
*/
  void clear() {
    head = 0;    // pointer to start reading data
    tail = head; // pointer to stop reading data
    size = 0;    // how much data.
  }
};

#endif