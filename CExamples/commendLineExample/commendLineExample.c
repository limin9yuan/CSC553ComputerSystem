#include <stdio.h>
//to run commend_line_ex file_ex.txt
//assume argv[0] = program name
//assume argv[1] = file to open

int main(int argc, char const *argv[]) {
    if (argc != 2)
    {
        printf("problem with %s\n",argv[0]);
    }
    else
    {
        FILE *file = fopen(argv[1], "r");
        if (file == 0) {
            printf("could not open file\n");
        } else {
            int x;
            while ((x = fgetc(file)) != EOF) {
                printf("%c,", x);
            }
        }
        fclose(file);
    }
    return 0;
}
