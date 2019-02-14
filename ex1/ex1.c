// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// The variables change independently!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int child = fork();
    // Your code here
    if (child < 0){
        printf("FORK FAILED.\n");
        exit(1);
    } else if (child == 0) {
        printf("Child (before): %i\n", x);
        x = 42;
        printf("Child (after): %i\n\n", x); // If you remove the second /n it changes the order. Why?
    } else {
        printf("Parent (before): %i\n", x);
        x = 7;
        printf("Parent (after): %i\n", x);
    }

    return 0;
}
