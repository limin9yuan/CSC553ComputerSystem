#include <stdio.h>

void swapping_by_value(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("In function swapping by value a and b are %d %d\n", a, b);
}
void swapping_by_reference(int *ptr_a, int *ptr_b)
{
    int temp;
    temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
    printf ("In function swapping by ref *ptr_a and *ptr_b are %d %d \n",*ptr_a, *ptr_b);
}
int main(int argc, char *argv[])
{
    int a, b;
    a = 5;
    b = 10;
    printf ("in main a and b are %d  %d \n", a,b);
    swapping_by_value(a,b);
    printf("after swapping by value a and b are %d  %d\n", a, b);
    swapping_by_reference(&a,&b);
    printf("after swapping by ref a and b are %d  %d \n", a, b);

    return 0;
}
