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
	kprintf("yolo:\n");
	kprintf("zfunction input: 0xaabbccdd\n");
	kprintf("zfunction output: 0x%lX\n",zfunction(0xaabbccdd));
	return 0;
}
