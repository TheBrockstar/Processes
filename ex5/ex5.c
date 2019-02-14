// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    int rw[2];
    int p = pipe(rw);

    if (p < 0) {
        printf("UH OH - PIRAHNA PLANT! PIPE FAILED.");
        exit(1);
    }

    int child = fork();

    if (child < 0) {
        // Error
        printf("To be, or not to be, is not the question because PIPE FAILED.");
    } else if (child == 0) {
        // Child
        char buffer[MSGSIZE];
        close(rw[1]);
        printf("Child: \n");
        for (int i = 0; i < 3; i++) {
            read(rw[0], buffer, MSGSIZE);
            printf("%s\n", buffer);
        }

    } else {
        // Parent
        close(rw[0]);
        write(rw[1], msg1, MSGSIZE);
        write(rw[1], msg2, MSGSIZE);
        write(rw[1], msg3, MSGSIZE);
    }
    
    return 0;
}
