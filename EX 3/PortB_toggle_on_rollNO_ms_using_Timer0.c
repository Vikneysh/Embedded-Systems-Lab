#include<pic18f458.h>
#include<htc.h>
void T0Delay(void);
void main(void)
{
	TRISB=0;
	while(1){
		T0Delay();
		PORTB=~(PORTB);
	}
}

void T0Delay(void){
	T0CON=0x0;  
	TMR0H=0x77;        
	TMR0L=0x48;
	T0CONbits.TMR0ON=1;
	while(INTCONbits.TMR0IF==0);
	T0CONbits.TMR0ON=0;
	INTCONbits.TMR0IF=0;
}