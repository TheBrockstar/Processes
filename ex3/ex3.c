// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int copy = fork();

    if (copy < 0) {
        // Error
        printf("SHUT DOWN ALL THE GARBAGE MASHERS ON THE DETENTION LEVEL! FAILED FORK.\n");
        exit(1);
    } else if (copy == 0) {
        // Child
        printf("Don't know why you say 'goodbye,' I say 'hello!'\n");
    } else {
        // Parent
        waitpid(copy, NULL, 0);
        printf("Goodbye my lover. Goodbye my friend. You have been the one. You have been the one for me...\n");
    }

    return 0;
}
