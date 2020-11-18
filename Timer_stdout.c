#include <stdio.h>
#include <time.h>

int main()
{

  //define the structure for waiting
  struct timespec time = { 1/*seconds*/, 0/*nanoseconds*/};

//infinite loop
  while (1){
    //print every loop
    printf("Wait for one second and...\n");
    //sleep for t seconds
    nanosleep(&time,NULL);
    //the message is usully writen in buffer so it can happen that the message do not appear the buffer is flashed

  // use fflush to move data to console
    fflush(stdout);
  }
}
