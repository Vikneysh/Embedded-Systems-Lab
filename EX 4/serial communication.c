#include<PIC18F458.h>
#define mybit PORTBbits.RB5

void main()
{
unsigned char z;
unsigned char fname[]="Hello";
unsigned char lname[]="World";
TRISBbits.TRISB5=1;
TXSTA=0X20;
SPBRG=0X15;
TXSTAbits.TXEN=1;
RCSTAbits.SPEN=1;
do
{
if(mybit==0)
{
for(z=0;z<5;z++)
{
while(PIR1bits.TXIF==0);
TXREG=fname[z];
}
}
else
{
for(z=0;z<6;z++)
{
while(PIR1bits.TXIF==0);
TXREG=lname[z];
}
}
}while(1);
}