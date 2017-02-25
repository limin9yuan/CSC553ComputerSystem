#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define RD 0
#define WT 1

int main(int argc, char *argv[])
{
    int p1[2];
    pipe(p1);
    switch (fork()) {
        case -1:error("Fork error");
                break;
        case 0: //child does the ls
                close(fileno(stdin)); //no need for stdout here
                dup(p1[RD]); //duplicate the descriptor for writing
                close(p1[WT]);
                close(p1[RD]);
                execlp("grep", "grep",".c", NULL);
                break;
        default: //parent does grep
                close(fileno(stdout)); //no need for stdin here
                dup(p1[WT]);
                close(p1[WT]);
                close(p1[RD]);
                execlp("ls", "ls",NULL);
                break;
    }
    return 0;
}
