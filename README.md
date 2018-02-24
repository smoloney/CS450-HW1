# CS415 Operating Systems 

## Homework 1

**Problem 1: Virtual memory exploration [33 points]**
Write a C program (p1.c) based on Figure 2.7 (p. 54) in your textbook, with the following changes:
- You should assign the current process's ID to staticVar instead of increasing it by 1.
- The sleep() and printf() calls should be in an infinite loop.

Take a screenshot of multiple copies of this program running at the same time, and explain what the outputs in the screenshot tell you about the memory addresses used by different processes.
___

**Problem 2: Asynchronous notifications [33 points]**
In this program, you will practice setting up a Unix signal handler to receive asynchronous notifications from the kernel to your program. Specifically, you will define a function to catch the SIGALRM signal, and then you will set an alarm to go off in a few seconds. Stub code:
```C
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* The signal handler isn't allowed to do anything except
 * access this variable and re-invoke signal().
 */
volatile sig_atomic_t alarm_flag = 0;

/* Prototype for signal handler */
void alarm_handler (int sig);

int main (void) {
  // Call signal() to set up a handler for SIGALRM
  // Call alarm() to have the alarm go off in a few seconds
  while (!alarm_flag) {
    puts("Waiting for an alarm");
  }
  return 0;
}
```
You need to:
- Define the alarm_handler function. Signal handlers need to be really simple; all this one should do is change the alarm_flag (which is a special data type that allows it to be concurrently accessed by your signal handler and by your regular code).
- In main, add a call to signal() to set up your handler.
- In main, add a call to alarm() to have the alarm go off.

Helpful references:
- Two-part guide to Linux signal handling. Note that you really shouldn't call printf() from inside a signal handler -- keep it short and sweet.
- Manual for the alarm function

In your research, you may see that signal is now deprecated and sigaction is what all the kids are doing these days. That's true! But sigaction is more complicated, so signal is a good place to start.

In an initial comment, explain what happens when you run your program, and why.

**Problem 3: Syscalls and syscall timing [33 points]**
Do Exercise 2-12 (p. 91) in your book, with the following changes:

- Your source code file should be C++11 instead of C, so that you can use the chrono library with the high-resolution clock as your timer, instead of gettimeofday().
- Use getpid() as the syscall you measure, as they suggest.
- For your normal function, experiment with a few different things -- for example, a totally empty function with no parameters vs. a simple function that increments a number vs. a function that touches memory.

Your output should be something like:
```
elapsed time for my function: 1.03e-07s
elapsed time for syscall: 9.6e-08s
```
Generate an assembly version of your program (using the -S flag) to see if you can get a sense of what your function is really doing and what the syscall is really doing. Why don't you see a syscall or int 0x80 instruction directly in your assembly file?

In an initial comment to your code, explain the work that each call (your function and the syscall) must do, and try to explain the relative performance.
