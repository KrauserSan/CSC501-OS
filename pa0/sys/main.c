/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
//#include "lab0.h"


int prX;
void halt();

prch(c)
char c;
{
	int i;
	sleep(5);
}
/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int main()
{

	kprintf("\n\nHello World, Xinu lives\n\n");

 	resume(prX = create(prch, 2000, 5, "proc X", 1, 'A'));

	kprintf("\n...............zfunction.........................\n");
	kprintf("zfunction input: 0xaabbccdd\n");
	kprintf("zfunction output: 0x%lX\n",zfunction(0xaabbccdd));
	kprintf("\n............... printsegaddress function.............\n");
	printsegaddress();
	kprintf("\n...............printtos function.....................\n");
	printtos();
	kprintf("\n...............printprocstks function................\n");
	printprocstks(2);
	kprintf("\n..................printsyscallsummary function.........\n");
	syscallsummary_start();        
	resume(prX = create(prch,2000,20,"proc B",1,'A'));
	sleep(2);
	getpid();
	getpid();
	getpid();
	syscallsummary_stop();
	printsyscallsummary();	
	return 0;
}
