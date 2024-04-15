#include <stdbool.h>

#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#define MAX_TASKS 100

typedef struct {
    char description[20];
    bool completed;
} Task;

void menu();

void ajouter(Task tasks[], int *count);

void lister(Task tasks[], int count);

void terminer(Task tasks[], int count);

void supprimer(Task tasks[], int *count);

#endif