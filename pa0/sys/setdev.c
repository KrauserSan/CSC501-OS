/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include "lab0.h"
/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */

extern unsigned long ctr1000;
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	unsigned long start = ctr1000;
	if(flag==2){
		sysFreq[currpid][13]++;
	}
	short	*nxtdev;

	if (isbadpid(pid))
		return(SYSERR);
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	unsigned long stop = ctr1000 - start;
	if(flag==2){
		sysTime[currpid][13] = sysTime[currpid][13] + stop;
	}
	return(OK);
}
