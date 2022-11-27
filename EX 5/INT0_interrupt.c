#include<htc.h>
#include<pic18f452.h>
void chk_isr();
void INT0_isr();
void MSdelay(unsigned int);

void main(){
TRISD=0;
PORTB=0x00;
TRISC=0;
TRISBbits.TRISB0=1;
INTCONbits.GIE=1;
INTCONbits.PEIE=1;
INTCONbits.INT0IF=0;
INTCONbits.INT0IE=1;
INTCON2bits.INTEDG0=1;
while(1){
	int count=7;
	PORTD=0xAA;
	for(int i=0;i<=count;i++)
	{
		PORTC=i;
		MSdelay(500);
	}
}
}
void interrupt my_isr(){
	chk_isr();
}

void MSdelay(unsigned int val)
{
 unsigned int i,j;
 for (i=0; i<val; i++)
     for (j=0; j<165; j++);	/* Delay count for 1ms for 8MHz freq. */
}

void chk_isr(){
	while(INTCONbits.INT0IF==1||PORTBbits.RB0>0){
		INT0_isr();
	INTCONbits.INT0IF=0;
	
}
}

void INT0_isr(){
	
	PORTD=~(PORTD);
	MSdelay(1000);

}

