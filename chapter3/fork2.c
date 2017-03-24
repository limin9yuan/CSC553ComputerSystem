#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
        printf("Parent running\n");
        int pid = fork();
        
        if(pid != 0)
        {
                printf("Parent running after fork\n");
                wait(NULL);
                printf("Parent done\n");
        }
        else
        {
                printf("Child running\n");
                sleep(5);
                printf("Child done\n");
        }
}
