//Demonstration of how to fork a child process and then
//have that child process load a new executable
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Parent running\n");
    int pid = fork();
    if (pid != 0) {
        wait(NULL);
        printf("Parent done\n");
    }
    else
    {
        printf("Child running\n");

        //The full or relative path to the program that
        //will be run in the new process
        char prog[] = "/bin/ls";

        //setup the args for running the ls program with
        //the command line argument of -l
        char *args[3];
        args[0] = "ls";
        args[1] = "-l";
        args[2] = NULL;

        //replace the child process with the ls program
        //and pass it the args. args[0] must be the name
        //of the program without any path. The remaining
        //entries of args are the command line arguments to
        //the program. The last entriy is args must be NULL
        int rv = execv(prog, args);

        //if execv returns at all there was an error with
        //the new process. Probably the file did not exist
        //or it was not executable
        printf("Problem with execv\n");
    }
    return 0;
}
