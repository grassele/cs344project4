#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// clang -Wall -Wextra lswc.c

int main(int argc, char *argv[]) 
{
    (void) argc;

    int pfd[2];
    pipe(pfd);

    pid_t pid = fork();

    if (pid == 0) {
        // child
        dup2(pfd[0], 0);
        close(pfd[1]);
        execlp("wc", "wc", "-l", NULL);
        perror("exec");
        exit(1);
    } else {
        // parent
        dup2(pfd[1], 1);
        close(pfd[0]);
        execlp("ls", "ls", "-1a", argv[1], NULL);
        perror("exec");
        exit(1);
    }
}