#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fichier;

    fichier = fopen("file.txt", "w");

    int *ptr, n, i, j, k, reg, sum = 0, arr = 0;

    printf("Enter nb of program to register ?\n");
    scanf("%d", &n);

    ptr = (int *) malloc(n * sizeof(int));

    if (!ptr)
    {
        printf("Error with malloc");
        exit(1);
    }

    printf("Enter nb of Mo for each program\n");
    for (i = 0; i < n; i++)
    {
        printf("Prog n°%d: ", i + 1);
        scanf("%d", ptr + i);
        sum += *(ptr + i);
        arr += *ptr;
    }

    printf("\nTotal : %d Mo\n", sum);

    if (!fichier)
    {
        printf("Erreur");
        return 1;
    }

    // write into file.txt
    for (j=0; j < sizeof(arr); j++)
    {
        if (ptr[j] != 0)
        {
            printf("Mo saved: %d\n", ptr[j]);
            reg += ptr[j];
            fprintf(fichier, "Program %d : %d\n", j+1, ptr[j]);
        } else {
            break;
        }
    }

    printf("\nTotal registered : %d Mo\n\n", reg);

    for (k = 0; k < sizeof(arr); k++)
    {
        if (ptr[k] != 0)
        {
            printf("+ Prog with %d Mo - ", ptr[k]);
            printf("saved\n");
        }
        else {
            break;
        }
    }

    fclose(fichier);

    free(ptr);

    return 0;
}
