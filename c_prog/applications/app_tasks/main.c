#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Task tasks[MAX_TASKS];

    int count = 0;
    int choix;

    do {
        menu();

        if (scanf("%d", &choix) != 1)
        {
            printf("It's not a number.\n");
            exit(EXIT_FAILURE);
        }

        switch (choix)
        {
            case 1:
                ajouter(tasks, &count);
                break;
            case 2:
                lister(tasks, count);
                break;
            case 3:
                terminer(tasks, count);
                break;
            case 4:
                supprimer(tasks, &count);
                break;
            case 5:
                printf("End of prog...\n");
                break;
            default:
                printf("Invalid number");
        }
    } while (choix != 5);

    return 0;
}