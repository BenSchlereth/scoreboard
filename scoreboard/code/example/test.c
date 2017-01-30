
// C-Standardbibliothek
#include <stdio.h>
#include <stdlib.h>


int writeregister(int zahl);
void write1();
void write0();

int main()
{
	int zahl;

	printf("Bitte eine Zahl eingeben:");
	scanf("%d", &zahl);
	printf("\n");
	writeregister(zahl);

printf("\n");
return 0;
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
                    write1();
                }
                else if(count==1 && (byte==1 || byte==4))
                {
                    write1();
                }
                else if(count==2 && (byte==5 || byte==6))
                {
                    write1();
                }
                else if(count==3 && byte==2)
                {
                printf("1");
                }
                else if(count==4 && (byte==1 || byte==4 || byte==7))
                {
                    write1();
                }
                else if(count==5 && (byte==1 || byte==3 || byte==4 || byte==5 || byte==7))
                {
                    write1();
                }
                else if(count==6 && (byte==1 || byte==2 || byte==3 || byte==7))
                {
                    write1();
                }
                else if(count==7 && (byte==0 || byte==1 || byte==7))
                {
                    write1();
                }

                else
                    write0();
            count--;
            }
            while (count>=0);
        zahl = zahl/10;
        }
printf("\n");
return 0;
}

void write0()
{
printf("0");
}

void write1()
{
printf("1");
}
