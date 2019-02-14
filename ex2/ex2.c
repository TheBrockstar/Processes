// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


// Both the parent and child processes have access to the file. When they are written concurrently, both writes go through.


int main(void)
{
    FILE *txt = fopen("./text.txt", "w+");
    char buffer[512];    
    int child = fork();

    if (child < 0) {
        // Failure
        printf("FUDGESICLES! FORK FAILED.");
        exit(1);

    } else if (child == 0) {
        // Child
        fgets(buffer, 512, txt);
        printf("Child Reads (before): %s\n", buffer);
        fputs("That hoopy frood always knows where his towel is. ", txt);
        fgets(buffer, 512, txt);
        printf("Child Reads (after): %s\n", buffer);

    } else {
        // Parent
        fgets(buffer, 512, txt);
        printf("Parent Reads (before): %s\n", buffer);
        fputs("So, so long and thanks for all the fish. ", txt);
        fgets(buffer, 512, txt);
        printf("Parent Reads (after): %s\n", buffer);


    }

    fclose(txt);
    
    return 0;
}
