/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <math.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");

	kprintf("\nMath.c output\n");
	kprintf("random var = %u\n",(int)expdev(0.1));
	sleep(1);
	kprintf("random var = %d\n",(int)expdev(0.1));
	sleep(1);
	kprintf("random var = %d\n",(int)expdev(0.1));
	sleep(1);
	kprintf("random var = %d\n",(int)expdev(0.1));
	sleep(1);
	kprintf("random var = %d\n",(int)expdev(0.1));
	kprintf("random var = %d\n",(int)expdev(0.1));
	sleep(1);
	kprintf("random var = %d\n",(int)expdev(0.1));
	sleep(1);
	kprintf("random var = %d\n",(int)expdev(0.1));
	kprintf("random var = %d\n",(int)expdev(0.1));
	sleep(1);
	kprintf("random var = %d\n",(int)expdev(0.1));
	sleep(1);
	kprintf("random var = %d\n",(int)expdev(0.1));
	return 0;
}
