#include<pic18f458.h>
#pragma code My_HiPrio_Int=0x0008
void AD_ISR(void);
void DELAY(unsigned int itime)
{
for(int i=0;i<itime;i++)
	for(int j=0;j<165;j++);
}
#pragma interrupt chk_isr
void chk_isr(void)
{
if(PIR1bits.ADIF==1)
AD_ISR();
}
void interrupt My_HiPrio_Int(void)
{
	chk_isr();
}


void main(void)
{
TRISC=0;
TRISD=0;
TRISAbits.TRISA0=1;
ADCON0=0x81;
ADCON1=0xCE;
PIR1bits.ADIF=0;
PIE1bits.ADIE=1;
INTCONbits.GIE=1;Q
INTCONbits.PEIE=1;
while(1)
{
DELAY(1);
ADCON0bits.GO=1;
}
}

void AD_ISR(void)
{
PORTC=ADRESL;
PORTD=ADRESH;
DELAY(250);
PIR1bits.ADIF=0;
}