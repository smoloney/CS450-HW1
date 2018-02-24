#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>

/**

When this program runs, it displays the duration of a specific task that
was executed in the program. After experimenting with different types of
functions we realized that the system call for getpid() always had a longer
duration than our iterating function.  After looking through the assembly file, we realized
we could not find any instance of a syscall or int 0x80 in the assebly file. We
then realized that the getpid system call was apart of the unistd.h library.
After doing a little research, we realized that many library functions invoke
system calls indirectly. Usually these library functions make fewer system
calls. 

System calls are expensive and can hurt performance.
The system must do many things:
-Process is interrupted & computer saves its state
–OS takes control of the CPU
–OS performs requested action
–OS saves its state
–OS gives control of the CPU back to user

Because of this, the cost of mode transfer is expensive, so by using libraries,
you can allow for possibly less system calls. By having less frequent switches
from user mode to kernel mode allows for less overhead.

Its funny to think that going through all these steps is more expensive
than the basic function we wrote that iterates to 1000!


**/

void function(){ // a basic function that iterates to 1000, where in each iteration,
	int num = 0; // a number keeps getting incremented by 1
	for (int i = 0; i < 1000; i++){
		num+=1;
	}
	return;
}

void memoryFunction(){ // a basic memory accessing function
	int foo [] = { 16, 2, 77, 40, 12071 };
	int result =0;
	int size = sizeof(foo)/sizeof(foo[0]);
	for ( int i=0; i < size; i++){
      result += foo[i];
    }
	return;
}

void emptyFunction(){ // an empty function
	return;
}

int main(){

	auto start3 = std::chrono::system_clock::now();
  	emptyFunction();
	auto end3 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds3 = end3-start3;
	std::cout << "elapsed time for emtpy function: " << elapsed_seconds3.count() << "s\n";

	auto start4 = std::chrono::system_clock::now();
	memoryFunction();
	auto end4 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds4 = end4-start4;
	std::cout << "elapsed time for memory accessing function: " << elapsed_seconds4.count() << "s\n";

	auto start1 = std::chrono::system_clock::now();
	function();
	auto end1 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds1 = end1-start1;
	std::cout << "elapsed time for my function: " << elapsed_seconds1.count() << "s\n";

  	auto start2 = std::chrono::system_clock::now();
  	getpid();
	auto end2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end2-start2;
	std::cout << "elapsed time for syscall: " << elapsed_seconds2.count() << "s\n";


	return 0;
}
