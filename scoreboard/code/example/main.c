#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define clock 1			//Clock-Input (Pin 11)for the 74hc595 chip
#define data 15			//Data-Input (Pin 14) for the 74hc595 chip
#define latch 16		//Latch-Input (Pin 12) for the 74hc595 chip

#define A1 0
#define A2 2 
#define A3 3			//3-Outputs to control which segment is selected

//#include "shiftregister.c"

int value();
int segmentselect();

void write1();
void write0();
int writeregister(int);

FILE *fp;

int main()
{
	int wert, selected;	

	wiringPiSetup();
	pinMode(clock,OUTPUT);
	pinMode(data,OUTPUT);
	pinMode(latch,OUTPUT);
	pinMode(A1,OUTPUT);
	pinMode(A2,OUTPUT);
	pinMode(A3,OUTPUT);

	wert = value();
	selected = segmentselect();
	writeregister(wert);
	return 0;
}

int segmentselect()
{
	long var;
	char line[80];

	fp = fopen("/home/pi/projects/code/segmentselect.txt","rt");
	
	if(fp==NULL)
		{
		perror("Error while opening");
		exit(EXIT_FAILURE);
		}

	while(fgets(line, 80, fp)  != NULL) 
		{
		sscanf(line,"%ld", &var);
		//printf ("%ld\n", var);
		}


	fclose(fp);
	return var;
}



int value()
{
	long var;
	char line[80];

	fp = fopen("/home/pi/projects/code/value.txt","rt");
	
	if(fp==NULL)
		{
		perror("Error while opening");
		exit(EXIT_FAILURE);
		}

	while(fgets(line, 80, fp)  != NULL) 
		{
		sscanf(line,"%ld", &var);
		//printf ("%ld\n", var);
		}


	fclose(fp);
	return var;
}


int writeregister(int zahl)
{
    int count, n;
    int byte;

    for(n=0;n<2;n++)					//2 Byte in two serial shiftregister
        {
        printf("\n");
        byte = zahl%10;
        printf("%d", byte);
        printf("\n");
        count = 7;
        do
            {
                if(count==0)
                {
                    write0();
                }
                else if(count==1 && (byte==1 || byte==4))
                {
                    write0();
                }
                else if(count==2 && (byte==5 || byte==6))
                {
                    write0();
                }
                else if(count==3 && byte==2)
                {
                	write0();
                }
                else if(count==4 && (byte==1 || byte==4 || byte==7))
                {
                    write0();
                }
                else if(count==5 && (byte==1 || byte==3 || byte==4 || byte==5 || byte==7))
                {
                    write0();
                }
                else if(count==6 && (byte==1 || byte==2 || byte==3 || byte==7))
                {
                    write0();
                }
                else if(count==7 && (byte==0 || byte==1 || byte==7))
                {
                    write0();
                }

                else
                    write1();
            count--;
            }
            while (count>=0);
        zahl = zahl/10;
        }
digitalWrite(latch,HIGH);
delayMicroseconds(10);
digitalWrite(latch,LOW);
printf("\n");
return 0;
}

void write0()
{
digitalWrite(data,LOW);
digitalWrite(clock,HIGH);
delayMicroseconds(10);
digitalWrite(clock,LOW);
digitalWrite(data,LOW);
}

void write1()
{
digitalWrite(data,HIGH);
digitalWrite(clock,HIGH);
delayMicroseconds(10);
digitalWrite(clock,LOW);
digitalWrite(data,LOW);
}
