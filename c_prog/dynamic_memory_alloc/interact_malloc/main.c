#include <stdio.h>
#include <stdlib.h>

struct myStruct {
    int mySuperNum;
    char mySuperHero[255];
} s1;

void myFunc()
{
    int *myNum = NULL;
    int c = 5;
    myNum = &c;

    printf("myNum : %d\n", *myNum); // 5
    printf("pointer addr : %p\n", myNum); // addr (myNum = &c)
    printf("pointer addr of c : %p\n", &c); // addr
    printf("myNum value : %d\n", c); // 5
}

int main(int argc, char *argv[])
{
    s1.mySuperNum = 44;
    strcpy(s1.mySuperHero, "Alphonso Le grand");
    printf("%d\n", s1.mySuperNum);
    printf("%s\n", s1.mySuperHero);

    myFunc();

    int *ptr, nb_amis, i, sum = 0;

    printf("Combien d'amis ?\n");
    scanf("%d", &nb_amis);
    printf("Vous avez %d\n", nb_amis);

    // malloc
    ptr = (int *) malloc(nb_amis * sizeof(int));

    if (ptr == NULL)
    {
        exit(1);
    }

    printf("Pointer : %p\n", ptr); // addr

    printf("Enter an element\n");
    for (i = 0; i < nb_amis; i++)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("La somme : %d", sum);

    free(ptr);

    return 0;
}
