#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>

void function(){ // a basic function that iterates to 100, where in each iteration,
	int num = 0; // a number keeps getting incremented by 1
	for (int i = 0; i < 100; i++){
		num+=1;
	}
}

void emptyFunction(){ // an empty function
    return;
}

int main(){

	auto start1 = std::chrono::system_clock::now();
	function();
	auto end1 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds1 = end1-start1;
	std::cout << "elapsed time for my function: " << elapsed_seconds1.count() << "s\n";

	auto start3 = std::chrono::system_clock::now();
	emptyFunction();
	auto end3 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds3 = end3-start3;
	std::cout << "elapsed time for empty function: " << elapsed_seconds3.count() << "s\n";

  	auto start2 = std::chrono::system_clock::now();
  	getpid();
	auto end2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end2-start2;
	std::cout << "elapsed time for syscall: " << elapsed_seconds2.count() << "s\n";

	return 0;
}
