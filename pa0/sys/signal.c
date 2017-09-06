/* signal.c - signal */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include "lab0.h"


/*------------------------------------------------------------------------
 * signal  --  signal a semaphore, releasing one waiting process
 *------------------------------------------------------------------------
 */
extern unsigned long ctr1000;
SYSCALL signal(int sem)
{
	unsigned long start;
	if(flag==2){
		sysFreq[currpid][16]++;
	}
	STATWORD ps;    
	register struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		return(SYSERR);
	}
	if ((sptr->semcnt++) < 0)
		ready(getfirst(sptr->sqhead), RESCHYES);
	restore(ps);
	unsigned long stop = ctr1000 - stop;
	if(flag==2){
		sysTime[currpid][16] = sysTime[currpid][16] + stop;
	}
	return(OK);
}
