#include <stdio.h>

typedef struct telephone_num
{
    char *name; //remember *char means string
    int number;
} TELEPHONE;

int main(int argc, char *argv[]) {
    TELEPHONE class1 = {"Tom", 12345};
    TELEPHONE *ptr_class1, class2;
    ptr_class1 = &class1;

    /* print examples using structure and pointer examples */
    printf(" using pointer  name %s and number %d\n", ptr_class1->name, ptr_class1->number);
    printf(" using structure  name %s and number %d \n", class1.name, class1.number);

    /* copy whole structure */
    class2=class1;
    printf(" copy of  structure  name %s and number %d \n", class2.name, class2.number);

    return 0;
}
