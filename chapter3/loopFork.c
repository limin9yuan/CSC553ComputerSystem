#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int i;
    for(i = 0; i < 4; i++)
    {
        fork();
        printf("%d fork.\n", i + 1);
    }
    return 0;
}
