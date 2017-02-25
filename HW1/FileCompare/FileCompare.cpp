// FileCompare.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
	FILE *f1, *f2;
	int ch1, ch2;
	int count = 0;
	char oneChar1[1];
	char oneChar2[1];
	char oneword1[100];
	char oneword2[100];
	char line1[256];
	char line2[256];
	char line[256];
	char commend = 'c';
	char fname1[40] = "in.txt";
	char fname2[40] = "out.txt";

	switch (commend)
	{
	case 'C':
	case 'c':printf("Check character...\n");
			 f1 = fopen(fname1, "r");
			 f2 = fopen(fname2, "r");
			 if (f1 == NULL)
			 {
				 printf("Can't open file for reading...\n");
				 exit(1);

			 }
			 else if (f2 == NULL)
			 {
				 printf("Can't open file for reading...\n");
				 exit(1);
			 }
			 else
			 {
				 while (fscanf(f1, "%c", oneChar1) == 1  && fscanf(f2, "%c", oneChar2) == 1)
				 {
					 if (oneChar1[0] != oneChar2[0])
					 { 
						 count++;
					 }
				 }
			     printf("There are %d character are different.\n", count);
				 fclose(f1);
				 fclose(f2);
				 break;
			 }
	case 'W':
	case 'w':printf("Check character...\n");
		f1 = fopen(fname1, "r");
		f2 = fopen(fname2, "r");
		if (f1 == NULL)
		{
			printf("Can't open file for reading...\n");
			exit(1);

		}
		else if (f2 == NULL)
		{
			printf("Can't open file for reading...\n");
			exit(1);
		}
		else
		{
			while (fscanf(f1, "%s", oneword1) == 1 && fscanf(f2, "%s", oneword2) == 1)
			{
				if (strcmp(oneword1, oneword2) != 0)
					count++;

			}
			while (fscanf(f1, "%s", oneword1) == 1)
				count++;
			while (fscanf(f2, "%s", oneword2) ==1 )
				count++;
			printf("There are %d word are different.\n", count);
			fclose(f1);
			fclose(f2);
			break;
		}
	case 'L':
	case 'l':
		printf("Check character...\n");
		f1 = fopen(fname1, "r");
		f2 = fopen(fname2, "r");
		if (f1 == NULL)
		{
			printf("Can't open file for reading...\n");
			exit(1);

		}
		else if (f2 == NULL)
		{
			printf("Can't open file for reading...\n");
			exit(1);
		}
		else
		{
			while (fgets(line1, sizeof(line), f1) && fgets(line2, sizeof(line), f2))
			{
				if (strcmp(line1, line2) != 0)
					count++;

			}
			while (fgets(line1, sizeof(line), f1))
			{
				count++;
			}while (fgets(line2, sizeof(line), f2))
			{
				count++;
			}
			printf("There are %d line are different.\n", count);
			fclose(f1);
			fclose(f2);
			break;
		}
	}
    return 0;
}

