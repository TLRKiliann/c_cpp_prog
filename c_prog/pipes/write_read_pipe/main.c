#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd_pipe[2];
    int nb_w, nb_r;
    char buff[512];
    char msg[] = "Alors comment ça va ? Tu vas bien oui ?";

    if (pipe(fd_pipe) == -1)
    {
        perror("error - pipe");
        return errno;
    }
    printf("Pipe read %d\nPipe write: %d\n", fd_pipe[0], fd_pipe[1]);

    nb_w = write(fd_pipe[1], msg, strlen(msg));
    if (nb_w == -1)
    {
        perror("error - write");
        return errno;
    }
    printf("Nb of octets written : %d\n", nb_w);

    nb_r = read(fd_pipe[0], buff, nb_w);
    if (nb_r == -1)
    {
        perror("error - read");
        return errno;
    }
    printf("Nb of octets readen : %d\n", nb_r);

    write(STDOUT_FILENO, buff, nb_r);
    write(STDOUT_FILENO, "\n", 1);

    printf("Fin du programme !");

    return 0;
}
