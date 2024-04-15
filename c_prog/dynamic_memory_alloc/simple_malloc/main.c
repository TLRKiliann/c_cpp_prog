#include <stdio.h>

int main(int argc, char *argv[])
{
    int *ptr, i, n, sum = 0;

    printf("How many app in memory ?\n");
    scanf("%d", &n);

    // malloc
    ptr = (int *) malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Error in malloc");
        exit(1);
    }

    printf("How many size by prog ?\n");
    for (i = 0; i < n; i++)
    {
        printf("Prog : %d : ", i + 1);
        scanf("%d", ptr + i );
        sum += *(ptr + i);
    }

    printf("Sum : %d Mo\n", sum);

    //printf("ptr: %p\n", *ptr);

    free(ptr);

    //printf("ptr: %p\n", *ptr); // addr change

    return 0;
}
