//Mingyuan Li
//Computer system
//HW4
//3/24/2016
//Use C program to simulate round robin algorithm
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>

int quantum = 0;
int p1 = 0;
int p2 = 0;
int p3 = 0;
int p4 = 0;
int p5 = 0;

int front = 0;
int capacity = 5;
int size = 0;
int *queue;
int i = 0;
pthread_t t1;
pthread_t t2;
pthread_t t3;
pthread_t t4;
pthread_t t5;

void *part1(void *param);
void *part2(void *param);
void *part3(void *param);
void *part4(void *param);
void *part5(void *param);

int main(int argc, char* argv[])
{
    if (argc != 7) {
        printf("You need 6 arguments...\n");
        exit(0);
    }

    queue = (int*)malloc(sizeof(int) * 5);
    quantum = atoi(argv[1]);
    p1 = atoi(argv[2]);
    p2 = atoi(argv[3]);
    p3 = atoi(argv[4]);
    p4 = atoi(argv[5]);
    p5 = atoi(argv[6]);

    queue[0] = p1;
    queue[1] = p2;
    queue[2] = p3;
    queue[3] = p4;
    queue[4] = p5;

    while (1 == 1) {
        i = i % 5;
        if (p1 != 0 && i == 0) {
            pthread_create(&t1, 0, part1, queue);
            pthread_join(t1, NULL);
            sleep(1);
            i++;
        }
        // if p1 burst time is 0, i++, do p2, same as p2 p3 p4
        else if (p1 == 0 && i == 0) {
            i++;
        }
        else if (p2 != 0 && i == 1) {
            pthread_create(&t2, 0, part2, queue);
            pthread_join(t2, NULL);
            sleep(1);
            i++;
        }
        else if (p2 == 0 && i == 1) {
            i++;
        }
        else if (p3 != 0 && i == 2) {
            pthread_create(&t3, 0, part3, queue);
            pthread_join(t3, NULL);
            sleep(1);
            i++;
        }
        else if (p3 == 0 && i == 2) {
            i++;
        }
        else if (p4 != 0 && i == 3) {
            pthread_create(&t4, 0, part4, queue);
            pthread_join(t4, NULL);
            sleep(1);
            i++;
        }
        else if (p4 == 0 && i == 3) {
            i++;
        }
        else if (p5 != 0 && i == 4) {
            pthread_create(&t5, 0, part5, queue);
            pthread_join(t5, NULL);
            sleep(1);
            i = 0;
        }
        else if (p5 == 0 && i == 4) {
            //if p5 burst time is 0, i = 4 and p1 p2 p3 p4 all 0 then exit
            if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0) {
                exit(0);
            }
            //if not i++, do p1 p2 p3 p4
            else
            {
                i++;
            }
        }
        else
        {
            exit(0);
        }
    }
}
void *part1(void* param) {
    p1 = ((int*)param)[0];
    if (p1 <= quantum) {
        printf("P1 %d==>Exiting\n", p1);
        p1 = p1 - p1;
    }
    else
    {
        p1 = p1 - quantum;
        queue[0] = p1;
        printf("P1 %d\n", quantum);
    }
}
void *part2(void* param) {
    p2 = ((int*)param)[1];
    if (p2 <= quantum) {
        printf("P2 %d==>Exiting\n", p2);
        p2 = p2 - p2;
    }
    else
    {
        p2 = p2 - quantum;
        queue[1] = p2;
        printf("P2 %d\n", quantum);
    }
}
void *part3(void* param) {
    p3 = ((int*)param)[2];
    if (p3 <= quantum) {
        printf("P3 %d==>Exiting\n", p3);
        p3 = p3 - p3;
    }
    else
    {
        p3 = p3 - quantum;
        queue[2] = p3;
        printf("P3 %d\n", quantum);
    }
}
void *part4(void* param) {
    p4 = ((int*)param)[3];
    if (p4 <= quantum) {
        printf("P4 %d==>Exiting\n", p4);
        p4 = p4 - p4;
    }
    else
    {
        p4 = p4 - quantum;
        queue[3] = p4;
        printf("P4 %d\n", quantum);
    }
}
void *part5(void* param) {
    p5 = ((int*)param)[4];
    if (p5 <= quantum) {
        printf("P5 %d==>Exiting\n", p5);
        p5 = p5 - p5;
    }
    else
    {
        p5 = p5 - quantum;
        queue[4] = p5;
        printf("P5 %d\n", quantum);
    }
}
