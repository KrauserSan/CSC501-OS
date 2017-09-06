/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include "lab0.h"

extern int getutim(unsigned long *);
extern unsigned long ctr1000;

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
	unsigned long start = ctr1000;
    /* long	now; */

	/* FIXME -- no getutim */
	unsigned long stop = ctr1000 - start;
	if(flag==2){
		sysTime[currpid][4] = sysTime[currpid][4] + stop;
		sysFreq[currpid][4]++;
	}
    return OK;
}
