#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

//Mingyuan Li
//Computer system
//HW3
//2/17/2016
//User give a number, program use one thread to find out all prime numbers and list

int *list;
int prime;
int count;
int N;

void *calculate_prime(void *param);

int main(int argc, char *argv[])
{
    int i;
    if(argc != 2)
    {
        printf("You should enter the range...\n");
        exit(0);
    }
    N =atoi(argv[1]);
    if(N < 2)
    {
        printf("There is not have prime number less than 2\n");
        exit(0);
    }
    
    pthread_t t1;
    list = malloc(sizeof(int) * N);

    printf("Prime numbers are....\n");
    pthread_create(&t1, 0, calculate_prime, NULL);
    pthread_join(t1, NULL);
}
void *calculate_prime(void *param)
{
    int i;
    int j;
    int flag;
    for(i = 2; i <= N; i++)
    {
        flag = 0;
        for(j = 2; j <= i/2; j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            printf("%d\n", i);
    }
    pthread_exit(0);
}
