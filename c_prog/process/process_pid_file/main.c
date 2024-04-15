#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// sudo demandé une x pour les 3 commandes.

int main() {
    FILE *file_cmd;

    file_cmd = fopen("file.txt", "w");
    if (file_cmd == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    //pid_1
    int pid_1 = fork();
    if (pid_1 == -1) {
        perror("Error with process 1");
        exit(EXIT_FAILURE);
    } else if (pid_1 == 0) {
        dup2(fileno(file_cmd), STDOUT_FILENO);
        execlp("netstat", "netstat", "-puten", NULL);
        perror("Error executing netstat");
        exit(EXIT_FAILURE);
    } else {
        printf("Cmd 1 launched !\n");
    }

    // pid_2
    int pid_2 = fork();
    if (pid_2 == -1) {
        perror("Error with process 2");
        exit(EXIT_FAILURE);
    } else if (pid_2 == 0) {
        dup2(fileno(file_cmd), STDOUT_FILENO);
        execlp("nmap", "nmap", "-sS", "10.0.2.15", NULL);
        perror("Error executing nmap");
        exit(EXIT_FAILURE);
    } else {
        printf("Cmd 2 launched !\n");
    }

    // pid_3
    int pid_3 = fork();
    if (pid_3 == -1) {
        perror("Error with process 3");
        exit(EXIT_FAILURE);
    } else if (pid_3 == 0) {
        dup2(fileno(file_cmd), STDOUT_FILENO);
        execlp("journalctl", "journalctl", "-k", "-e", NULL);
        perror("Error executing journalctl");
        exit(EXIT_FAILURE);
    } else {
        printf("Cmd 3 launched !\n");
    }

    fclose(file_cmd);

    wait(NULL);
    wait(NULL);

    sleep(1);

    // Display content file
    file_cmd = fopen("file.txt", "r");

    if (file_cmd == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char c;
    printf("Content of file.txt :\n");

    while ((c = fgetc(file_cmd)) != EOF) {
        putchar(c);
    }

    fclose(file_cmd);

    return 0;
}
