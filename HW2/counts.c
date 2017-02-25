#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
//Mingyuan Li
//Computer System
//HW2
//2/10/2016
//Program count vowels and words from file

int main(int argc, char* argv[])
{
    int countV = 0;
    int countW = 0;
    FILE *f;
    char oneChar[1];
    char oneWord[100];
    f = fopen(argv[1], "r");

    if(argc < 2 || argv[1] == NULL)
    {
        printf("Less arguments, exit...\n");
        exit(1);
    }
    
    if(fork() != 0)
    {
        if(f == NULL)
        {
            printf("Can't open file for reading...\n");
            exit(1);
        }
        while(fscanf(f, "%c", oneChar) == 1)
        {
            if(oneChar[0] == 'a' || oneChar[0] == 'e' || oneChar[0] == 'i' || oneChar[0] == 'o' || oneChar[0] == 'u')
                countV++;
            if(oneChar[0] == 'A' || oneChar[0] == 'E' || oneChar[0] == 'I' || oneChar[0] == 'O' || oneChar[0] == 'U')
                countV++;
        }
        printf("There are %d vowels.\n", countV);
        wait(NULL);
    }
    else
    {
        f = fopen(argv[1], "r");
        if(f == NULL)
        {
            printf("Can't open file for reading...\n");
        }
        while(fscanf(f, "%s", oneWord) == 1)
        {
            countW++;
        }
        printf("There are %d words.\n", countW);
    }
    return 0;
}
