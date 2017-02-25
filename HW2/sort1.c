#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define N 5
//Mingyuan Li
//Computer System
//HW2
//2/10/2016
//Sort an array, parent do increase sort, child do decrease sort
int increaseSort(int n, int a[])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int decreaseSort(int n, int a[])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }   
}
int main(int argc, char* argv[])
{
    int ray[N];
    srand(time(NULL));
    for(int i = 0; i < 5; i++)
    {
        ray[i] = rand() % 100;
    }
    int pid = fork();
    if(pid != 0)
    {
        printf("Parent sort.\n"); 
        increaseSort(5, ray);
        for(int i = 0; i < 5; i++)
        {
            printf("%d ", ray[i]);
        }
        printf("\n");
    }
    else
    {
        sleep(1);
        printf("\nChild sort.\n");
        decreaseSort(5, ray);
        for(int i = 0; i < 5; i++)
        {
            printf("%d ", ray[i]);
        }
    }
    return 0;
}
