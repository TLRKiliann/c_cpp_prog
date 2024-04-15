#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>

#define _GNU_SOURCE

#define PIPE_BUF 100

int main(int argc, char *argv[])
{
    int fd_pipe[2];
    int nb_w, nb_r;
    int cpt=1;
    int F_SETPIPE_SZ = 4;
    int F_GETPIPE_SZ = 4;
    int coderet;
    char buff[PIPE_BUF];
    char msg[] = "Le Hello Message !\n";
    long maxtaille;

    struct stat infos;


    if (pipe(fd_pipe) == -1)
    {
        perror("pipe - error");
        return errno;
    }
    printf("FD => Pipe read[0]: %d\nFD => Pipe write[1]: %d\n", fd_pipe[0], fd_pipe[1]);

    printf("PIPE_BUFF (w atomique) : %ld\n", PIPE_BUF);

    maxtaille = fcntl(fd_pipe[0], F_GETPIPE_SZ);
    if (maxtaille == -1)
    {
        perror("F_GETPIPE_SZ error");
    }
    printf("Taille maximale du pipe: %ld\n", maxtaille);

    if (nb_w == -1)
    {
        perror("write");
        return errno;
    }
    printf("nb_w => %d\n", nb_w);

    coderet = fstat(fd_pipe[1], &infos);
    if (!coderet)
    {
        printf("st_dev : %ld\n", infos.st_dev);
        printf("st_ino : %ld\n", infos.st_ino);
        printf("st_mode : %lo octets\n", infos.st_mode);
        if ((infos.st_mode & S_IFMT) == S_IFIFO)
        {
            printf("C'est FIFO\n");
        }
        else
        {
            printf("C'est pas FIFO\n");
        }
        printf("st_size %ld\n", infos.st_size);
    }
    else
    {
        perror("coderet");
        return errno;
    }

    maxtaille = PIPE_BUF * 4;

    if (fcntl(fd_pipe[0], F_SETPIPE_SZ, maxtaille) == -1)
    {
        perror("S_SETPIPE_SZ error");
        return errno;
    }

    maxtaille = fcntl(fd_pipe[0], F_GETPIPE_SZ);

    if (maxtaille == -1)
    {
        perror("maxtaille");
        return errno;
    }

    printf("Taille maximale du pipe (2): %ld\n", maxtaille);

    // we writte until pipe is saturated.
    while (write(fd_pipe[1], buff, PIPE_BUF) != -1)
    {
        printf("compteur: %d\nPIPE_BUF: %d\n", cpt++, PIPE_BUF);
        printf("errno result: %d\n", errno);
        perror("error to catch buffer !\n");
        return errno;
    }

    nb_r = read(fd_pipe[0], buff, nb_w);
    if (nb_r == -1)
    {
        perror("read");
        return errno;
    }
    if (nb_r)
    {
        printf("nb_r => %d\n", nb_r);
        write(STDOUT_FILENO, buff, nb_r);
        write(STDOUT_FILENO, "\n", 1);
    }

    printf("Fin du progamme !\n");

    return 0;
}
