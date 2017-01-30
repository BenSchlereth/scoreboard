#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

FILE *fp;

int main()
{
	char ch;
	long seconds;
	char line[80];

	//wiringPiSetup();

	fp = fopen("/home/pi/projects/code/example/number.txt","rt");
	
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
