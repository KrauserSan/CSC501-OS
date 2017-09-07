/* sleep10.c - sleep10 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include "lab0.h"

/*------------------------------------------------------------------------
 * sleep10  --  delay the caller for a time specified in tenths of seconds
 *------------------------------------------------------------------------
 */

extern unsigned long ctr1000;
SYSCALL	sleep10(int n)
{
	unsigned long start = ctr1000;
	if(flag==2){
		sysFreq[currpid][19]++;
	}
	STATWORD ps;    
	if (n < 0  || clkruns==0)
	         return(SYSERR);
	disable(ps);
	if (n == 0) {		/* sleep10(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*100);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
	unsigned long stop = ctr1000 - start;
	if(flag == 2){
		sysTime[currpid][19] = sysTime[currpid][19] + stop;
	}
	return(OK);
}
