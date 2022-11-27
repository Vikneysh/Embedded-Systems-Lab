//Since the output could not be properly visualized using a loop-based delay, a Timer0 delay is used.
//Port B shows character
//Port C shows count of the character

#include<pic18f452.h>
void T0Delay(void);
void main(void)
{
	TRISBbits.TRISB0=0;
	TRISC=0;
	TRISB=0;
	PORTB=0x00;
	PORTC=0x00;
	int i;
	char *arr="1101110";
	for(i=0;arr[i]!='\0';i++)
	{
		if((int)arr[i]==48)
			PORTBbits.RB0=0;
		else
			PORTBbits.RB0=1;
		int count=1;
		while(arr[i]==arr[i+1])
		{
			i++;
			count++;

		}
		PORTC=count;
		T0Delay();
	}
}
void T0Delay(void){
	T0CON=0x05;  
	TMR0H=0x1B;        
	TMR0L=0x1F;
	T0CONbits.TMR0ON=1;
	while(INTCONbits.TMR0IF==0);
	T0CONbits.TMR0ON=0;
	INTCONbits.TMR0IF=0;
}