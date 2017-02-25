//Demonstration of how to create and use an unnamed
//unix pipe to communicate between a parent and a child

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define RD 0
#define WT 1

int main(int argc, char *argv[]) {
    printf("Parent running\n");
    int fd[2];
    pipe(fd);
    if (pipe(fd) == -1)
    {
        printf("Failed to create pipe\n");
        return -1;
    }

    //Create child process
    int pid = fork();

    //fork returns pid of child process in parent
    //and 0 in the child
    if (pid != 0) {
        printf("Parent running after fork\n");

        //parent will write to the pipe. so close
        //the read end of the pipe and begin writing data
        close(fd[RD]);
        char *str1 = "printing to the pipe\0";
        char *str2 = "putting more in pipe\0";

        printf("Parent writing: %s\n", str1);
        write(fd[WT], str1, 21);
        sleep(3);
        printf("Parent writing: %s\n", str2);
        write(fd[WT], str2, 21);

        close(fd[WT]);
        printf("Parent done\n");
    }
    else
    {
        printf("Child running\n");

        //the child will read from pipe. so close the
        //write end of the pipe and begin reading until the
        //parent close the pipe
        close(fd[WT]);
        char buf[100];
        while (read(fd[RD], buf, 100) != 0) {
            printf("%s\n", buf);
        }
        close(fd[RD]);
        printf("Child done\n");
    }
    return 0;
}
