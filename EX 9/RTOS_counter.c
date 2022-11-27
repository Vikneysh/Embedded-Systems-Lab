
unsigned short *const display = (unsigned short *) 0xE010; 
unsigned long *const timer = (unsigned long *) 0xE040;     


unsigned short const bitpat[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
void delay(int);

void show7seg(void)
{
    _trap(15);
    _word(35);
}


void clear7seg(void)
{
    int i;

    for (i = 0; i < 3; i++) display[i] = 0;      
    display[3] = bitpat[0];                      
}

void write7seg(long n)
{
    display[3] = bitpat[n];
}

void main(void)
{
    long counter = 0;

    label:show7seg();
    clear7seg();
    for (;;) {
        long cntr = *timer / 10;
        if (cntr) {

            if (counter <= 5)
            {
                delay(10000);
                write7seg(counter);
                counter++;
                }
            else
                {

                    counter=0;
                   
                    }
        }
    }
}
void delay(int itime)
{
int i=0,j=0;
    for(i=0;i<itime;i++){

           for( j=0;j<165;j++)
           {
           }
           }
}
