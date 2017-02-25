#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int x;
    int y;
}POINT;

int main(int argc, char *argv[]) {
    int *ptr_one; //use in int malloc example
    POINT *ptr_two; //use in struct example
    ptr_one = (int*) malloc(sizeof(int)); //ask memory for one int
    if (ptr_one == 0)
    {
        printf("Something wrong in memory\n");
        return -1;
    }
    *ptr_one = 25;
    printf(" %d\n", *ptr_one);
    free(ptr_one);

    //struct example
    ptr_two = (POINT*) malloc(sizeof(int));
    if (ptr_two == 0)
    {
        printf("Problem with struct memory\n");
        return -1;
    }
    ptr_two->x = 3; //one way to write it
    (*ptr_two).y = 7; //another way to write it
    printf(" X is  %d\n",ptr_two->x);
    printf(" Y is %d\n", ptr_two->y);

    free(ptr_two);
    return 0;
}
