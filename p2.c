#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* 
When we execute this program, the alarm flag is set to 0.  Which means it will not
produce an alarm.  Next, the signal function is called with the arguments SIGINT and alarm_handler.
SIGINT will send a signal to terminate the program and the alarm_handler sends the current status of 
the alarm flag.  If the signal is 1, it will wait three seconds to output an alarm.  Before this alarm
is activated, the while loop will continually check the alarm flag and otherwise output "Waiting for an alarm."

 */

/* The signal handler isn't allowed to do anything except
* acess this variable and re-invoke signal(). 
 */

volatile sig_atomic_t alarm_flag = 0;
// Prototype for signal handler

void alarm_handler(int sig){
    alarm_flag = sig;
}

int main(void){
// Call signal() to set up a handler for SIGALRM
signal(SIGINT, alarm_handler);
// Call alarm() to have the alarm go off in afew seconds

alarm(3);

while(!alarm_flag){
    puts("Waiting for an alarm");
}

return 0;


}