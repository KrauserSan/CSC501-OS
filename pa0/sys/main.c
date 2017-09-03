/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");
	kprintf("\n...............zfunction.........................\n");
	kprintf("zfunction input: 0xaabbccdd\n");
	kprintf("zfunction output: 0x%lX\n",zfunction(0xaabbccdd));
	kprintf("\n............... printsegaddress function.............\n");
	printsegaddress();
	kprintf("\n...............printtos function.....................\n");
	printtos();
	return 0;
}
