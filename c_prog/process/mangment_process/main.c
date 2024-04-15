#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    char description[100];
    pid_t pid;
    pid_t ppid;
} Process;

void menu()
{
    printf("\n Menu \n");
    printf("1.Créer un processus\n");
    printf("2.Lister les processus\n");
    printf("3.Supprimer un processus\n");
    printf("4.Exit of program\n");
    printf("Faites votre choix: \n");
}

void ajouter(Process proc[], int *count)
{
    if (*count >= MAX_SIZE)
    {
        printf("Nb max of proc reached !\n");
        return;
    }

    pid_t pid = fork(); // child process created

    if (pid < 0)
    {
        perror("error - fork");
        return;
    }
    else if (pid == 0)
    {
        // executed code by child process
        printf("Je suis le processus fils\n");
        sleep(5); // simulation works of child pid
        exit(0); // process exit
    }
    else
    {
        // executed code by parent process
        printf("Je suis le processus parent, le PID du fils est : %d\n", pid);

        // save informations of child process
        snprintf(proc[*count].description, sizeof(proc[*count].description), "Processus %d", pid);
        proc[*count].pid = pid;
        proc[*count].ppid = getpid(); // PID of parent process
        (*count)++;
    }
}

void lister(Process proc[], int count)
{

    printf("Listing des processus\n");
    if (count == 0)
    {
        printf("No processus run\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d.%s - %d - %d\n", i + 1, proc[i].description, 
            proc[i].pid, proc[i].ppid
        );
    }
}

void supprimer(Process proc[], int *count, int index)
{
    if (index <= 0 || index > *count)
    {
        printf("error - index\n");
        return;
    }

    for (int j = index - 1; j < *count - 1; j++)
    {
        proc[j] = proc[j + 1];
    }
    (*count)--;
}

int main()
{
    Process proc[MAX_SIZE];
    
    int choix;
    int count = 0;

    do {
        menu();
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                ajouter(proc, &count);
                break;
            case 2:
                lister(proc, count);
                break;
            case 3:
                int index;
                printf("Entrez l'indice du processus à supprimer : ");
                scanf("%d", &index);
                supprimer(proc, &count, index);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid number\n");
                break;
        }

    } while (choix != 4);      

    printf("End of program...\n");

    return 0;
}