#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    if(fork())
    {
        void catchMe();
        signal(SIGUSR1, catchMe); //call catchMe if we get SIGUSR1
        for(;;)
            printf("I'm the parent.\n");
    }
    else
    {
        sleep(3);
        kill(getppid(), SIGUSR1);
    }
}
void catchMe()
{
    printf("Got the signal.\n");
    exit(0);
}
