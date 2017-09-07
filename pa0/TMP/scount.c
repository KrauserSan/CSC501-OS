/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include "lab0.h"

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
extern unsigned long ctr1000;
SYSCALL scount(int sem)
{
	unsigned long start = ctr1000;
	if(flag==2){
		sysFreq[currpid][10]++;
	}
extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);
	unsigned long stop = ctr1000 - start;
	if(flag==2){
		sysTime[currpid][10] = sysTime[currpid][10] + stop;
	}
	return(semaph[sem].semcnt);
}
