#include <stdio.h>
#include <string.h>

#define MAX_ROUND 3

typedef struct Vitality {
    int heal;
} v1;

typedef struct {
    struct Vitality v1;
    char name[100];
    int age;
    int life;
} Player;

void menu()
{
    printf("\nMenu\n");
    printf("1.Fight\n");
    printf("2.Resume\n");
    printf("3.Heal\n");
    printf("4.Exit\n");
}

void fight_func(Player one[], Player two[], int *count)
{
    int choice;
    if (*count >= MAX_ROUND)
    {
        printf("error - count\n");
        return;
    }
    printf("Fighting\n");

    strcpy(one->name, "Chloe");
    strcpy(two->name, "Doug");
    one->age = 33;
    two->age = 44;

    printf("Enter player that you are (1 or 2): \n");
    scanf("%d", &choice);
    
    if (choice == 1) 
    {
        two->life -= 50;
        if (two->life > 0)
        {
            printf("%s keep alive with %d\n", two->name, two->life);
        }
        else
        {
            printf("%s is dead with %d\n", two->name, two->life);
            return;
        }
    } else if (choice == 2) {
        one->life -= 50;
        if (one->life > 0)
        {
            printf("%s keep alive with %d\n", one->name, one->life);
        }
        else 
        {
            printf("%s is dead with %d\n", one->name, one->life);
            return;
        }
    } else {
        printf("Invalid number\n");
        return;
    }
    (*count)++;
}

void resume_func(Player one[], Player two[])
{
    printf("Player one: %s\n", one[0].name);
    printf("Player two: %s\n", two[0].name);
    printf("Age: %d\n", one[0].age);
    printf("Age: %d\n", two[0].age);
    printf("Life 1: %d\n", one[0].life);
    printf("Life 2: %d\n", two[0].life);
}

void heal_func(Player one[], Player two[])
{
    int player;
    printf("Choose your player number (1 or 2)\n");
    scanf("%d", &player);

    //complex struct call
    if (player == 1)
    {
        one[0].life += one->v1.heal;
        printf("%s recover life by heal of +50. Total life is: %d\n", 
            one[0].name, one[0].life
        );
    } 
    else if (player == 2)
    {
        two[0].life += one->v1.heal;
        printf("%s recover life by heal of +50. Total life is: %d\n", 
            two[0].name, two[0].life
        );
    }
    else
    {
        printf("Invalid number\n");
        return;
    }
}

int main()
{
    Player one[MAX_ROUND];
    Player two[MAX_ROUND];

    int play;
    int count = 0;

    one->life = 100;
    two->life = 100;

    //complex struct init
    one->v1.heal = 20;
    printf("Heal : %d", one->v1.heal);

    do {
        menu();
        scanf("%d", &play);

        switch (play)
        {
            case 1:
                fight_func(one, two, &count);
                break;
            case 2:
                resume_func(one, two);
                break;
            case 3:
                heal_func(one, two);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (play != 4);

    return 0;
}