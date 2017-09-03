#include <stdio.h>

extern long etext;
extern long edata;
extern long end;

void printsegaddress(){


	kprintf("Current: etext[0x%lx] = 0x%lx, edata[0x%lx]=0x%lx, ebss[0x%lx]=0x%lx \n",
		&etext-1,*(&etext-1),&edata-1,*(&edata-1),&end-1,*(&end-1));
	kprintf("Preceding: etext[0x%lx] = 0x%lx, edata[0x%lx]=0x%lx, ebss[0x%lx]=0x%lx \n",
		&etext-2,*(&etext-2),&edata-2,*(&edata-2),&end-2,*(&end-2));
	kprintf("After: etext[0x%lx] = 0x%lx, edata[0x%lx]=0x%lx, ebss[0x%lx]=0x%lx \n",
		&etext,*(&etext),&edata,*(&edata),&end,*(&end));
    

}
