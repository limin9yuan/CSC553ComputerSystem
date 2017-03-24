#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    if(fork()) //fork , assume it always works.
    {
        for(;;) //parent prints a message forever
            printf("I'm the parent\n");
    }
    else // child
    {
        sleep(3);
        kill(getppid(), SIGKILL);//kill parent
    }
}
