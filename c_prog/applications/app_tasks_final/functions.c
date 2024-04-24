#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"

void menu()
{
    printf("\nMenu\n");
    printf("1.Frais alimentaires\n");
    printf("2.Frais transports\n");
    printf("3.Listing (record data)\n");
    printf("4.Supprimer par id\n");
    printf("5.Lecture du fichier\n");
    printf("6.Supprimer le fichier file.txt\n");
    printf("7.Exit\n");
}

void frais_alimentaires(Expenses expenses[], int *count)
{
    FILE *filename;

    filename = fopen("file.txt", "a");

    if (filename == NULL)
    {
        printf("error - to open file (frais_alimentaires)");
        return;
    }

    if (*count >= MAX_SIZE)
    {
        printf("error - count");
        return;
    }

    printf("Combien avez-vous dépensé en food ? (ex: 100 ou 22.30)\n");
    scanf("%s", expenses[*count].food);

    fprintf(filename, "Food: %s\n", expenses[*count].food);
    fclose(filename);
    (*count)++;
}

void frais_transports(Expenses expenses[], int *count)
{
    FILE *filename;

    filename = fopen("file.txt", "a");

    if (filename == NULL)
    {
        printf("error - to open file (frais_transports)");
        return;
    }

    if (*count >= MAX_SIZE)
    {
        printf("error - count");
        return;
    }

    printf("Combien avez-vous dépensé en tranports ? (ex: 100 ou 22.30)\n");
    scanf("%s", expenses[*count].transport);

    fprintf(filename, "Transports: %s\n", expenses[*count].transport);
    fclose(filename);
    (*count)++;
}

void listing(Expenses expenses[], int count)
{
    FILE *filename;

    filename = fopen("file.txt", "a");

    time_t temps_actuel = time(NULL);

    struct tm *date_heure = localtime(&temps_actuel);
    
    char date[20];

    strftime(date, sizeof(date), "%Y-%m-%d", date_heure);
    
    if (filename == NULL) {
        printf("error - open file (listing)\n");
        return;
    }

    if (count == 0)
    {
        printf("No expenses\n");
        return;
    }

    float total_food = 0;
    float total_transport = 0;
    
    for (int i = 0; i < count; i++)
    {
        printf("%d.", i + 1);
        // Display expenses food (unitaire)
        if (expenses[i].food[0] != '\0') {
            printf("food: %s\n", expenses[i].food);
            total_food += atof(expenses[i].food); // atof
        }
        // Display expenses transports (unitaire)
        if (expenses[i].transport[0] != '\0') {
            printf("transports: %s\n", expenses[i].transport);
            total_transport += atof(expenses[i].transport); // atof
        }
    }
    float expenses_total = total_food + total_transport;
    // Display expenses
    printf("Total food: %.2f\n", total_food);
    printf("Total transports: %.2f\n", total_transport);
    printf("*Date: %s\n", date);
    printf("+ TOTAL expenses => %.2f\n", expenses_total);

    // copy to file.txt
    fprintf(filename, "Total food: %.2f\n", total_food);
    fprintf(filename, "Total transport: %.2f\n", total_transport);
    fprintf(filename, "*Date: %s\n", date);
    fprintf(filename, "+ Total: %.2f\n", expenses_total);

    fclose(filename);
}

void supprimer(Expenses expenses[], int *count)
{   
    int index;
    int choix_suppression;

    printf("Voulez-vous supprimer food = 1 / transports = 2: \n");
    scanf("%d", &choix_suppression);

    if (choix_suppression != 1 && choix_suppression != 2) 
    {
        printf("Choix invalide\n");
        return;
    }

    printf("Entrez l'id de la dépense à supprimer: ");
    scanf("%d", &index);

    if (index < 1 || index > *count) 
    {
        printf("Index invalide\n");
        return;
    }

    if (choix_suppression == 1) {
        // Remove expenses food by id (displayed in terminal)
        for (int i = index - 1; i < *count - 1; i++) {
            strcpy(expenses[i].food, expenses[i + 1].food);
            strcpy(expenses[i].transport, expenses[i + 1].transport);
        }
    } else if (choix_suppression == 2) {
        // Remove expenses transport by id (displayed in terminal)
        for (int i = index - 1; i < *count - 1; i++) {
            strcpy(expenses[i].food, expenses[i].food);
            strcpy(expenses[i].transport, expenses[i + 1].transport);
        }
    }
    (*count)--;
}

void lecture_file()
{
    FILE *read_f;

    read_f = fopen("file.txt", "r");
    
    char myString[512];

    if (read_f == NULL)
    {
        perror("error - file.txt not found (1).\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(myString, 512, read_f))
    {
        printf("%s", myString);
    }
    fclose(read_f);
}

void supprimer_file(const char *rm_file)
{
    if (remove(rm_file) != 0)
    {
        perror("error - file.txt not found (2).\n");
        exit(EXIT_FAILURE);
    }

    printf("File %s was removed as success.\n", rm_file);
}
