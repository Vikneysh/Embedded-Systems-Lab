// Mail Box

#include <ucos_ii.h>
#include<stdio.h>
OS_EVENT *mailbox;
OS_STK switchStack[256];
OS_STK segmentStack[256];

INT8U *const Switch = (INT8U *)0xE001;
INT8U *const sound=(INT8U *)0xE031;
void Siminit(void);
void switchRead(void *);
void soundNow(void *);

void main(void)
{
    Siminit();
    OSInit();
    mailbox = OSMboxCreate(OS_NULL);
    OSTaskCreate(switchRead, OS_NULL, &switchStack[256], 10);
    OSTaskCreate(soundNow, OS_NULL, &segmentStack[256], 11);
    OSStart();
}

void Siminit()
{

    _trap(15);
    _word(31);
}

void switchRead(void *m)
{
    INT8U state = 0;

    for (;;) {
       if (state != *Switch) {
           state = *Switch;
           OSMboxPost(mailbox, &state);
       }
       OSTimeDlyHMSM(0, 0, 1, 0);
    }
}
void soundNow(void *m)
{
    INT8U *msg;
    INT8U err;
    INT8U temp;
    for (;;) {
       msg = (INT8U *) OSMboxPend(mailbox, 0, &err);
       printf(" %d",*msg);
       *sound=0;
    }
}
