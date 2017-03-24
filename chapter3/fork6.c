#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int pid = fork();
    int count = 1;
    if(pid != 0)
    {
        for(int i = 0; i < 10; i++)
        {
            printf("%d Parent process running.\n", count);
            count++;
            sleep(1);
        }
        wait(NULL);
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            printf("%d Child process running.\n", count);
            count++;
            sleep(1);
        }
    }
}
