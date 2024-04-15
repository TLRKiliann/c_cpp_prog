#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CONTAINER 100

typedef struct {
    char box[100];
} Container;

typedef struct {
    char str[20];
    bool complete;
} Task;

void menu()
{
    printf("1.ajouter\n");
    printf("2.lister\n");
    printf("3.marquer\n");
    printf("4.exit\n");
}

//add sentence into box of container struct
void ajouter(Container container[], Task tasks[], int *cpt)
{
    if (*cpt >= MAX_CONTAINER)
    {
        printf("Max nb reached\n");
        return;
    }

    printf("Entrer votre phrase\n");
    scanf(" %[^\n]", container[*cpt].box);
    strcpy(tasks[*cpt].str, container[*cpt].box); //copy str to box
    tasks[*cpt].complete = false;
    (*cpt)++;
}

//display box from container
void lister(Task tasks[], int cpt)
{
    if (cpt == 0)
    {
        printf("Aucune entrée\n");
        return;
    }

    for (int i = 0; i < cpt; i++)
    {
        //display from 2 struct !!!
        printf("Tasks str => %d.%s - [%s]\n", i + 1, tasks[i].str, 
            tasks[i].complete ? "Terminate" : "Not finished"
        );
    }
}

void marked(Task tasks[], int cpt)
{
    int index;
    printf("Le quel voulez-vous qu'il termine ?\n");
    scanf("%d", &index);

    if (index < 1 || index > cpt)
    {
        printf("error - index");
        return;
    }

    tasks[index - 1].complete = true;
    printf("Changement effectué.\n");
}

int main()
{
    Task tasks[MAX_CONTAINER];
    Container container[MAX_CONTAINER];
    int cpt = 0;
    int choix;

    do {
        menu();
        printf("Choix ?\n");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                ajouter(container, tasks, &cpt);
                break;
            case 2:
                lister(tasks, cpt);
                break;
            case 3:
                marked(tasks, cpt);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid nb\n");
                break;
        }

    } while (choix != 4);

    return 0;
}