/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include "lab0.h"

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
extern unsigned long ctr1000;
SYSCALL	sleep(int n)
{
	unsigned long start = ctr1000;
	if(flag==2){
		sysFreq[currpid][18]++;
	}
	STATWORD ps;    
	if (n<0 || clkruns==0)
		return(SYSERR);
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
	unsigned long stop = ctr1000 - start;
	if(flag==2){
		sysTime[currpid][18] = sysTime[currpid][18] + stop;
	}
	return(OK);
}
