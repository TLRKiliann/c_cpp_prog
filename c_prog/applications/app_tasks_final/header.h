#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_SIZE 100

typedef struct {
    char food[100];
    char transport[100];
} Expenses;

void menu();

void frais_alimentaires(Expenses expenses[], int *count);

void frais_transports(Expenses expenses[], int *count);

void listing(Expenses expenses[], int count);

void supprimer(Expenses expenses[], int *count);

void lecture_file();

void supprimer_file(const char *rm_file);

#endif