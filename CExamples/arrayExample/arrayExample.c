#include <stdio.h>

int main(int argc, char *argv[])
{
    //an array with 6 elements
    double gpa[6] = {3.4,3.2,2.5,2.6,3.6,3.8};

    double *p;
    int i;
    p = gpa;

    //output each element using pointer
    for (i = 0; i < 6; i++)
    {
        printf("*(p + %d) : %3.1f\n", i, *(p + i) );
    }

    //output using gpa address
    for (i = 0; i < 6; i++)
    {
        printf("*(gpa + %d) : %3.1f\n", i, *(gpa + i));
    }

    double *tmp = gpa;
    for (i = 0; i < 6; i++)
    {
        printf("*(tmp + %d) : %3.1f\n", i, *tmp);
        tmp++;
    }

    return 0;
}
