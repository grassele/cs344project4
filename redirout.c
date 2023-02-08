#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// clang -Wall -Wextra redirout.c

int main(int argc, char *argv[]) 
{
    if (argc < 3) {
        printf("Too few arguments. Please supply filename and command.\n");
        exit(0);
    }

    int fd;
    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd, 1);

    char *com_args[10];
    for (int i = 2; i < argc; i++) {
        com_args[i-2] = argv[i];
    }

    execlp(com_args, NULL);


}