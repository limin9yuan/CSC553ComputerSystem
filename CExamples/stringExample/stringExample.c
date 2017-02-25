#include <stdio.h> //printf, puts, gets
#include <string.h> //strcmp, strcat

int main(int argc, char *argv[]) {
    char firstName[20];
    char lastName[20];
    char fullName[40];

    int i;

    printf("Enter your first name\n");
    fgets(firstName, 20, stdin);

    //fgets add a new line char so we need to remove it
    for (i = 0; i < 20; i++) {
        if (firstName[i] == '\n') {
            firstName[i] = '\0';
        }
    }

    //string compare example
    if (strcmp(firstName,"Mary") == 0)
    {
        printf("we have same name\n");
    }
    else
    {
        printf("thats not my name\n");
    }

    //string length example
    printf("your name is %d letters long\n", strlen(firstName));

    printf("Enter you last name\n");
    fgets(lastName, 20, stdin);

    //remove the \n fgets adds
    for (i = 0; i < 20; i++) {
        if (lastName[i] == '\n') {
            lastName[i] = '\0';
        }
    }
    //put a NULL char in what will be the "end" of full name when complete concat done
    fullName[0] = '\0';

    //string concat example firstname is put in front of fullname
    strcat(fullName, firstName); //firstname into fullname
    strcat(fullName, " "); //seperate name by space
    strcat(fullName, lastName); //put last name at end of fullname

    printf("your full name is %s\n", fullName);
    return 0;
}
