#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int value = 5;

int main(int argc, char* argv[])
{
    pid_t pid;
    
    pid = fork();
    
    if (pid > 0)
    {
        wait(NULL);
        printf("Parent: value = %d\n", value);
    }
    else if (pid == 0)
    {
        value += 15;
        printf("Child: value = %d\n", value);
    }
}
