#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>

//Mingyuan Li
//Computer system
//HW3
//2/17/2016
//User give a range, program use four thread to calculate the sum

int *list;
int sum;

void *part1(void *param);
void *part2(void *param);
void *part3(void *param);
void *part4(void *param);

int main(int argc, char *argv[])
{
    int i;
    if(argc != 3)
    {
        printf("You need three arguments....\n");
        exit(0);
    }
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int length = end - start + 1;

    list = (int*)malloc(sizeof(int) * length);

    for(int i = 0; i < length - 1; i++)
    {
        list[i] = i + start;
        printf("%d\n", list[i]);
    }
    
    int block = length / 4;
    int size1 = block;
    int size2 = block;
    int size3 = block;
    int size4 = length - (3 * block);

    int start1 = 0;
    int start2 = block;
    int start3 = start2 + block;
    int start4 = start3 + block;

    int ray1[2] = {start1, size1};
    int ray2[2] = {start2, size2};
    int ray3[2] = {start3, size3};
    int ray4[2] = {start4, size4};

    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;

    pthread_create(&t1, 0, part1, ray1);
    pthread_create(&t2, 0, part2, ray2);
    pthread_create(&t3, 0, part3, ray3);
    pthread_create(&t4, 0, part4, ray4);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("Sum is %d\n", sum);
}
void *part1(void *param)
{
    //int *p = (int*)param;
    int start = ((int*)param)[0];
    int size = ((int*)param)[1];

    for(int i = 0; i < size; i++)
    {
        sum += list[i + start];
    }
}
void *part2(void *param)
{
    int start = ((int*)param)[0];
    int size = ((int*)param)[1];

    for(int i = 0; i < size; i++)
    {
        sum += list[i + start];
    }
}
void *part3(void *param)
{
    int start = ((int*)param)[0];
    int size = ((int*) param)[1];

    for(int i = 0; i < size; i++)
    {
        sum += list[i + start];
    }
}
void *part4(void *param)
{
    int start = ((int*) param)[0];
    int size = ((int*) param)[1];

    for(int i = 0; i < size; i++)
    {
        sum += list[i + start];
    }
}
