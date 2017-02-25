#include <stdio.h>

//example of a global declaration
int j, k;
int *ptr;

int main(int argc, char *argv[])
{
    j = 1;
    k = 2;
    ptr = &k;
    printf("\n");
    printf("j has the value %d and is stored at %p\n", j, &j);
    printf("k has the value %d and is stored at %p\n", k, &k);
    printf("ptr has the value %p and is stored at %p\n", ptr, &ptr);
    printf("The value of the integer pointed to by ptr is %d\n", *ptr);

    return 0;
}
