// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// It looks like there are many variants to allow for a variety of 
// combinations of different methods to access an executable, and different
// formats of arguments to pass it. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here    
    int copy = fork();

    if (copy < 0) {
        printf("NOOOOOOOOOOOOOOOOOOOOOO! FAILED FORK.");
        exit(1);
    } else if (copy == 0) {
        char *arguments[3];

        // arguments[0] = strdup("/bin/ls");
        // arguments[1] = "-l";
        // arguments[2] = NULL;
        // execvp(arguments[0], arguments);

        // arguments[0] = strdup("/bin/ls");
        // arguments[1] = "ls";
        // arguments[2] = "-l";
        // execl(arguments[0], arguments[1], arguments[2], (char*)NULL);

        // arguments[0] = strdup("/bin/ls");
        // arguments[1] = "-l";
        // arguments[2] = NULL;
        // execv(arguments[0], arguments);

        char *env[] = {"NONE=none", '\0'};
        arguments[0] = strdup("/bin/ls");
        arguments[1] = "ls";
        arguments[2] = "-l";
        execle(arguments[0], arguments[1], arguments[2], (char*)NULL, env);
    }

    return 0;
}
