#include <stdio.h>
#include <time.h>

int main()
{
  struct timespec t = { 3/*seconds*/, 0/*nanoseconds*/};
  while (1){
    printf("Wait three seconds and...\n");
    nanosleep(&t,NULL);
    fflush(stdout); 
  }
}
