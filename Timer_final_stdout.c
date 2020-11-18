#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main()
{

  //define the structure for waiting
  struct timespec time = { 0/*seconds*/, 10000000/*nanoseconds*/};

  //defin ethe time intervals for measuring time
   struct timeval  tv1, tv2;
//infinite loop
for (int i=0;i<10;i++){

//get the current today time structure
 gettimeofday(&tv1, NULL);
  for(int i=0;i<10;i++){
  	//wait for the time in strcuture
    nanosleep(&time,NULL);
  }
  //get the current today time strcuture
  gettimeofday(&tv2, NULL);
  //print the execution time
 printf ("Total time = %f seconds\n",
         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec));
}

}
