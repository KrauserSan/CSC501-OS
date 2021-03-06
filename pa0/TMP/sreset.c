/* sreset.c - sreset */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include "lab0.h"
/*------------------------------------------------------------------------
 *  sreset  --  reset the count and queue of a semaphore
 *------------------------------------------------------------------------
 */
extern unsigned long ctr1000;
SYSCALL sreset(int sem, int count)
{
	unsigned long start = ctr1000;
	if(flag==2){
		sysFreq[currpid][22]++;
	}
	STATWORD ps;    
	struct	sentry	*sptr;
	int	pid;
	int	slist;

	disable(ps);
	if (isbadsem(sem) || count<0 || semaph[sem].sstate==SFREE) {
		restore(ps);
		return(SYSERR);
	}
	sptr = &semaph[sem];
	slist = sptr->sqhead;
	while ((pid=getfirst(slist)) != EMPTY)
		ready(pid,RESCHNO);
	sptr->semcnt = count;
	resched();
	restore(ps);
	unsigned long stop = ctr1000 - start;
	if(flag==2){
		sysTime[currpid][22] = sysTime[currpid][22] + stop;
	}
	return(OK);
}
