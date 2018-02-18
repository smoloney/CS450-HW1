#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int staticVar = 0;
int main(){
     staticVar = getpid();
    int x = 0;
    while(x != -1){
        // printf("Static var:%d\n", staticVar);
        sleep(10);
        printf("Address: %x; Value: %d\n", &staticVar, staticVar);;
    }



    return 0;

}