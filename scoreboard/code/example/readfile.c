#include <stdio.h>
#include <stdlib.h>

FILE *fp;
int value();
int select();

int select()
{
	//char ch;
	long seconds;
	char line[80];


	fp = fopen("/home/pi/projects/code/segmentselect.txt","rt");
	
	if(fp==NULL)
		{
		perror("Error while opening");
		exit(EXIT_FAILURE);
		}

	while(fgets(line, 80, fp)  != NULL) 
		{
		sscanf(line,"%ld", &seconds);
		printf ("%ld\n", seconds);
		}


	fclose(fp);
	return 0;
}

int value()
{
	//char ch;
	long seconds;
	char line[80];


	fp = fopen("/home/pi/projects/code/value.txt","rt");
	
	if(fp==NULL)
		{
		perror("Error while opening");
		exit(EXIT_FAILURE);
		}

	while(fgets(line, 80, fp)  != NULL) 
		{
		sscanf(line,"%ld", &seconds);
		printf ("%ld\n", seconds);
		}


	fclose(fp);
	return 0;
}
