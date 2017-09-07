/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include "lab0.h"

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */

extern unsigned long ctr1000;
SYSCALL getpid()
{
	unsigned long start = ctr1000;
	unsigned long stop = ctr1000 - start;
	if(flag==2){
		sysFreq[currpid][2]++;
		sysTime[currpid][2] = sysTime[currpid][2] + stop;
	}
	return(currpid);
}
