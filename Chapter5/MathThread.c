//Solution to exercise 4.21
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int *list;

double average;
int maximum;
int minimum;

void *calculate_average(void *param);
void *calculate_maximum(void *param);
void *calculate_minimum(void *param);

int main(int argc, char *argv[]) {
    int i;
    int num_of_args = argc - 1;
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    list = (int*)malloc(sizeof(int) * num_of_args);
    for (i = 0; i < num_of_args; i++)
    {
        list[i] = atoi(argv[i + 1]);
    }
    pthread_create(&t1, 0, calculate_average, &num_of_args);
    pthread_create(&t2, 0, calculate_maximum, &num_of_args);
    pthread_create(&t3, 0, calculate_minimum, &num_of_args);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("The average is %f\n", average);
    printf("The maximum is %d\n", maximum);
    printf("The minimum is %d\n", minimum);
    return 0;
}
void *calculate_average(void *param)
{
    int count = *(int*)param;
    int i, total = 0;
    for (i = 0; i < count; i++)
    {
        printf("%d\n", list[i]);
        total += list[i];
    }
    average = total / count;
}
void *calculate_maximum(void *param)
{
    int count = *(int*)param;
    int i;
    maximum = list[0];

    for (i = 0; i < count; i++) {
        if (list[i] > maximum) {
            maximum = list[i];
        }
    }
}
void *calculate_minimum(void *param)
{
    int count = *(int*)param;
    int i;
    minimum = list[0];

    for (i = 0; i < count; i++)
    {
        if (list[i] < minimum) {
            minimum = list[i];
        }
    }
}
