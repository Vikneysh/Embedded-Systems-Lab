#include<htc.h>
	#include<pic18f452.h>
	#include<string.h>

void delay(int);
void main(void)
{
	TRISB=0;	
	int i,loPos=0,hiPos=0;
	char *str="HELLO";
	char lo[3];
	char hi[5];
	for(i=0;i<5;i++)
	{
		if(i%2==0)
		{
			hi[hiPos++]=str[i];
		}
		else
		{
			lo[loPos++]=str[i];
		}
	}	
	lo[loPos++]='\0';
	hi[hiPos++]='\0';
	strcat(hi,lo);
	for(i=0;i<5;i++)
	{
		PORTB=(int)hi[i];
		delay(100000);
	}
}
void delay(int t)
{
	int i;
	for(i=0;i<t;i++)
	{
	}
}
