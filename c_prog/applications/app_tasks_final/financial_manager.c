#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include "header.h"

int main()
{
    FILE *filename;

    Expenses expenses[MAX_SIZE];

    const char *rm_file = "file.txt";

    int choix;
    int count = 0;
    int yes_no;

    do {
        menu();
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                frais_alimentaires(expenses, &count);
                break;
            case 2:
                frais_transports(expenses, &count);
                break;
            case 3:
                listing(expenses, count);
                break;
            case 4:
                supprimer(expenses, &count);
                break;
            case 5:
                lecture_file();
                break;
            case 6:
                printf("Do you want to remove file.txt ? (yes = 1 / no = 0)\n");
                scanf("%d", &yes_no);
                if (yes_no == 1)
                {
                    supprimer_file(rm_file);
                } else {
                    printf("File not removed !\n");
                }
                break;
            case 7:
                printf("Bye !\n");
                break;
            default:
                printf("Invalid number\n");
                break;
        }
    } while(choix != 7);

    return 0;
}
