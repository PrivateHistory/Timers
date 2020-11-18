#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>
//convert ms to nanoseconds
#define MS_TO_NS(x)    (x ∗ 1E6L)
//define the timer structure
static struct hrtimer timer;

//callback function activated when the timer interval is done
enum hrtimer_restart callback_function( struct hrtimer ∗timer )
{
  //print the signal to dmsg
printk( "The message dispalyed every second\n", jiffies);
//Restart the timer
return HRTIMER_RESTART;
}

int init_timer_module( void )
{
// variable to represent the time
ktime_t ktime;
//delay of 1 second
unsigned long delay_in_ms = 1000L;
//print when the module is inatlled
printk("Timer module was installed\n");
//set the time of the timer variable
ktime = ktime_set( 0, MS_TO_NS(delay_in_ms) );

//initialize the timer (timer) with monolitic clock and
hrtimer_init( &timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL );
//callback function that is activated when the time passed
hr_timer.function = &callback_function;
//start the timer
hrtimer_start( &timer, ktime, HRTIMER_MODE_REL );
return 0;
}

void exit_timer_module( void )
{
  //state avriable for timer
int state;
//stop the timer(timer)
state = hrtimer_cancel( &timer );
//check if the timer was stopped
if (state)
printk("The timer was still in use...\n");

printk("Timer module uninstalling\n");

return;
}
module_init(init_timer_module);
module_exit( exit_timer_module);
