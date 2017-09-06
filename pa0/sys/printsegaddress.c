#include <stdio.h>

extern int etext;
extern int edata;
extern int end;

void printsegaddress(){


	kprintf("Current: etext[0x%08X] = 0x%08X, edata[0x%08X]=0x%08X, ebss[0x%08X]=0x%08X \n",
		&etext-1,*(&etext-1),&edata-1,*(&edata-1),&end-1,*(&end-1));
	kprintf("Preceding: etext[0x%08X] = 0x%08X, edata[0x%08X]=0x%08X, ebss[0x%08X]=0x%08X \n",
		&etext-2,*(&etext-2),&edata-2,*(&edata-2),&end-2,*(&end-2));
	kprintf("After: etext[0x%08X] = 0x%08X, edata[0x%08X]=0x%08X, ebss[0x%08X]=0x%08X \n",
		&etext,*(&etext),&edata,*(&edata),&end,*(&end));
    

}
