#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//./main file.txt
int main(int argc, char *argv[])
{
    char *buff;
    if (argc < 2)
    {
        printf("arg %s", argv[0]);
        return 1;
    }

    buff = dirname(argv[1]);
    if (buff != NULL)
    {
        printf("Le dirname est : %s\n", buff);
    }
    else
    {
        perror("error - dirname");
        return errno;
    }

    buff = basename(argv[1]);
    if (buff != NULL)
    {
        printf("Le basename est : %s\n", buff);
    }
    else
    {
        perror("error - basename");
        return errno;
    }

    return 0;
}
