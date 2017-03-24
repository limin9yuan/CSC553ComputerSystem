#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("%d\n", getpid());
    fork();
    printf("%d\n", getpid());

    fork();
    printf("%d\n", getpid());

    fork();
    printf("%d\n", getpid());

    return 0;
}
