#include<htc.h>
#include<pic18f452.h>
void delay(int);
void main(void)
{
	TRISB=0; 
		
while(1)
	{
	 	PORTB=0xAA;
		delay(100);
		PORTB=0x55;
		delay(100);
	}
}
void delay(int t)
{
	int i;
	for(i=0;i<t;i++)
	{
	}
}