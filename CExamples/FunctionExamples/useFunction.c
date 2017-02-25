//Example of pass by value and pass by reference
#include <stdio.h>

void pass_by_value(int x)
{
    printf("Begining pass by value x is %d\n", x);
    x += 10;
    printf("After add 10 in pass by value x is %d\n", x);
}

void pass_by_reference(int *x)
{
    printf("Begining pass by reference *x is %d\n", *x);
    (*x) += 10;
    printf("After add 10 in pass by reference *x is %d\n", *x);
}

int main(int argc, char *argv[])
{
    int a = 10;
    printf("Before pass by value a is %d\n", a);
    pass_by_value(a);
    printf("After pass by value a is %d\n", a);
    printf("Before pass by reference a is %d\n", a);
    pass_by_reference(&a);
    printf("After pass by reference a is %d\n", a);
    return 0;
}
