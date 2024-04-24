#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pidc;
    int status;

    if (argc < 2)
    {
        printf("Argv[0] = %s\n", argv[0]);
        return 1;
    }

    // child creation
    pidc = fork();
    if (pidc == -1)
    {
        perror("error - pid");
        return errno;
    }

    if (pidc)
    {
        // parent process
        printf("Enfant créé : %ld\n", pidc);
        pidc = wait(&status);
        printf("pidc = %ld - WEXITSTATUS = %d\n", pidc, WEXITSTATUS(status));
    } 
    else
    {
        // child process
        printf("PID de l'enfant = %d\n", getpid());
        
        // name of prog as first argument
        argv[0] = argv[1];

        int cpt;
        for (cpt = 1; cpt < argc; cpt++)
        {
            argv[cpt] = argv[cpt + 1];
        }
        argv[argc] = (char *) NULL;

        if (execve(argv[0], argv, envp) == -1)
        {
            perror("error - arg");
            _exit(EXIT_FAILURE);
        }
    }
    return 0;
}