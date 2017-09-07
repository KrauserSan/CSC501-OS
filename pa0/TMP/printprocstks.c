#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

unsigned long *esp;

void printprocstks(int priority){
	
	int id;
	for(id = 0; id < NPROC; id++){
		if(proctab[id].pprio > priority){
			kprintf("Process [%s]\n",proctab[id].pname);
			kprintf("	pid: %d\n",id);
			kprintf("	priority: %d\n",proctab[id].pprio);
			kprintf("	base: 0x%08X\n", proctab[id].pbase);
			kprintf("	limit: 0x%08X\n",proctab[id].plimit);
			kprintf("	len: %d\n",proctab[id].pstklen);
			if(proctab[id].pstate == PRCURR){
				asm("movl %esp, esp");
				kprintf("	pointer: 0x%08X\n",esp);
			}else{
				kprintf("	pointer: 0x%08X\n",proctab[id].pesp);
			}
		}	
	}
} 
