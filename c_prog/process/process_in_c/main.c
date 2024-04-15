#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("Error with pid");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("Child process is working\n");
        sleep(5);
        exit(0);
    }
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Child process: %d\n", pid);
    }

    pid_t pid_2;
    pid_2 = fork();
    if (pid_2 < 0)
    {
        perror("pid2 failed");
        exit(EXIT_FAILURE);
    }
    else if (pid_2 == 0)
    {
        printf("Child process 2 is working\n");
        sleep(5);
        exit(0);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        printf("Child process: %d\n", pid_2);
    }

    return 0;
}
