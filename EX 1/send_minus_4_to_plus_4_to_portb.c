#include<htc.h>
#include<pic18f452.h>
void delay(int);
void main(void)
{
	TRISB=0;
	int i;
	int a[]={0xFC,0xFD,0xFE,0xFF,0x00,0x01,0x02,0x03,0x04};
	int len=sizeof(a)/sizeof(a[0]);
	while(1)
	{
		for(i=0;i<len;i++)
		{
		delay(100);
		PORTB=a[i];
		}
	}
}

void delay(int t)
{
	int i;
	for(i=0;i<t;i++)
	{
	}
}

