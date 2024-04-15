#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

void menu()
{
    printf("\nMenu\n");
    printf("1.Ajouter une tache\n");
    printf("2.Lister une tache\n");
    printf("3.Terminer une tache\n");
    printf("4.Supprimer une tache\n");
    printf("5.Quitter\n");
}

void ajouter(Task tasks[], int *count)
{
    if (*count >= MAX_TASKS)
    {
        printf("Nb maximale de tache atteinte\n");
        return;
    }
    printf("Ajouter une descritption\n");
    scanf(" %[^\n]", tasks[*count].description);
    tasks[*count].completed = false;
    (*count)++;
}

void lister(Task tasks[], int count)
{
    if (count == 0)
    {
        printf("Aucune tache à afficher\n");
        return;
    }
    
    for (int i = 0; i < count; i++)
    {
        if (tasks[i].description != NULL && strlen(tasks[i].description) > 19)
        {
            printf("\n%d - error - description too long !\n", i + 1);
        }
        else
        {
            printf("\n%d.%s - [%s]", i + 1, 
                tasks[i].description, 
                tasks[i].completed ? "Terminated" : "Not finished"
            );
        }
    }
}

void terminer(Task tasks[], int count)
{
    int index;
    printf("Indicate nb of task to stop\n");
    scanf("%d", &index);

    if (index < 1 || index > count)
    {
        printf("Index non trouvé\n");
        return;
    }
    tasks[index - 1].completed = true;
    printf("Task marked as finished.\n");
}

void supprimer(Task tasks[], int *count)
{
    int index;
    printf("Indicate number of task to delete\n");
    scanf("%d", &index);

    if (index < 1 || index > *count)
    {
        printf("Don't exist into index\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }
    (*count)--;
}