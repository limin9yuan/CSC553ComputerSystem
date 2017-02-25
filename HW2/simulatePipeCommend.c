//Mingyuan Li
//Computer System
//HW2
//2/10/2016
//simulates unix pipe
//ls -l | sort  | grep .c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define RD 0
#define WT 1

int main(int argc, char* argv[])
{
    int p1[2];
    int p2[2];
    
    pipe(p1);
    pipe(p2);

    switch(fork())
    {
        case -1:
                perror("Fork error");
                break;

        case 0://child does the ls
                close(fileno(stdout)); //no need  for stdout here
                dup(p1[WT]); //duplicate the descriptor for writing
                close(p1[WT]);
                close(p1[RD]);
                execlp("ls","ls","-l",NULL);

                break;

        default://parent does grep
		switch(fork())
                {
                    case -1:
                            perror("Fork error");
                            break;

                    case 0://child does the ls
                            close(fileno(stdin));
                            dup(p1[RD]);
                            close(p1[WT]);
                            close(p1[RD]);
                            close(fileno(stdout));
                            dup(p2[WT]);
                            close(p2[WT]);
                            close(p2[RD]);
                            execlp("sort","sort",NULL);

                            break;

                    default://parent does grep
                            close(fileno(stdin));// no need for stdin here
                            dup(p2[RD]); // duplicate the descriptor for reading
                            close(p2[WT]);
                            close(p2[RD]);
                            close(p1[WT]);
                            close(p1[RD]);
                            execlp("grep","grep",".c",NULL);
		
                            break;
                }
                break;
    }
    return 0;
}
